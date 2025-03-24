#ifndef MOVIES_H
#define MOVIES_H
#include "Movie.h"
#include<iostream>
#include<vector>

class Movies{
    std::vector<Movie> obj;
    public:
    bool add_movie(std::string n,std::string r,int w);
    bool increment_watched(std::string nom);
    void display();
};

#endif