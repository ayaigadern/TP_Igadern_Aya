#include<iostream>
#ifndef EXO
#define EXO 1
#endif
namespace espace{
        int x=42; // Declaration d'une variable entiere x dans le namespace
        void aff(){ // definition d une fonction qui affiche la valeur de x
            std::cout<<"avec namespace: "<<x<<std::endl;
        }
        
    }
int main(int argc,char* argv[]){
    #if EXO==1
    std::cout<<"Exercice 1 "<<std::endl;
    #define PI 3.14159 // definition d'une macro PI
    #ifdef DEBUG
    std::cout<<"DEBUG est definie "<<std::endl;
    #else
    std::cout<<"DEBUG n est pas definie "<<std::endl;
    #endif
    return  0;

    #elif EXO==2
    std::cout<<"Exercice 2 "<<std::endl;
    for(int i=1;i<argc;i++){
        std::cout<<"Argument "<<i<<": "<<argv[i]<<std::endl;
    }
    return 0;
    #elif EXO==3
    std::cout<<"Exercice 3"<<std::endl;
    
    espace::aff(); // Appel de la fonction (aff) du namespace (espace)
    std::cout<<"sans namespace: "<<espace::x<<std::endl;
    return 0;

    #elif EXO==4
    std::cout<<"Exercice 4"<<std::endl;
    int num1;
    float num2;
    std::cout<<"Entrez un entier: ";
    std::cin>>num1;
    std::cout<<"Entrer un nombre decimal: ";
    std::cin>>num2;
    std::cout<<"Valeurs saisies: "<<num1<<" et "<<num2<<std::endl;
    return 0;

    #endif
    return 0;
}