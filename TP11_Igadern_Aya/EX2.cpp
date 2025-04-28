#include <iostream>
#include <stdexcept>
#include <string>

// Exception for negative quantity
class NegativeQuantityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Attempted to add a negative quantity of items.";
    }
};

// Exception for insufficient stock
class InsufficientStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Attempted to remove more items than available in stock.";
    }
};

// Inventory class
class Inventory {
private:
    int stock;

public:
    
    Inventory(int initial_stock) {
        if (initial_stock < 0) {
            throw NegativeQuantityException();
        }
        stock = initial_stock;
    }

    // Method to add items
    void add_items(int quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        stock += quantity;
    }

    // Method to remove items
    void remove_items(int quantity) {
        if (quantity > stock) {
            throw InsufficientStockException();
        }
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        stock -= quantity;
    }

    // Method to get current stock
    int get_stock() const {
        return stock;
    }
};

int main(){
    // Test1: Initialisation etajout d'articles
    Inventory inv(100); //Initial stock of100 items
    std::cout<< "Initial stock: "<< inv.get_stock()<< std::endl;
    try {
    inv.add_items(50);
    std::cout <<"After adding 50 items: " <<inv.get_stock()<< std::endl;
    }
    catch (const NegativeQuantityException&ex){
    std::cerr <<ex.what()<< std::endl;
    }
    catch (...){
    std::cerr <<"Unknown error occurred"<< std::endl;
    }
    // Test2: Tentativederetrait excessif
    try {
    inv.remove_items(160); // Should throwInsufficientStockException
    std::cout <<"After removing 160 items: "<<inv.get_stock()<< std::endl;
    }
    catch (const InsufficientStockException&ex){
    std::cerr <<ex.what()<< std::endl;
    }
    catch (...){
    std::cerr <<"Unknown error occurred"<< std::endl;
    }
    // Test3: Tentatived'ajout d'une quantiténégative
    try {
    inv.add_items(-10); //Should throw NegativeQuantityException
    std::cout <<"After adding -10 items: " <<inv.get_stock()<< std::endl;
    }
    catch (const NegativeQuantityException&ex){
    std::cerr <<ex.what()<< std::endl;
    }
    catch (...){
    std::cerr <<"Unknown error occurred"<< std::endl;
    }
    std::cout<< "Program completed" <<std::endl;
    return 0;
}