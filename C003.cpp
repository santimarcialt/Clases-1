#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Triangulo{
    public:
        double lado1;
        double lado2;
        double lado3;

        double calcularPerimetro(){
            return lado1+lado2+lado3;
        }

        double calcularArea(){
            double s=calcularPerimetro()/2;
            return sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
        }

        bool esEquilatero(){
            return lado1==lado2 && lado2==lado3;
        }

        bool esRectangulo(){
            double mayor=lado1;
            double a=lado2;
            double b=lado3;

            if(lado2>mayor){
                mayor=lado2;
                a=lado1;
                b=lado3;
            }

            if(lado3>mayor){
                mayor=lado3;
                a=lado1;
                b=lado2;
            }

            return (a*a)+(b*b)==(mayor*mayor);
        }

        void imprimir(){
            cout<<fixed<<setprecision(2);
            cout<<"Lados: "<<lado1<<", "<<lado2<<", "<<lado3<<endl<<endl;
            cout<<"Perimetro: "<<calcularPerimetro()<<endl<<endl;
            cout<<"Area: "<<calcularArea()<<endl<<endl;

            if(esEquilatero()){
                cout<<"Equilatero: SI"<<endl;
            }else{
                cout<<"Equilatero: NO"<<endl;
            }

            if(esRectangulo()){
                cout<<"Rectangulo: SI"<<endl;
            }else{
                cout<<"Rectangulo: NO"<<endl;
            }
        }
};

int main(){
    Triangulo t1;

    t1.lado1=3.0;
    t1.lado2=4.0;
    t1.lado3=5.0;

    t1.imprimir();

    return 0;
}
