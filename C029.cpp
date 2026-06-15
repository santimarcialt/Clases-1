#include<iostream>
using namespace std;

class Animal{
    protected:
        string nombre;

    public:
        Animal(string n):nombre(n){}

        string getNombre() const{
            return nombre;
        }

        virtual void hacerSonido(){
            cout<<"Sonido";
        }

        virtual void imprimir(){
            cout<<nombre<<endl;
        }
};

class Perro:public Animal{
    private:
        string raza;

    public:
        Perro(string n,string r):Animal(n){
            raza=r;
        }

        void hacerSonido() override{
            cout<<"Guau!";
        }

        void imprimir() override{
            cout<<nombre<<" - Raza: "<<raza<<endl;
        }
};

class Gato:public Animal{
    private:
        bool esCallejero;

    public:
        Gato(string n,bool c):Animal(n){
            esCallejero=c;
        }

        void hacerSonido() override{
            cout<<"Miau!";
        }

        void imprimir() override{
            cout<<nombre<<" - Callejero: ";
            if(esCallejero){
                cout<<"Si"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
};

int main(){
    Perro p1("Rex","Labrador");
    Gato g1("Luna",false);

    cout<<p1.getNombre()<<" (Labrador) dice: ";
    p1.hacerSonido();
    cout<<endl;

    p1.imprimir();

    cout<<g1.getNombre()<<" (Callejero: No) dice: ";
    g1.hacerSonido();
    cout<<endl;

    g1.imprimir();

    return 0;
}
