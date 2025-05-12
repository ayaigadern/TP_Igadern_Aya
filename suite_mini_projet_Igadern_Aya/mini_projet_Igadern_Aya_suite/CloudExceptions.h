#ifndef CLOUDEXCEPTIONS_H
#define CLOUDEXCEPTIONS_H
#include<stdexcept>

class CloudException:public std::runtime_error{
    public:
        CloudException(const std::string& message)
        :std::runtime_error(message){}
};

class AllocationException:public CloudException{
   public:
    AllocationException(const std::string& message)
        :CloudException(message){}
};

class FileException:public CloudException{
    public:
        FileException(const std::string& message)
        :CloudException(message){}

};
#endif