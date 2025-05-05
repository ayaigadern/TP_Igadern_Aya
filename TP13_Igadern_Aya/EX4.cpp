#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

class Livre {
private:
    std::string titre;
    int pages;

public:
    Livre(std::string t, int p) : titre(t), pages(p) {}

    // Définition de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const Livre& livre) {
        os << livre.titre << " - " << livre.pages << " pages";
        return os;
    }

    // Accesseurs pour titre et pages
    std::string getTitre() const { return titre; }
    int getPages() const { return pages; }
};

int main() {
    std::vector<Livre> livres = {
        Livre("C++ Moderne", 350),
        Livre("Apprendre Python", 500),
        Livre("Algorithmique", 450)
    };

    std::cout << "A partir des livres :" << std::endl;
    for (const auto& livre : livres) {
        std::cout << livre << std::endl;
    }

    // Tri par titre (ordre alphabétique)
    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.getTitre() < b.getTitre();
    });

    std::cout << "\nTri par titre :" << std::endl;
    for (const auto& livre : livres) {
        std::cout << livre << std::endl;
    }

    // Tri par nombre de pages (ordre décroissant)
    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.getPages() > b.getPages();
    });

    std::cout << "\nTri par nombre de pages decroissant :" << std::endl;
    for (const auto& livre : livres) {
        std::cout << livre << std::endl;
    }

    return 0;
}
