#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
class Movie{
    private:
    std::string name;
    std::string rating;
    int watched;
    public:
    void set_name(std::string nom);
    void set_rating(std::string r);
    void set_watched(int w);
    std::string get_name();
    std::string get_rating();
    int get_watched();
    void display();
    void incrementWatched();
};

#endif