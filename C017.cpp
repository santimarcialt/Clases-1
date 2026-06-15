#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Punto{
    public:
        double x;
        double y;

        Punto(double a,double b):x(a),y(b){}

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"("<<x<<", "<<y<<")";
        }

        double distanciaA(Punto otro) const{
            return sqrt((x-otro.x)*(x-otro.x)+(y-otro.y)*(y-otro.y));
        }
};

class Segmento{
    public:
        Punto inicio;
        Punto fin;

        Segmento(Punto p1,Punto p2):inicio(p1),fin(p2){}

        double longitud(){
            return inicio.distanciaA(fin);
        }

        void imprimir(){
            cout<<"Inicio: ";
            inicio.imprimir();
            cout<<endl;

            cout<<"Fin: ";
            fin.imprimir();
            cout<<endl;

            cout<<"Longitud: "<<fixed<<setprecision(2)<<longitud()<<endl;
        }
};

int main(){
    Punto p1(0,0);
    Punto p2(3,4);

    Segmento s1(p1,p2);

    s1.imprimir();

    return 0;
}
