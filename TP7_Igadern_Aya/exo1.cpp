#include<iostream>
class Joueur{
    public:
    std::string nom;
    int score;
    // Méthode pour afficher le nom du joueur
    void afficher_nom(){
        std::cout<<"Joueur: "<<nom<<" , ";
    }
    //methode pour afficher le score
    void afficher_score(){
        std::cout<<"Score: "<<score<<std::endl;
    }

};
int main(){
    Joueur J1;
    J1.nom="Alice";
    J1.score=100;
    J1.afficher_nom();
    J1.afficher_score();

    Joueur J2;
    J2.nom="Bob";
    J2.score=200;
    J2.afficher_nom();
    J2.afficher_score();

    
}