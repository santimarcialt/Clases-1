#include<iostream>
#include<iomanip>
using namespace std;
class Circulo{
    public:
        double radio; 
        const double PI=3.14159;
        double calcularArea(){
            return PI*radio*radio;
        }
        double calcularPerimetro(){
            return 2*PI*radio;
        }
        void imprimir(){
            cout<<fixed<<setprecision(2);
            cout<<"Radio: "<<radio<<endl;
            cout<<"Area: "<<calcularArea()<<endl;
            cout<<"Perimetro: "<<calcularPerimetro()<<endl;
        }
};
int main(){
    Circulo c1;
    Circulo c2;
    c1.radio=5.0;
    c2.radio=3.0;
    c1.imprimir();
    cout<<endl;
    c2.imprimir();
}
