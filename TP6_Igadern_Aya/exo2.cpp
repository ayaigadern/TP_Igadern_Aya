#include<iostream>
#include<vector>

struct Graph{
    int n; // Nombre de sommets du graphe
    int **ptr; // Matrice d'adjacence stockant les connexions entre sommets
    Graph(int size){
        n=size;
        ptr=new int*[n]; // Allocation dynamique d'un tableau de `n` pointeurs


        for(int k=0;k<n;k++){
            ptr[k]=new int[n]; // Allocation de chaque ligne de la matrice
            for(int j=0;j<n;j++){
                ptr[k][j]=0; // Initialisation de toutes les cases à 0
            }
        }
    }
   

    void ajouter(int i,int j){
        if(i>=0 && i<n && j>=0 && j<n){
            ptr[i][j]=1; //Ajout d'une arête dirigée de i vers j
        }

    }
    void DFS_(int s,bool* visited){
        std::cout<<s<<" ";
        visited[s]=true; // Marquer le sommet comme visité
        for(int i=0;i<n;i++){
            if(ptr[s][i]==1 && !visited[i]) // Vérification des voisins non visités
            DFS_(i,visited);
        }        
      

    }
    void DFS(int s){
        bool* visited=new bool[n]();
        std::cout<<"Parcours en profondeur a partir du sommet "<<s<<" :"<<std::endl;
        DFS_(s,visited);
        delete[] visited; // Libération correcte de la mémoire


    }
    
    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }
};

int main(){
    Graph g(4);
    g.ajouter(0,1);
    g.ajouter(1, 3);
    g.ajouter(3, 2);
    g.DFS(0);
    
    return 0;

}