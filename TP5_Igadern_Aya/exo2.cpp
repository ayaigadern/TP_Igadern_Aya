#include<iostream>
#include<cctype>
#include<unordered_map>
void word_frequency(const std::string& text){
    // Unordered_map pour stocker la fréquence de chaque mot
    std::unordered_map<std::string,int> freq;
    std::string temp;
    for(char i :text){
        if(i==','){
            continue;
        }
        // Si le caractère n'est pas un espace, l'ajouter au mot temporaire en minuscule
        if(!(std::isspace(i))){
           temp.push_back(std::tolower(i));
        }
        else if(!temp.empty()){
            freq[temp]++; // Incrémenter la fréquence du mot
            temp.clear(); // Réinitialiser le mot temporaire

        }
    }
    // Gestion du dernier mot du texte s'il n'est pas suivi d'un espace
    if(!temp.empty()){
        freq[temp]++;
    }
    for(auto val:freq){
        std::cout<<val.first<<" -> "<<val.second<<std::endl;
    }
}
int main(){
    std::cout<<"Entrez une phrase : ";
    std::string text;
    std::getline(std::cin ,text);
    std::cout<<"Frequence des mots : "<<std::endl;
    word_frequency(text);

    return 0;
}
