#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Classe de base pour permettre le stockage hétérogène
class PaireBase {
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const = 0;
};

// Classe template générique Paire
template <typename T, typename U>
class Paire : public PaireBase {
protected:
    T premier;
    U second;

public:
    Paire(const T& p, const U& s) : premier(p), second(s) {}
    
    void afficher() const override {
        std::cout << "Paire: ";
        
        // Utilisation de if constexpr pour gérer les booléens différemment
        if constexpr (std::is_same_v<T, bool>) {
            std::cout << (premier ? "vrai" : "faux");
        } else {
            std::cout << premier;
        }
        
        std::cout << " et ";
        
        if constexpr (std::is_same_v<U, bool>) {
            std::cout << (second ? "vrai" : "faux");
        } else {
            std::cout << second;
        }
        
        std::cout << std::endl;
    }
    
    const T& getPremier() const { return premier; }
    const U& getSecond() const { return second; }
};

// Spécialisation partielle pour Paire<T, int>
template <typename T>
class Paire<T, int> : public PaireBase {
protected:
    T premier;
    int second;

public:
    Paire(const T& p, int s) : premier(p), second(s) {}
    
    void afficher() const override {
        std::cout << "Specialisation - Paire avec second parametre entier: ";
        
        // Gestion des booléens pour le premier paramètre
        if constexpr (std::is_same_v<T, bool>) {
            std::cout << (premier ? "vrai" : "faux");
        } else {
            std::cout << premier;
        }
        
        std::cout << " et " << second << std::endl;
    }
    
    const T& getPremier() const { return premier; }
    int getSecond() const { return second; }
};

int main() {
    std::vector<std::unique_ptr<PaireBase>> paires;
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));
    for (const auto& p : paires) {
    p->afficher();
    }
    return 0;
    }