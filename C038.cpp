#include<iostream>
using namespace std;
class Animal{
    public:
        string nombre;
        Animal(string n){
            nombre=n;
        }
        virtual void hacerSonido(){
            cout<<"Sonido de animal";
        }
        virtual void imprimir(){
            cout<<nombre<<" : ";
            hacerSonido();
            cout<<endl;
        }
};
class Perro:public Animal{
    public:
        Perro(string n):Animal(n){}
        void hacerSonido() override{
            cout<<"Guau!";
        }
};
class Gato:public Animal{
    public:
        Gato(string n):Animal(n){}
        void hacerSonido() override{
            cout<<"Miau!";
        }
};
class Pajaro:public Animal{
    public:
        Pajaro(string n):Animal(n){}
        void hacerSonido() override{
            if(nombre=="Loro"){
                cout<<"Loro quiere galleta!";
            }
            else{
                cout<<"Pio pio!";
            }
        }
};
int main(){
    Animal* animales[6];
    animales[0]=new Perro("Rex");
    animales[1]=new Gato("Luna");
    animales[2]=new Pajaro("Pio");
    animales[3]=new Perro("Max");
    animales[4]=new Gato("Pelusa");
    animales[5]=new Pajaro("Loro");

    for(int i=0;i<6;i++){
        animales[i]->imprimir();
    }

    for(int i=0;i<6;i++){
        delete animales[i];
    }
}
