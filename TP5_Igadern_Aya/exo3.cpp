#include<iostream>
#include<cctype>
std::string encode_rle(const std::string& text){
    std::string temp="";
    std::string encode=""; // chaine pour stocker le resultat encode
    int count=1; // compteur pour le nombre de repetitions du caractere courant
    char current=text[0]; //caractere courant
    for(int i=1 ;i<text.size();i++){
        if(text[i]==current){ //si le caractere actuel est le meme que le caractere courant
            count++;
        }
        else{
            encode+=current; //ajouter le caractere courant
            encode+=std::to_string(count); //ajouter le nombre de repetitions
            current=text[i]; //mettre a jour le caractere courant
            count=1; // reinitialiser le compteur
        }
    }
    // ajouter le dernier caractere et son compteur
    encode+=current;
    encode+=std::to_string(count);
    
    
    return encode;

}
int main(){
    std::cout<<"Entree : ";
    std::string text;
    std::getline(std::cin,text);
    std::cout<<"Ecodee : "<<encode_rle(text)<<std::endl;
    
    return 0;
}