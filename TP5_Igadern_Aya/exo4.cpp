#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
#include<map>

void top_frequent_word(const std::string& text,int n){
    std::map<std::string ,int> freq; // Map pour stocker la fréquence de chaque mot
    std::string temp=""; // Chaîne temporaire pour construire chaque mot
    for (int i=0;i<text.length();i++){
        // Ignorer les virgules
        if(text[i]==','){
            continue;
        }
        // Si le caractère n'est pas un espace, l'ajouter au mot temporaire en minuscule
        if(!isspace(text[i])){
            temp.push_back(std::tolower(text[i]));
        }
        else{
                freq[temp]++;
                temp="";
        }

    }
     // Gestion du dernier mot du texte s'il n'est pas suivi d'un espace
    if(!temp.empty()){
            freq[temp]++;}
    // Vérifier si n est supérieur au nombre de mots distincts
    if(n>freq.size()){
        std::cout<<"il y a que "<<freq.size()<<" mot dans cette phrase";
        return ;
    }
    // Convertir le map en un vecteur de paires pour le tri
    std::vector<std::pair<std::string, int>> sorted_words(freq.begin(), freq.end());
    // Trier le vecteur par fréquence décroissante
    std::sort(sorted_words.begin(), sorted_words.end(),
    [](const auto& a, const auto& b) { return a.second > b.second; });
    // Afficher les n mots les plus fréquents
    std::cout<<"Top "<<n<<" mots les plus frequents : "<<std::endl;
    for(int i=0;i<n;i++){
        std::cout<<sorted_words[i].first<<" -> "<<sorted_words[i].second<<std::endl;
    }
    
         



}
int main(){
    std::cout<<"Texte : ";
    std::string text;
    std::getline(std::cin,text);
    int n;
    top_frequent_word(text,3);

    return 0;
}
