#include <iostream>
#include <list>
#include <unordered_map>
#include <memory>

// Structure représentant un nœud du cache
struct Node {
    int key;
    std::shared_ptr<int> value;

    Node(int k) : key(k), value(std::make_shared<int>(k)) {}
};

// Structure du cache LRU
struct LRUCache {
    int capacity;
    std::list<int> lru_list;  // Liste pour suivre l'ordre des accès (LRU en arrière, MRU en avant)
    std::unordered_map<int, std::pair<std::shared_ptr<Node>, std::list<int>::iterator>> cache;

    // Constructeur
    LRUCache(int cap) : capacity(cap) {}

    // Fonction pour accéder à une clé
    void access(int key) {
        if (cache.find(key) != cache.end()) {
            // Clé déjà présente, mise à jour de l'ordre d'accès
            lru_list.erase(cache[key].second);
        } else {
            if (cache.size() >= capacity) {
                // Cache plein, on évince l'élément le moins récemment utilisé (LRU)
                int lru_key = lru_list.back();
                std::cout << "Acces a la cle " << key << " -> Eviction de la cle " << lru_key << std::endl;
                cache.erase(lru_key);
                lru_list.pop_back();
            }
        }

        // Ajouter la clé en tête de liste (MRU - Most Recently Used)
        lru_list.push_front(key);
        cache[key] = {std::make_shared<Node>(key), lru_list.begin()};
    }

    // Affichage du cache
    void display() {
        std::cout << "Cache actuel : "<<std::endl;
        for (int key : lru_list) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }
};

// Programme principal
int main() {
    LRUCache cache(4);
    std::cout<<"Acces aux cles : 1 2 3 1 4"<<std::endl;

    cache.access(1);
    cache.access(2);
    cache.access(3);
    cache.access(1);
    cache.access(4);

    cache.display();  

    cache.access(5);  
    cache.display();  

    return 0;
}
