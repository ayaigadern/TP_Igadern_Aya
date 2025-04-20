#include "KubernetesCluster.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    node->start();
    nodes_.push_back(std::move(node));
}

bool KubernetesCluster::removePod(const std::string& name) {
    for (auto it = pods_.begin(); it != pods_.end(); ++it) {
        if ((*it)->getMetrics().find("Pod: " + name) != std::string::npos) {
            pods_.erase(it);
            return true;
        }
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    std::cout << "-> Déploiement du Pod " << pod->getMetrics() << std::endl;
    
    if (schedulePod(*pod)) {
        pod->deploy();
        std::cout << "Pod " << pod->getMetrics() << "\ndéployé avec succès." << std::endl;
        pods_.push_back(std::move(pod));
    } else {
        std::cout << "Échec du déploiement du pod " << pod->getMetrics() << " : ressources insuffisantes." << std::endl;
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double required_cpu = 0;
    double required_memory = 0;
    
    for (const auto& container : pod.getContainers()) {
        required_cpu += container->getCpu();
        required_memory += container->getMemory();
    }
    
    for (auto& node : nodes_) {
        if (node->allocate(required_cpu, required_memory)) {
            std::cout << "sur le nœud " << node->getMetrics() << std::endl;
            return true;
        }
    }
    
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
                         [&name](const std::unique_ptr<Pod>& pod) {
                             return pod->getMetrics().find("Pod: " + name) != std::string::npos;
                         });
    
    if (it != pods_.end()) {
        return it->get();
    }
    
    return nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::stringstream ss;
    ss << "=== Cluster Metrics ===";
    
    for (const auto& node : nodes_) {
        ss << "\n" << node->getMetrics();
    }
    
    for (const auto& pod : pods_) {
        ss << "\n" << pod->getMetrics();
    }
    
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}