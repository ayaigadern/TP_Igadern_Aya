#ifndef KUBERNETES_CLUSTER_H
#define KUBERNETES_CLUSTER_H

#include "Server.h"
#include "Pod.h"
#include <vector>
#include <memory>
#include <functional>

class KubernetesCluster {
private:
    std::vector<std::shared_ptr<Server>> nodes_;
    std::vector<std::unique_ptr<Pod>> pods_;

public:
    void addNode(std::shared_ptr<Server> node);
    bool removePod(const std::string& name);
    void deployPod(std::unique_ptr<Pod> pod);
    bool schedulePod(Pod& pod);
    Pod* getPod(const std::string& name);
    std::string getMetrics() const;
    
    // Méthode pour filtrer les serveurs selon un prédicat (lambda)
    std::vector<std::reference_wrapper<const Server>> getFilteredServers(
        std::function<bool(const Server&)> predicate) const;
    
    // Pour accéder aux pods depuis forEachContainer
    const std::vector<std::unique_ptr<Pod>>& getPods() const { return pods_; }
    
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
};

#endif 