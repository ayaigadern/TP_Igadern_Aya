#include<iostream>
#include<vector>

template <typename T>

class Conteneur{
    private:
        std::vector<T> stock;
        int capacite;
    
    public:
        Conteneur(int capacite):capacite(capacite){};
        void ajouter(T value){
            if(stock.size()<capacite){
                stock.push_back(value);
           
            }
            else{
                std::cout<<"capacite depasse"<<std::endl;
            }
            
            
        }
        T obtenir(int key){
            return stock[key];

        }


};

int main() {
        Conteneur<int> c1(3); // Capacité de 3
        c1.ajouter(10);
        c1.ajouter(20);
        c1.ajouter(30);
        c1.ajouter(40); // Capacité dépassée
        std::cout << c1.obtenir(0) << " " << c1.obtenir(1) << std::endl; // Affiche 10 20
        Conteneur<std::string> c2(2);
        c2.ajouter("Bonjour");
        c2.ajouter("Monde");
        std::cout << c2.obtenir(0) << " " << c2.obtenir(1) << std::endl; // Affiche Bonjour Monde
        return 0;
}