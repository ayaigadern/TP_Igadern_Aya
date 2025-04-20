#include "Cloud_Util.h"
#include <iostream>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics();
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    while (!pods.empty()) {
        auto pod = std::move(pods.front());
        pods.erase(pods.begin());
        cluster.deployPod(std::move(pod));
    }
}