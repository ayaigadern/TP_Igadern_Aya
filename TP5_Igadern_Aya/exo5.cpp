#include<iostream>
#include<cctype>
#include<map>
void sort_by_length(const std::string& text){
    std::multimap<int,std::string> word_map;
    std::string temp=""; // chaine temporaire pour construire chaque mot
    int count=0; //compteur pour la longueur du mot courant

    for (int i=0;i<text.length();i++){
        if(!isspace(text[i])){ // Si le caractère n'est pas un espace, l'ajouter au mot temporaire
            temp.push_back(text[i]);
            count++;

        }
        else{
            word_map.insert({count,temp});  // Insérer le mot avec sa longueur comme clé
            count=0;
            temp.clear();
        }

    }
    // Gestion du dernier mot du texte s'il n'est pas suivi d'un espace
    if(!temp.empty()){
        word_map.insert({count,temp});
    }
    // Construire la phrase triée par longueur de mots
    std::string result = "";
    auto it = word_map.begin();

    while (it != word_map.end()) {
        auto range = word_map.equal_range(it->first); // Trouve la plage des éléments avec la même clé
        for (auto i = range.first; i != range.second; ++i) {
            result += i->second + " "; // Ajoute chaque valeur associée à la clé
        }
        it = range.second; // Passe à la prochaine clé unique
    }

    // Supprime l'espace final si nécessaire
    if (!result.empty()) {
        result.pop_back();
    }
        std::cout<<"Trie par longueur : "<<result<<std::endl;

}
int main(){
    std::string text;
    std::cout<<"Phrase : ";
    std::getline(std::cin, text);
    sort_by_length(text);

}
