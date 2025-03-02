#include<iostream>
#include<memory>

struct MemoryBlock{
    int size;
    MemoryBlock(int s) :size(s){
        std::cout<<"Bloc de memoire alloue de "<<size<<" unites. "<<std::endl;

    }
    ~MemoryBlock(){
        std::cout<<"Liberation de la memoire de "<<size<<" unites."<<std::endl;

    }
};
std::unique_ptr<MemoryBlock> mergeBlocks(std::unique_ptr<MemoryBlock> b1, std::unique_ptr<MemoryBlock> b2) {
    int newSize = b1->size + b2->size;
    std::cout << "Fusion des deux blocs : " << newSize << " unites." << std::endl;
    return std::make_unique<MemoryBlock>(newSize);
}
int main() {
    // Création de deux blocs de mémoire avec unique_ptr
    std::unique_ptr<MemoryBlock> block1 = std::make_unique<MemoryBlock>(100);
    std::unique_ptr<MemoryBlock> block2 = std::make_unique<MemoryBlock>(200);

    // Fusionner les blocs
    std::unique_ptr<MemoryBlock> mergedBlock = mergeBlocks(std::move(block1), std::move(block2));

    // À la fin de main(), les objets seront automatiquement libérés.
    return 0;
}