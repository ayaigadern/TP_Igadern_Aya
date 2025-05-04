#include<iostream>
#include<fstream>
#include<iomanip>
int main(){
    double num;
    std::cout<<"Entrer des nombres (une entree non numerique pour arreter) : ";
    std::ofstream Myfile("output.txt");
    if(!Myfile){
        std::cerr<<"Erreur lors de l ouverture du fichier"<<std::endl;
        return 1;
    }
    while(std::cin>>num){
        Myfile<<std::fixed<<std::setprecision(2)<<std::setw(10)<<std::left<<num<<std::endl;
    }
    Myfile.close();
    std::cout<<"Nombres enregistres dans output.txt";

}