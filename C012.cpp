#include<iostream>
#include<iomanip>
using namespace std;

class Punto3D{
    public:
        double x;
        double y;
        double z;

        Punto3D(){
            x=0;
            y=0;
            z=0;
        }

        Punto3D(double px,double py,double pz){
            x=px;
            y=py;
            z=pz;
        }

        void imprimir(){
            cout<<fixed<<setprecision(2);
            cout<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
        }
};

int main(){
    Punto3D p1;
    Punto3D p2(3.0,1.0,4.0);
    Punto3D p3(1.0,5.0,9.0);

    p1.imprimir();
    p2.imprimir();
    p3.imprimir();

    return 0;
}
