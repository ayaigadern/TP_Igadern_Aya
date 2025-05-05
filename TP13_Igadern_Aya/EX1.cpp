#include<iostream>
#include<vector>
#include<algorithm>

class Additionneur{
    private:
        int valeur;
    public:
        Additionneur(int v):valeur(v){};
        void operator()(int x)const{
            std::cout<<(x+valeur)<<" ";
        }
};

int main(){
    std::vector<int> data={1,2,3,4,5};
    std::for_each(data.begin(),data.end(),Additionneur(10));
    std::cout<<std::endl;
    return 0;


}