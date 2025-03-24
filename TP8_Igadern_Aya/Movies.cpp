#include<iostream>
#include "Movies.h"

bool Movies::add_movie(std::string n,std::string r,int w){
    for( auto& i:obj){
        if(i.get_name()==n){
            return false;
        }
    }
    Movie objet;
    objet.set_name(n);
    objet.set_rating(r);
    objet.set_watched(w);
    obj.push_back(objet);
    return true;
}
bool Movies::increment_watched(std::string nom){
    for(auto& i:obj){
            if(i.get_name()==nom){
                i.incrementWatched();
                return true;
            }
    }
    return false;
    
}
void Movies::display(){
    if (obj.empty()) {
        std::cout << "Desole, aucun film a afficher" << std::endl;
    } 
    else{
        std::cout << "=====================" << std::endl;
        for(auto& i:obj){
            i.display();
        
        
    }
    std::cout << "=====================" << std::endl;
}


}