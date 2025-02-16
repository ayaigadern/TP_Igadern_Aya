#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
#ifndef EXO
#define EXO 1
#endif
int main(){
    #if EXO==1
    // Exercice 1 : Calculer la somme d'un tableau d'entiers
    std::cout<<"Exercice1"<<std::endl;
    int array[5]={10,20,30,40,50};
    int somme=0;
    std::cout<<"Elements :";
    for(int i=0;i<5;i++){
        std::cout<<array[i]<<" ";
        somme+=array[i]; // Ajoute chaque élément à la somme
    }
    std::cout<<std::endl;
    std::cout<<"Somme : "<<somme<<std::endl;
    return 0;

    #elif EXO==2
     // Exercice 2 : Calculer la somme des éléments de la diagonale d'une matrice
    std::cout<<"Exercice 2 :"<<std::endl;
    int matrice[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int somme=0;
    std::cout<<"Matrice :"<<std::endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<matrice[i][j]<<"  ";
            
        }
        somme+=matrice[i][i];
        std::cout<<std::endl;
    }
    std::cout<<"Somme diagonale : "<<somme<<std::endl;
    return 0;

    #elif EXO==3
    // Exercice 3 : Inverser un tableau avec std::array
    std::cout<<"Exercice 3 :"<<std::endl;
    std::array<int,5> tab={1,2,3,4,5};
    std::array<int,5> inverse={}; // Tableau vide pour l'inversion
    int index=0;

    std::cout<<"Original : ";
    for(auto it=tab.begin();it!=tab.end();++it){
        std::cout<<*it<<" "; // Affiche les éléments inversés

    }
    std::cout<<std::endl;
    std::cout<<"Inverse : ";
    for(auto it=tab.rbegin();it!=tab.rend();++it){
        inverse[index]=*it;
      std::cout<<*it<<" ";
      index++;

    }
    tab=inverse;
    return 0;

    #elif EXO==4
        // Exercice 4 : Doubler les valeurs saisies par l'utilisateur et les afficher
    std::cout<<"Exercice 4 :"<<std::endl;
    std::cout<<"combien de nombres vous voulez entrer? ";
    int num;
    std::cin>>num;
    std::vector<int> numbers(num);
    std::cout<<"entrer les nombres : ";
    for(int i=0;i<num;i++){
        std::cin>>numbers[i];
    }
    std::cout<<"Double : ";
    for(int i=0;i<num;i++){
        std::cout<<numbers[i]*2<<" "; // Affiche les valeurs doublées
    }
    return 0;

    #elif EXO==5
    // Exercice 5 : Ajouter des éléments au début et à la fin d'une liste
    std::cout<<"Exercice 5 :"<<std::endl;
    std::list<int> lst={10,20,30,40,50};
    lst.push_front(0); // Ajoute un élément au début de la liste
    lst.push_back(60);  // Ajoute un élément à la fin de la liste
    std::cout<<"Apres insertion : ";
    for(int val:lst){
        std::cout<<val<<" ";
    }
    return 0;

    #elif EXO==6
        // Exercice 6 : Gérer l'insertion d'éléments dans un set 

    std::cout<<"Exercice 6 :"<<std::endl;
    std::set<int> myset={5,10,15,20};
    std::cout<<"original : ";
    for(auto val:myset){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Apres insertion de 10 : ";
    myset.insert(10);
    for(auto val:myset){
        std::cout<<val<<" ";
    }
    std::cout<<"(pas de doublons)"<<std::endl;
    return 0;

    #elif EXO==7
        // Exercice 7 : Afficher les éléments d'un map avec des clés et des valeurs
    std::cout<<"Exercice 7 :"<<std::endl;
    std::map<std::string,int> mp={{"John",85},{"Alice",90},{"Bob",78}};
    for(auto val:mp){
        std::cout<<val.first<<" : "<<val.second<<std::endl; // Affiche chaque clé (nom) et sa valeur (note)
    }
    
    return 0;

    #elif EXO==8
     // Exercice 8 : Compter la fréquence des mots avec unordered_map
    std::cout<<"Exercice 8 :"<<std::endl;
    std::unordered_map<std::string,int> mp={};
    int num;
    std::cout<<"entrer le nombre des mots : ";
    std::cin>>num;
    std::string mot;
    for(int i=0;i<num;i++){
        std::cin>>mot;
        
            if(mp.find(mot) != mp.end()){
                mp[mot]+=1; // Si le mot existe, on incrémente sa fréquence
            }
            else{
                mp[mot]=1; // Sinon, on initialise sa fréquence à 1
            }
        
    }
    for(auto val:mp){
        std::cout<<val.first<<" : "<<val.second<<std::endl;
    }
    return 0;

    #elif EXO==9
    // Exercice 9 : Trier un vecteur d'entiers
    std::cout<<"Exercice 9 :"<<std::endl;
    std::vector<int> vect{30,10,50,20,40};
    std::cout<<"Original : ";
    for(int val:vect){
        std::cout<<val<<" ";
    }
    std::sort(vect.begin(),vect.end()); // Trie les éléments du vecteur
    std::cout<<std::endl;
    std::cout<<"Triee : ";
    for(int val:vect){
        std::cout<<val<<" ";
    }
    return 0;

    #elif EXO==10
    // Exercice 10 : Trouver la plus longue séquence consécutive dans un set
    std::cout<<"Exercice 10 :"<<std::endl;
    std::set<int> nums={100,4,200,1,3,2};
    int longeur = 0;
    std::vector<int> sequence; // Pour stocker les valeurs de la plus longue séquence

    for (int num : nums) {
        // Vérifie si num est le début d'une séquence
        if (nums.find(num - 1) == nums.end()) {
            int current = num;
            int longeur2 = 1;
            std::vector<int> currentSequence = {current}; // On commence une nouvelle séquence avec 'num'
            
            // Cherche les éléments consécutifs
            while (nums.find(current + 1) != nums.end()) {
                current++;
                longeur2++;
                currentSequence.push_back(current); // Ajoute chaque élément consécutif à la séquence
            }
            
            // Met à jour la longueur de la séquence la plus longue
            if (longeur2 > longeur) {
                longeur = longeur2;
                sequence = currentSequence; // Met à jour la séquence la plus longue
            }
        }
    }
    
    // Affichage des résultats
    std::cout << "Plus longue sequence : " << longeur <<"(";
    for (int val : sequence) {
        std::cout << val << ", ";
    }
    std::cout<<")";
    std::cout << std::endl;
    return 0;

    #elif EXO==11
    std::cout<<"Exercice 11 :"<<std::endl;
    using namespace std;
    // Définition des types pour la liste et la map
    typedef list<pair<int, int>> LRUList; // Stocke les paires (clé, valeur)
    typedef unordered_map<int, LRUList::iterator> CacheMap; // Associe une clé à un itérateur de la liste

    // Initialisation du cache et de la liste
    CacheMap cache;
    LRUList lru;
    int capacity = 2;

    // Fonction pour insérer ou mettre à jour une paire (clé, valeur) dans le cache
    auto put = [&](int key, int value) {
        // Vérifie si la clé existe déjà
        if (cache.find(key) != cache.end()) {
            // Met à jour la valeur et déplace l'élément en tête de liste
            lru.erase(cache[key]); // Supprime l'élément existant
        } else if (cache.size() >= capacity) {
            // Supprime l'élément le moins récemment utilisé (dernier de la liste)
            int lru_key = lru.back().first; // Récupère la clé du dernier élément
            cache.erase(lru_key); // Supprime la clé de la map
            lru.pop_back(); // Supprime l'élément de la liste
        }
     // Ajoute la nouvelle paire (clé, valeur) en tête de liste
     lru.push_front({key, value}); // Insère en tête
     cache[key] = lru.begin(); // Met à jour la map avec l'itérateur
 };

 // Fonction pour récupérer la valeur associée à une clé
 auto get = [&](int key) {
     if (cache.find(key) == cache.end()) {
         return -1; // Clé non trouvée
     }

     // Déplace l'élément en tête de liste car il vient d'être utilisé
     auto it = cache[key]; // Récupère l'itérateur
     int value = it->second; // Récupère la valeur
     lru.erase(it); // Supprime l'élément de la liste
     lru.push_front({key, value}); // Réinsère en tête
     cache[key] = lru.begin(); // Met à jour la map avec le nouvel itérateur

     return value;
 };

 // Fonction pour afficher le contenu du cache
 auto display = [&]() {
     cout << "Etat du cache : ";
     for (const auto& pair : lru) {
         cout << "(" << pair.first << ", " << pair.second << ") ";
     }
     cout << endl;
    };


    put(1, 10);
    put(2, 20);
    display(); 

    cout << "Acces a la cle 1 : " << get(1) << endl;
    display(); 

    put(3, 30); 
    display(); 
    return 0;
    

    #endif
    return 0;
}