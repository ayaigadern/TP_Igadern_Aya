#include<iostream>
#include<cctype>
#include<vector>
#include<regex>
bool contains_email(const std::string& text){
    std::vector<std::string> words;
    std::string temp="";
     // Expression régulière pour valider une adresse email
    std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    for(auto var:text){
        if(!isspace(var)){  // Si le caractère n'est pas un espace, l'ajouter au mot temporaire
            temp.push_back(var);
        }
        else if(!temp.empty()){
            words.push_back(temp);
            temp.clear();
        }
    }
    if(!temp.empty()){
        words.push_back(temp);
    }
    for(auto var:words){
        // Si le mot contient le caractère '@'
            if(var.find('@')!=std::string::npos){
                if(std::regex_match(var,pattern)){
                    // Vérifier si le mot correspond au format d'une adresse email
                    std::cout<<"Adresse email detecte : ";
                    std::cout<<var<<std::endl;
                    return true;
                }
            }
    }
    std::cout<<"pas d adresse mail detecte";
    return false;
}
int main(){
    std::string text;
    std::cout<<"Phrase : ";
    std::getline(std::cin, text);
    contains_email(text);
    return 0;
}