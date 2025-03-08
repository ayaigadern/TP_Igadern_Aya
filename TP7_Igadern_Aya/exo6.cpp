#include<iostream>
#include<fstream>

class Fichier{
    public:
    std::fstream* flux;
    // Constructeur de la classe Fichier
    Fichier(const std::string& nom_fichier) {
        flux = new std::fstream(nom_fichier, std::ios::in | std::ios::out | std::ios::trunc); // ouverture en lecture et écriture
        if (!flux->is_open()) { // Vérification de l'ouverture du fichier
            std::cerr << "Erreur d'ouverture du fichier" << std::endl;
        }
    }
    //sauvgarder
    void sauvgarder(const std::string& contenu){
        if(flux->is_open()){
            *flux<<contenu;
            std::cout<<"Sauvgarder des donnees..."<<std::endl;
        }else{
            std::cerr << "Le fichier ne peut pas etre ouvert pour l'ecriture." << std::endl;

        }
    }
    //changer
    void charger(){
        if(flux->is_open()){
            flux->seekg(0); // Positionner le pointeur de lecture au début du fichier
            std::string ligne;
            std::cout<<"Lecture des donnees..."<<std::endl;
            std::cout<<"Contenue du fichier:"<<std::endl;
            while (getline(*flux, ligne)) {  // Lire ligne par ligne
                std::cout << ligne << std::endl;
            }
           
        }
        else {
            std::cerr << "Le fichier ne peut pas etre ouvert pour la lecture." << std::endl;
        }

       

    }
    ~Fichier(){
        if (flux->is_open()) {
            flux->close();  // fermer le fichier
        }
        delete flux;  // libérer la mémoire du pointeur flux
        std::cout << "Memoire du flux liberee" << std::endl;
    }
};
int main(){
    Fichier fichier("text.txt");
    fichier.sauvgarder("Bonjour, ceci est un test.");
    fichier.charger();

    return 0;
}