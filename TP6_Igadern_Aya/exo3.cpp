#include<iostream>
struct Node{
    int key; // Clé du nœud
    Node* left;  // Pointeur vers le sous-arbre gauche
    Node* right; // Pointeur vers le sous-arbre droit

    Node(int value){
        key=value;
        left=right=nullptr; // Initialisation des fils à null
    }

};

struct BST{
    Node* root;  // Pointeur vers la racine de l'arbre

    BST(){
        root=nullptr; // L'arbre est initialement vide
    }

    Node* insert(int key,Node* node){
        if(!node){
            return new Node(key); // Crée un nouveau nœud si on atteint une position vide
        }
        if(key<node->key){
            node->left=insert(key,node->left); // Insère à gauche si la clé est plus petite
        }
        else if(key>node->key){
            node->right=insert(key,node->right); // Insère à droite si la clé est plus grande
        }
        return node;
    }

    void insert(int key){
        root=insert(key,root);
    }

    bool search(Node* node,int key){
        if(!node){return false;} // Si on atteint un nœud vide, la clé n'est pas trouvée
        if(node->key==key){
            return true; // Si la clé correspond, on retourne vrai
        }
        else if(key<node->key){
            search(node->left,key); // Recherche dans le sous-arbre gauche
        }
        else if(key>node->key){
            search(node->right,key); // Recherche dans le sous-arbre droit
        }
    }

    bool search(int key){
        return search(root,key);
    }
    Node* minvalue(Node* node){
        while(node->left){ // On descend à gauche jusqu'à atteindre le nœud le plus bas
            node=node->left;
        }
        return node;
    }

    Node* remove(Node* node,int key){
        if(!node){return nullptr;}
        else if(key<node->key){
            node->left=remove(node->left,key); // Descente dans le sous-arbre gauche
        }
        else if(key>node->key){
            node->right=remove(node->right,key);  // Descente dans le sous-arbre droit
        }
        else{
            if(!node->left){ // pas d'enfant gauche
                Node* temp=node->right;
                delete node;
                return temp;
            }
            else if(!node->right){ //  pas d'enfant droit
                Node* temp=node->left;
                delete node;
                return temp;
            }
            Node*temp=minvalue(node->right); //  deux enfants, on cherche le successeur
            node->key=temp->key; // Remplace la clé du nœud par la plus petite valeur à droite
            node->right=remove(node->right,temp->key); // Supprime l'ancien nœud successeur

        }
        return node;

    }

    void remove(int key){
         root=remove(root,key);
    }



    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node; // Libération de la mémoire
        }
    }

    void inorder(Node* root){
        if(root){
            inorder(root->left);
            std::cout<<root->key<<" ";
            inorder(root->right);
        }
    }
    ~BST() { clear(root); }
};
int main() {
    BST bst;
    
    std::cout << "Insertion des elements : 5 3 7 2 4 6 8" << std::endl;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "Parcours infixe : " << std::endl;
    bst.inorder(bst.root);
    std::cout<<std::endl;

    std::cout << "Recherche de 4 : ";
    if (bst.search(4)) {
        std::cout << "Trouve" << std::endl;
    } else {
        std::cout << "Non trouve" << std::endl;
    }

    std::cout << "Suppression de 4" << std::endl;
    bst.remove(4);

    std::cout << "Parcours infixe apres suppression : " << std::endl;
    bst.inorder(bst.root);

    return 0;
}