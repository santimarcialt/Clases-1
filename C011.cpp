#include<iostream>
#include<iomanip>
using namespace std;

class Rectangulo{
    public:
        double base;
        double altura;

        Rectangulo(double b,double h):base(b),altura(h){}

        double calcularArea(){
            return base*altura;
        }

        double calcularPerimetro(){
            return 2*(base+altura);
        }

        void imprimir(){
            cout<<fixed<<setprecision(2);
            cout<<"Base: "<<base<<", Altura: "<<altura<<endl;
            cout<<"Area: "<<calcularArea()<<endl;
            cout<<"Perimetro: "<<calcularPerimetro()<<endl;
        }
};

int main(){
    Rectangulo r1(6.0,4.0);
    Rectangulo r2(10.0,2.5);

    r1.imprimir();
    cout<<endl;
    r2.imprimir();

    return 0;
}
