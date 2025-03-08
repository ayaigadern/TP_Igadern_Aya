#include<iostream>
#include<vector>
#include<iomanip>

class Etudiant{
    public:
    std::string nom;
    std::vector<int> note;
    //afficher la moyenne
    void moyenne(){
        float moyn=0;
        int count=0;
        for(auto i :note){
            moyn+=i;
            count++;
        }
        std::cout << "Moyenne: " << std::fixed << std::setprecision(2) << moyn/count << std::endl;
    }

};
int main(){
    Etudiant etd;
    etd.nom="Karim";
    std::cout<<"Nom: "<<etd.nom<<std::endl;
    etd.note.push_back(15);
    etd.note.push_back(18);
    etd.note.push_back(12);
    std::cout<<"Note: ";
    for(auto i :etd.note){
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
    etd.moyenne();
}