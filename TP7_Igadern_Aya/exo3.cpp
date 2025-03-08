#include<iostream>
class Joueur{
    private:// Accès privé pour les membres suivants
        std::string nom;
        int score;
    public: // Accès public pour les membres suivants

        //constructeur
        Joueur(std::string nom="None", int score=0): nom(nom),score(score){
            std::cout<<"Constructeur appele"<<std::endl;
        }
        //destructeur
        ~Joueur(){
            std::cout<<"Destructeur appele"<<std::endl;
        }
        //afficher le nom
        void afficher_nom(){
            std::cout<<"Joueur: "<<nom<<" , ";
        }
        //afficher le score
        void afficher_score(){
            std::cout<<"Score: "<<score<<std::endl;;
        }
    

};

int main(){
    Joueur J1{"Alice",100};
    J1.afficher_nom();
    J1.afficher_score();

   


    
}