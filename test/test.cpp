#include <iostream>
 #include <typeinfo> // Ajout de l'en-tête pour typeid

 using namespace std;

 int main(){
 int f = 10;
 double b = 1.0;

 decltype(1 + f) z1 = 0;
 decltype(1/f + b) z2 = 0;

 cout << z1 << " " << sizeof(z1)<< endl;
 cout << z2 << " " << typeid(z2).name() << endl;

 return 0;
 }
