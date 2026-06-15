#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Punto{
    public:
        double x;
        double y;

        void imprimir(){
            cout<<"("<<fixed<<setprecision(2)<<x<<", "<<y<<")";
        }

        double distanciaA(Punto otro){
            return sqrt((x-otro.x)*(x-otro.x)+(y-otro.y)*(y-otro.y));
        }

        Punto puntoMedio(Punto otro){
            Punto medio;
            medio.x=(x+otro.x)/2;
            medio.y=(y+otro.y)/2;
            return medio;
        }
};

int main(){
    Punto p1;
    Punto p2;
    Punto medio;

    p1.x=3;
    p1.y=4;

    p2.x=7;
    p2.y=1;

    medio=p1.puntoMedio(p2);

    cout<<fixed<<setprecision(2);

    cout<<"P1: ";
    p1.imprimir();
    cout<<endl<<endl;

    cout<<"P2: ";
    p2.imprimir();
    cout<<endl<<endl;

    cout<<"Distancia: "<<p1.distanciaA(p2)<<endl<<endl;

    cout<<"Punto medio: ";
    medio.imprimir();

    return 0;
}
