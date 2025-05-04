#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>

int main(){
    std::ifstream data("data.txt");
    std::ofstream report("report.txt");

    if(!data|| !report){
        std::cerr<<"Erreur lors de l ouverture du fichier"<<std::endl;
        return 1;
    }

    report<<std::setw(20)<<std::left<<"Nom"<<std::setw(10)<<"Age"<<std::setw(15)<<"Salaire"<<std::endl;

    std::string line;
    while(std::getline(data,line)){
        std::istringstream getLine(line);
        std::string nom;
        double salaire;
        int age;
        if(getLine>>nom>>age>>salaire){
            report<<std::fixed<<std::setprecision(2)<<std::setw(20)<<std::left<<nom
            <<std::setw(10)<<age
            <<std::setw(15)<<salaire<<std::endl;
        }
    }
    report.close();
    data.close();
    std::cout<<"report genrer dans report.txt"<<std::endl;
    return 0;
    
}