#include <iostream>

class SharedPtr {
private:
    int* ptr;
    int* reference;

public:
    // Constructeur
    explicit SharedPtr(int* p = nullptr) : ptr(p), reference(new int(1)) {
        std::cout << "Creation d'un SharedPtr vers " << (ptr ? *ptr : 0) << std::endl;
        std::cout << "Nombre de references : " << *reference << std::endl;
    }

    // Constructeur de copie
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), reference(other.reference) {
        (*reference)++; 
        std::cout << "Creation d'une copie" << std::endl;
        std::cout << "Nombre de references : " << *reference << std::endl;
    }

    // Destructeur
    ~SharedPtr() {
        (*reference)--; 
        std::cout << "Destruction d'un SharedPtr" << std::endl;
        if (*reference == 0) {
            delete ptr;
            delete reference;
            std::cout << "Objet supprime" << std::endl;
        } else {
            std::cout << "Nombre de references : " << *reference << std::endl;
        }
    }
};

int main() {
    SharedPtr ptr1(new int(10)); 

    {
        SharedPtr ptr2 = ptr1; 
    } 

    return 0; 
}
