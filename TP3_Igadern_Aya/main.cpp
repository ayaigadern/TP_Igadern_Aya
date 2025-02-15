#include<iostream>
#include<limits>
#ifndef EXO
#define EXO 1
#endif

// Fonction constexpr pour calculer la factorielle d'un nombre à la compilation
constexpr int fact(int a){
    if(a<=1){
        return 1;
    }
    return a*fact(a-1);
}

// Déclaration d'une variable globale
int value=100;

int main(){
    #if EXO == 1
    // Exercice 1 : Analyse de la mémoire d’un tableau
    std::cout<<"Exercice 1 :"<<std::endl;
    int tab[10]={0,1,2,3,4,5,6,7,8,9}; // Déclaration et initialisation du tableau
    std::cout<<"La taille du tebleau est: "<<sizeof(tab)<<" octets."<<std::endl;
    std::cout<<"la taille d'un element du tableau: "<<sizeof(tab[0])<<" octets."<<std::endl;
    std::cout<<"le nombre d'elements du tableau: "<<sizeof(tab)/sizeof(tab[0])<<std::endl;
    return 0;

    #elif EXO==2
    // Exercice 2 : Estimation pour le service de nettoyage de tapis
    std::cout<<"Exercice 2 :"<<std::endl;
    const int petite=250; 
    const int grande=350;
    float small;
    int large;
    
    // Demande à l'utilisateur le nombre de pièces à nettoyer
    std::cout<<"Number of small rooms: ";
    std::cin>>small;
    std::cout<<"Number of large rooms: ";
    std::cin>>large;
    
    // Calcul du coût total et de la taxe
    std::cout<<"Price per small room: "<<petite<<"dh"<<std::endl;
    std::cout<<"Price per large room: "<<grande<<"dh"<<std::endl;
    int cost=large*grande+petite*small;
    std::cout<<"Cost :"<<cost<<"dh"<<std::endl;
    float tax=(large*grande+petite*small)*6.0f/100.0f;
    std::cout<<"Tax: "<<tax<<"dh"<<std::endl;
    std::cout<<"============================"<<std::endl;
    std::cout<<"Total estimate: "<<cost+tax<<"dh"<<std::endl;
    std::cout<<"This estimate is valid for 30 days"<<std::endl;
    return 0;

    #elif EXO==3
    // Exercice 3 : Calcul de la factorielle à la compilation
    std::cout<<"Exercice 3 :"<<std::endl;
    
    // Vérification de la factorielle avec static_assert
    constexpr int result=fact(5);
    static_assert(result==120,"Error:la factorielle calculee n'est pas correcte");
    std::cout<<"la factorielle de 5 est "<<result<<std::endl;
    return 0;

    #elif EXO==4
    // Exercice 4 : Variables Globales et Locales (Shadowing)
    std::cout<<"Exercice 4 :"<<std::endl;
    int value=50; // Déclaration d'une variable locale avec le même nom
    std::cout<<"Valeur locale : "<<value<<std::endl;
    std::cout<<"Valeur globale : "<<::value<<std::endl; // Utilisation de l'opérateur de portée
    return 0;

    #elif EXO==5
    // Exercice 5 : Utilisation avancée des constantes
    std::cout<<"Exerice 5 :"<<std::endl;
    const double mois=12; 
    constexpr float compile_time=7.0; // Rayon d'un cercle évalué à la compilation
    #define PI 3.14159 
    
    // Calcul et affichage de l'aire du cercle
    float result=PI*compile_time*compile_time;
    std::cout<<"nombre de mois dans une annee: " <<mois<<std::endl;
    std::cout<<"Rayon du cercle: "<<compile_time<<std::endl;
    std::cout<<"Aire du cercle : "<<result<<std::endl;
    return 0;

    #elif EXO==6
    // Exercice 6 : Détection d’overflow lors d’une multiplication
    std::cout << "Exercice 6 :" << std::endl;
    
    // Lambda function pour effectuer une multiplication sécurisée
    auto safeMultiply = [](int x, int y) -> int {
        if (x > 0 && y > 0 && x > std::numeric_limits<int>::max() / y) {
            std::cerr << "Erreur: overflow." << std::endl;
            return -1;
        }
        if (x < 0 && y < 0 && x < std::numeric_limits<int>::min() / y) {
            std::cerr << "Erreur: overflow" << std::endl;
            return -1;
        }
        return x * y;
    };
    
    // Test de la fonction safeMultiply
    int a = 30000000;
    int b = 100;
    int result = safeMultiply(a, b);
    
    if (result == -1) {
        std::cerr << "Multiplication failed due to overflow." << std::endl;
    } else {
        std::cout << "Result of multiplication: " << result << std::endl;
    }
    return 0;
    #endif
    return 0;
}
