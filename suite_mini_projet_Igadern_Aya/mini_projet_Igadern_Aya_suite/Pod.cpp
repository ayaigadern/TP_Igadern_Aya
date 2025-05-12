#include "Pod.h"
#include <sstream>
#include <algorithm>
#include <iomanip>

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels)
    : name_(std::move(name)), labels_(std::move(labels)) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string& id) {
    for (auto it = containers_.begin(); it != containers_.end(); ++it) {
        if ((*it)->getId() == id) {
            containers_.erase(it);
            return true;
        }
    }
    return false;
}

void Pod::deploy() {
    for (auto& container : containers_) {
        container->start();
    }
}

std::string Pod::getMetrics() const {
    std::stringstream ss;
    ss << "[Pod: " << std::setw(10) << std::left << name_ << "]";
    for (const auto& container : containers_) {
        ss << "\n" << container->getMetrics();
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}