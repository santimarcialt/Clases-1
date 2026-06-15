#include<iostream>
#include<iomanip>
using namespace std;

class Circulo{
    public:
        const double PI;
        double radio;

        Circulo(double r):PI(3.14159),radio(r){}

        double area(){
            return PI*radio*radio;
        }

        double perimetro(){
            return 2*PI*radio;
        }

        void imprimir(){
            cout<<fixed<<setprecision(2);
            cout<<"Radio: "<<radio<<endl;
            cout<<"Area: "<<area()<<endl;
            cout<<"Perimetro: "<<perimetro()<<endl;
        }
};

int main(){
    Circulo c1(7.0);

    c1.imprimir();

    return 0;
}
