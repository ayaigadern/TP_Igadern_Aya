#include <iostream>
#include <vector>
#include <stdexcept>


class StackFullException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Tentative de pousser un élément dans une pile pleine";
    }
};

class StackEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Tentative de retirer un élément d'une pile vide";
    }
};

// Classe Stack avec capacité maximale fixée
class Stack {
private:
    std::vector<int> elements;
    size_t max_capacity;
    
public:

    Stack(size_t capacity) : max_capacity(capacity) {
        elements.reserve(capacity);
    }
    
    // Méthode pour ajouter un élément à la pile
    void push(int value) {
    
        if (elements.size() >= max_capacity) {
            throw StackFullException();
        }
        elements.push_back(value);
        std::cout << "Élément " << value << " ajouté à la pile." << std::endl;
    }
    
    // Méthode pour retirer un élément de la pile
    int pop() {
    
        if (elements.empty()) {
            throw StackEmptyException();
        }
        int value = elements.back();
        elements.pop_back();
        std::cout << "Élément " << value << " retiré de la pile." << std::endl;
        return value;
    }
    
    // Méthode pour vérifier si la pile est vide
    bool isEmpty() const {
        return elements.empty();
    }
    
    // Méthode pour vérifier si la pile est pleine
    bool isFull() const {
        return elements.size() >= max_capacity;
    }
    
    // Méthode pour afficher la taille actuelle de la pile
    size_t size() const {
        return elements.size();
    }
};

// Fonctions qui utilisent la pile et démontrent le déroulement de pile (stack unwinding)
void func_c(Stack& stack) {
    std::cout << "Entrée dans func_c" << std::endl;
    
    // Provoquer une exception
    if (stack.isFull()) {
        std::cout << "Tentative d'ajouter un élément à une pile pleine dans func_c" << std::endl;
        stack.push(42);  
    } else {
        std::cout << "Tentative de retirer un élément d'une pile vide dans func_c" << std::endl;
        stack.pop();     
    }
    
    std::cout << "Cette ligne ne sera jamais exécutée si une exception est levée dans func_c" << std::endl;
}

void func_b(Stack& stack) {
    std::cout << "Entrée dans func_b" << std::endl;
    func_c(stack);
    std::cout << "Cette ligne ne sera jamais exécutée si une exception est levée dans func_c" << std::endl;
}

void func_a(Stack& stack) {
    std::cout << "Entrée dans func_a" << std::endl;
    func_b(stack);
    std::cout << "Cette ligne ne sera jamais exécutée si une exception est levée dans func_b ou func_c" << std::endl;
}

int main() {
    // Test 1: Démontrer StackFullException via func_a
    try {
    Stack stack(2); // Stack with capacity of 2
    stack.push(1);
    stack.push(2);
    std::cout << "Stack size: " << stack.size() << std::endl;
    func_a(stack); // Will throw StackFullException
    }
    catch (const StackFullException& ex) {
    std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
    std::cerr << "Unknown error occurred" << std::endl;
    }
    // Test 2: Démontrer StackEmptyException avec pop
    try {
    Stack stack(2); // Nouvelle pile vide
    std::cout << "Stack size: " << stack.size() << std::endl;
    stack.pop(); // Will throw StackEmptyException
    }
    catch (const StackEmptyException& ex) {
    std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
    std::cerr << "Unknown error occurred" << std::endl;
    }
    std::cout << "Program completed" << std::endl;
    return 0;
    }