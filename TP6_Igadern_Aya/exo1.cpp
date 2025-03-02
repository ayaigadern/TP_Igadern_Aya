#include<iostream>
int main(){
    int **ptr=new int*[3];   // Allocation dynamique d'un tableau de 3 pointeurs vers des entiers
    for(int i=0;i<3;i++){
        ptr[i]=new int[3]; // Allocation dynamique d'un tableau de 3 entiers pour chaque ligne
    }
    ptr[0][0]=1;
    ptr[0][1]=2;
    ptr[0][2]=3;

    ptr[1][0]=4;
    ptr[1][1]=5;
    ptr[1][2]=6;

    ptr[2][0]=7;
    ptr[2][1]=8;
    ptr[2][2]=9;

    std::cout<<"Matrice initiale :"<<std::endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<ptr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"Matrice transposee :"<<std::endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<ptr[j][i]<<" ";
        }
        std::cout<<std::endl;
    }

    for(int i=0; i<3; i++){
        delete[] ptr[i];  // Suppression des lignes
    }
    delete[] ptr;  // Suppression du tableau de pointeurs

    return 0;
}