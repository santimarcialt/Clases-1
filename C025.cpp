#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Triangulo{
    private:
        double base;
        double altura;
        double hipotenusa;

    public:
        Triangulo(double b,double h):base(b),altura(h){
            hipotenusa=sqrt(base*base+altura*altura);
        }

        double getBase() const{
            return base;
        }

        double getAltura() const{
            return altura;
        }

        double getHipotenusa() const{
            return hipotenusa;
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"Base: "<<getBase()<<endl;
            cout<<"Altura: "<<getAltura()<<endl;
            cout<<"Hipotenusa: "<<getHipotenusa()<<endl;
        }
};

int main(){
    Triangulo t1(3,4);

    t1.imprimir();

    return 0;
}
