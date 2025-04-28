#include<iostream>
#include<string>
#include<typeinfo>

template <typename T>
T maximum(T x, T y) {
    return (x > y) ? x : y;
}

template <>
std::string maximum<std::string>(std::string x, std::string y) {
    return (x.compare(y) > 0) ? x : y;
}


int main(){
    std::cout << maximum(5, 10) << std::endl; // Affiche 10
    std::cout << maximum(3.14, 2.71) << std::endl; // Affiche 3.14
    std::cout << maximum(std::string("chat"), std::string("chien")) << std::endl; // Affiche chien
    return 0;
}