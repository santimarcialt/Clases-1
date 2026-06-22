#include<iostream>
#include<iomanip>
using namespace std;

class Forma{
    public:
        virtual double area() const=0;
        virtual void imprimir() const{
            cout<<"Area: "<<area()<<endl;
        }
        virtual ~Forma(){}
};

class Cuadrado:public Forma{
    private:
        double lado;
    public:
        Cuadrado(double l){
            lado=l;
        }
        double area() const override{
            return lado*lado;
        }
};

class Rombo:public Forma{
    private:
        double d1,d2;
    public:
        Rombo(double diagonal1,double diagonal2){
            d1=diagonal1;
            d2=diagonal2;
        }
        double area() const override{
            return (d1*d2)/2;
        }
};

class Pentagono:public Forma{
    private:
        double perimetro,apotema;
    public:
        Pentagono(double p,double a){
            perimetro=p;
            apotema=a;
        }
        double area() const override{
            return (perimetro*apotema)/2;
        }
};

int main(){
    Forma* figuras[3];

    figuras[0]=new Cuadrado(5.0);
    figuras[1]=new Rombo(6.0,8.0);
    figuras[2]=new Pentagono(10.0,6.882);

    cout<<fixed<<setprecision(2);

    for(int i=0;i<3;i++){
        figuras[i]->imprimir();
    }

    for(int i=0;i<3;i++){
        delete figuras[i];
    }
}
