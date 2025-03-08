#include<iostream>
class Joueur{
    private: // Accès privé pour les membres suivants
    std::string nom;
    int score;
    public: // Accès public pour les méthodes suivantes
     // Méthode pour définir le nom du joueur
    void set_nom(std::string n){
        nom=n;
    }
    
    // Méthode pour définir le score du joueur
    void set_score(int s){
        score=s;
    }
   //afficher le nom
    void afficher_nom(){
        std::cout<<"Joueur: "<<nom<<std::endl;
    }
    //afficher le score
    void afficher_score(){
        std::cout<<"Score: "<<score<<std::endl;
    }
    ~Joueur() {
        std::cout << "Objet dynamique supprime." << std::endl;
    }

};

int main(){
    Joueur* J1=new Joueur;
    J1->set_nom("Alice");
    J1->set_score(100);
    J1->afficher_nom();
    J1->afficher_score();
    delete J1;
    return 0;
}