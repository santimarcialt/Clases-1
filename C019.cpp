#include<iostream>
#include<iomanip>
using namespace std;

class Persona{
    private:
        string nombre;
        int edad;
        double altura;

    public:
        Persona(string n,int e,double h){
            nombre=n;
            edad=0;
            altura=0;
            setEdad(e);
            setAltura(h);
        }

        void setNombre(string n){
            nombre=n;
        }

        void setEdad(int e){
            if(e>=0 && e<=120){
                edad=e;
            }else{
                cout<<"Edad invalida."<<endl;
            }
        }

        void setAltura(double h){
            if(h>=0.5 && h<=2.5){
                altura=h;
            }else{
                cout<<"Altura invalida."<<endl;
            }
        }

        string getNombre(){
            return nombre;
        }

        int getEdad(){
            return edad;
        }

        double getAltura(){
            return altura;
        }

        void imprimir(){
            cout<<fixed<<setprecision(2);
            cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<", Altura: "<<altura<<"m"<<endl;
        }
};

int main(){
    Persona p1("Ana",22,1.65);

    p1.imprimir();

    p1.setEdad(150);
    p1.setAltura(3.0);

    p1.imprimir();

    return 0;
}
