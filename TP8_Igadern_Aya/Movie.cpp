#include "Movie.h"
#include<iostream>

void Movie::set_name(std::string nom){
    name=nom;
}
void Movie::set_rating(std::string r){
    rating=r;
}
void Movie::set_watched(int w){
    watched=w;
}
std::string Movie::get_name(){
    return name;
}
std::string Movie::get_rating(){
   return rating;
}
int Movie::get_watched(){
    return watched;
}
void Movie::display(){
    std::cout<<name<<", "<<rating<<", "<<watched<<std::endl;
    
}
void Movie::incrementWatched(){
    watched++;
}