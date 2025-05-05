#include <iostream>
#include <vector>
#include <functional> 

// Fonction qui filtre selon un prédicat
void filtrer(const std::vector<int>& vec, std::function<bool(int)> predicat) {
    for (int x : vec) {
        if (predicat(x)) {
            std::cout << x << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> valeurs = {10, 15, 20, 25, 30, 50, 75};

    int seuil = 20;
    filtrer(valeurs, [seuil](int x) { return x > seuil; });

    filtrer(valeurs, [](int x) { return x % 2 == 0; });

    return 0;
}
