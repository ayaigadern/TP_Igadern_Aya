#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Resource.h"
#include "Container.h"
#include "Pod.h"
#include "Server.h"
#include "KubernetesCluster.h"
#include "Cloud_Util.h"
#include "CloudExceptions.h"
#include "MetricLogger.hpp"
 int main(){
 std::cout <<"=== Test AllocationException direct ===\n";
 try {
    Server failNode("fail-node",1.0, 1024.0);
    failNode.allocate(4.0,4096.0); //Trop gros
 } catch (const AllocationException& e) {
    std::cout << "Exception capturée : " << e.what() << std::endl;
 }
 std::cout <<"\n=== Test FileException ===\n";
 KubernetesCluster cluster;
 auto nodeX= std::make_shared<Server>("nodeX",12.0, 12048.0);
 nodeX->start();// activer lenoeud
 cluster.addNode(nodeX);// cluster nonvide
 /* Gérer l'erreur d'ouverturedu fichier */
 saveClusterMetrics(cluster,"cluster1_metrics.txt");
 std::cout <<"\n=== Test Lambda : serveurs inactifs ===\n"; KubernetesCluster cluster1;
 auto inactiveServer = std::make_shared<Server>("node3",2.0,4096.0); // Ne sera pas activé
 // Ajouter sans activer
 cluster1.addNode(inactiveServer);
 inactiveServer->stop(); // S'assurer qu'il est inactif
 
 /* Filtrer et afficher les serveurs inactifs à l'aide de la fonction getFilteredServers */
 auto inactifs = cluster1.getFilteredServers([](const Server& s) {
    return !s.isActive();
 });
 
 // Afficher les serveurs inactifs
 for (const auto& server : inactifs) {
    std::cout << server.get().getMetrics() << std::endl;
 }
 std::cout <<"\n=== Déploiement sur un serveur inactif ===\n";
 auto c=std::make_unique<Container>("inactive-c1","busybox",1.0,1024.0);
 auto pod=std::make_unique<Pod>("test-pod");
 pod->addContainer(std::move(c));
 /* Gérer l'erreur icidu deploiement*/
 cluster1.deployPod(std::move(pod));
 std::cout <<"\n=== Pods triés par nombre de conteneurs ===\n";
 // Créationdesconteneurs
 auto c1=std::make_unique<Container>("c1","nginx",2.0,1024.0);
 auto c2=std::make_unique<Container>("c2","redis",4,2048.0);
 auto c3=std::make_unique<Container>("c3","mysql",2,1024.0);
 auto c4=std::make_unique<Container>("c4","myapp",10,12024.0);
 // Créationdespods
 auto pod1= std::make_unique<Pod>("web-pod");
 pod1->addContainer(std::move(c1));
 pod1->addContainer(std::move(c2));
 auto pod2 = std::make_unique<Pod>("db-pod");
 pod2->addContainer(std::move(c3)); // Déploiement sans planification réelle, on injecte les pods manuellement
 std::vector<std::unique_ptr<Pod>> pods;
 pods.push_back(std::move(pod1));
 pods.push_back(std::move(pod2));
 /* Gérer le déploiement */
 deployPods(cluster, pods);
 
 std::cout << "\n=== Tri des pods ===\n";
 /* Tri des pods */
 std::vector<const Pod*> podRefs;
 
 // Récupérer des références aux pods
 for (const auto& pod : cluster.getPods()) {
    podRefs.push_back(pod.get());
 }
 
 // Trier les pods par nombre de conteneurs
 std::sort(podRefs.begin(), podRefs.end(), [](const Pod* a, const Pod* b) {
    return a->getContainers().size() > b->getContainers().size();
 });
 
 // Afficher les pods triés
 for (const auto* pod : podRefs) {
    std::cout << pod->getMetrics() << std::endl;
 } std::cout << "\n=== Tous les conteneurs du cluster 1 ===\n";
 // Utilisation de la fonction forEachContainer pour afficher tous les conteneurs
 forEachContainer(cluster, [](const Container& container) {
    std::cout << container.getMetrics() << std::endl;
 });
 
 // Utilisation de MetricLogger
 std::cout << "\n=== Test MetricLogger ===\n";
 MetricLogger<KubernetesCluster>::logToStream(cluster, std::cout, "Cluster 1");
 
 return 0;
}