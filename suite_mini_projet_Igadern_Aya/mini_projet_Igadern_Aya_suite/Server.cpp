#include "Server.h"
#include <sstream>
#include "CloudExceptions.h"
#include <iomanip>

Server::Server(std::string id, double cpu, double memory)
    : Resource(std::move(id), cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

bool Server::allocate(double cpu, double memory) {
    if (!active_) {
        throw AllocationException("Allocation Error: Serveur " + id_ + " est inactif");
    }
    
    if (cpu > available_cpu_ || memory > available_memory_) {
        throw AllocationException("Allocation Error: Server " + id_ + " n'a pas assez de ressources disponibles");
    }
    
    available_cpu_ -= cpu;
    available_memory_ -= memory;
    return true;
}

void Server::start() {
    active_ = true;
}

void Server::stop() {
    active_ = false;
}

std::string Server::getMetrics() const {
    std::stringstream ss;
    ss << "[Server: " << id_ << "| Total: " << std::setw(2) << std::left << cpu_ << " CPU, " 
       << std::setw(6) << std::left << memory_ << " MB | Free: " 
       << std::setw(2) << std::left << available_cpu_ << " CPU, " 
       << std::setw(6) << std::left << available_memory_ << " MB]";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
}