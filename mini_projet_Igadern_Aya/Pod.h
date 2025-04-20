#ifndef POD_H
#define POD_H

#include "Container.h"
#include <vector>
#include <memory>
#include <unordered_map>

class Pod {
private:
    std::string name_;
    std::vector<std::unique_ptr<Container>> containers_;
    std::unordered_map<std::string, std::string> labels_;

public:
    Pod(std::string name, std::unordered_map<std::string, std::string> labels = {});
    
    void addContainer(std::unique_ptr<Container> container);
    bool removeContainer(const std::string& id);
    void deploy();
    std::string getMetrics() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Pod& p);
    
    const std::vector<std::unique_ptr<Container>>& getContainers() const;
};

#endif