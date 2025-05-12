#include "Cloud_Util.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <iomanip>
#include "CloudExceptions.h"

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics();
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    while (!pods.empty()) {
        try {
            auto pod = std::move(pods.front());
            pods.erase(pods.begin());
            cluster.deployPod(std::move(pod));
        }
        catch (AllocationException& e) {
            std::cout << "Exception lors du déploiement: " << e.what() << std::endl;
            // Continue avec les autres pods même en cas d'échec
        }
    }
    
    // S'assurer que le vecteur est vide (pour libérer tous les pointeurs)
    pods.clear();
}

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename){
    try {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw FileException("Erreur lors de l'ouverture du fichier " + filename);
        }
        
        file << cluster.getMetrics();
        file.close();
        std::cout << "Métriques sauvegardées avec succès." << std::endl;
    }
    catch (FileException& e) {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
}

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    // Pour chaque pod dans le cluster
    for (const auto& pod : cluster.getPods()) {
        // Pour chaque conteneur dans le pod
        for (const auto& container : pod->getContainers()) {
            // Appliquer la fonction sur le conteneur
            func(*container);
        }
    }
}