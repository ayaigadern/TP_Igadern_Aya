#include<iostream>
#include<vector>
class Objet{
    public:
    std::string nom;
    int quantite;


    // Constructeur de la classe Objet avec des valeurs par défaut pour les attributs
    Objet(std::string nom="None",int quantite=0):nom(nom),quantite(quantite){}
};
class Inventaire{
    public:
    std::vector<Objet*> objects; // Vecteur de pointeurs vers des objets Objet
    //ajouter un objet
    void ajouter(std::string n,int q){
        Objet* obj=new Objet;
        obj ->nom=n;
        obj->quantite=q;
        objects.push_back(obj);
        std::cout<<"Ajout de "<<n<<" (x"<<q<<")"<<std::endl;
    }
    //retire un objet
    void retirer(std::string n){
        for(auto x=objects.begin();x!=objects.end();++x){
            if((*x)->nom==n){
                std::cout<<"Suppression de "<<n<<std::endl;
                delete *x;
                objects.erase(x);
                return;  
            }
        }
    }
    
    ~Inventaire(){
        std::cout<<"Inventaire :"<<std::endl;
        for(auto i:objects){
            std::cout<<"- "<<i->nom<<" (x"<<i->quantite<<")"<<std::endl;
            delete i;
        }
        std::cout<<"Memoire de l'inventaire liberee";
    }

};
int main(){
    Inventaire elements;
    elements.ajouter("Pomme",3);
    elements.ajouter("Epee",1);
    return 0;

    
}