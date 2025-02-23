#include<iostream>
#include<cctype>
#include <algorithm>
bool is_palindrome(const std::string& phrase){
    std::string phrasecopy; //chaine pour stocker la version nettoyee de la phrase
    for(char ch :phrase){
        if(!std::isspace(ch)){ //ignorer les espaces et ajouter les caracteres en minuscules a phrasecopy
            phrasecopy.push_back(std::tolower(ch));
        }
    }
     //creer une copie inversee de la chaine nettoyee
     std::string reversed = phrasecopy;
     std::reverse(reversed.begin(), reversed.end());
    // comparer la chaine nettoyee avec sa version inversee
     return phrasecopy == reversed;
}
int main(){
    std::cout<<"Entrez un mot : ";
    std::string phrase;
    std::getline(std::cin,phrase);
    if(is_palindrome(phrase)==1){
            std::cout<<phrase<<" est un palindrome";
    }
    else{
        std::cout<<phrase<<" n'est pas un palindrome";
    }
    
    return 0;
}