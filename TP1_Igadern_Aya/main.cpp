#include<iostream>
#ifndef EXO
#define EXO 1
#endif

int main() {
    #if EXO == 1
    std::cout << "Exercice 1 " << std::endl;
    std::cout<<"Hello, World!\nBienvenue en C++!"<<std::endl;//Affiche un message
    return 0;

    #elif EXO == 2
    std::cout << "Exercice 2 " << std::endl;
    double num;
    std::cout<<"Entrez un nombre: ";
    std::cin>>num; //Lecture d'un nombre entré par l'utilisateur
    std::cout<<"Vous avez entre: "<<num<<std::endl;
    return 0;

    #elif EXO==3
    std::cout<<"Exercice3 "<<std::endl;
    double num1;
    double num2;
    std::cout<<"Entrez deux nombres: ";
    std::cin>>num1;
    std::cin>>num2;
    std::cout<<"Somme: "<<num1+num2<<std::endl;//Affiche la somme
    std::cout<<"Difference: "<<num1-num2<<std::endl; // Affiche la difference
    std::cout<<"Produit: "<<num1*num2<<std::endl; //Affiche le produit
    if(num2==0){
        std::cout<<"On ne peut pas diviser par 0"<<std::endl; // verifie si la division est possible
    }
    else{
        std::cout<<"Quotient: "<<num1/num2<<std::endl; // Affiche le quotient si num2!=0
    }
    return 0;

    #elif EXO==4
    std::cout<<"Exercice4 "<<std::endl;
    std::cout<<"Entrez un nombre:";
    int nombre;
    std::cin>>nombre;
    std::cout<<"Vous avez entre: "<<nombre<<std::endl;
    return 0;

    #else
    std::cout << "exercice 5 " << std::endl;
    double valeur;
    std::cout<<"Entrez une temeprature en Celsius: ";
    std::cin>>valeur;
    double result;
    result=(9*valeur)/5+32; // Conversion en Fahrenheit
    std::cout<<"Temperature en Fahrenheit: "<<result<<std::endl;
    return 0;
    
    #endif
    return 0;
}
