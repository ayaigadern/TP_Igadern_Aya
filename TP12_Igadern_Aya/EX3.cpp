#include<iostream>
#include<fstream>

int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if(!input || !output){
        std::cerr<<"Erreur lors de l ouverture des fichiers"<<std::endl;
        return 1;
    }

    std::string mot;
    std::cout<<"Entrer un mot cle : ";
    std::cin>>mot;
    std::string line;
    while(std::getline(input,line)){
        if(line.find(mot) !=std::string::npos){
            output<<std::left<<line<<std::endl;
        }
    }
    std::cout<<"lignes contenant "<<mot<<" copiees dans output.txt"<<std::endl;
    return 0;

}
