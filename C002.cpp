#include<iostream>
#include<string>
using namespace std;
class Persona{
    public:
        string nombre;
        int edad;
        double altura;

        void imprimir(){
            cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<", Altura: "<<altura<<"m"<<endl;
        }

        bool esMayorDeEdad(){
            return edad>=18;
        }

        string saludar(){
            return "Hola, soy "+nombre+" y tengo "+to_string(edad)+" anios.";
        } 
        void verificar (bool siMayorDeEdad) {
          if(siMayorDeEdad==true){
          cout<<"Mayor de edad: SI"<<endl;
          }else{
          cout<<"Mayor de edad: NO"<<endl;
    }	
		}
};

int main(){
    Persona p1;
    Persona p2;
    Persona p3;

    p1.nombre="Pedro";
    p1.edad=55;
    p1.altura=1.63;

    p2.nombre="Santiago";
    p2.edad=13;
    p2.altura=1.22;

    p3.nombre="Sofia";
    p3.edad=19;
    p3.altura=2.10;

    p1.imprimir();
    p1.verificar(p1.esMayorDeEdad());
    cout<<p1.saludar()<<endl<<endl;

    p2.imprimir();
    p2.verificar(p2.esMayorDeEdad());
    cout<<p2.saludar()<<endl<<endl;

    p3.imprimir();
    p3.verificar(p3.esMayorDeEdad());
    cout<<p3.saludar()<<endl;

    return 0;
}
