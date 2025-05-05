#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
    std::vector<int> vec = {10, 12, 15, 17};

    // Transformation : ajouter 5 à chaque élément
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) {
        return x + 5;
    });

    // Affichage du vecteur transformé
    for (int x : vec) {
        std::cout << x << " ";
    }

    std::cout << std::endl;
    return 0;
}
