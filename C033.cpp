#include<iostream>
#include<iomanip>
using namespace std;

class Figura{
    protected:
        double area;

    public:
        Figura(double area){
            this->area=area;
        }

        virtual void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"Figura: "<<area<<endl;
        }
};

class Rectangulo:public Figura{
    protected:
        double base;
        double altura;

    public:
        Rectangulo(double base,double altura):Figura(base*altura){
            this->base=base;
            this->altura=altura;
        }

        void imprimir() const override{
            Figura::imprimir();
            cout<<"Base: "<<base<<" Altura: "<<altura<<endl;
        }
};

class Cuadrado:public Rectangulo{
    private:
        double lado;

    public:
        Cuadrado(double lado):Rectangulo(lado,lado){
            this->lado=lado;
        }

        void imprimir() const override{
            Rectangulo::imprimir();
            cout<<"Lado: "<<lado<<endl;
        }
};

int main(){
    Cuadrado c1(5.0);

    c1.imprimir();

    return 0;
}
