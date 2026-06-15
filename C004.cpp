#include<iostream>
using namespace std;

class Contador{
    public:
        int valor;

        void incrementar(){
            valor++;
        }

        void decrementar(){
            valor--;
        }

        void incrementarEn(int n){
            valor+=n;
        }

        void reset(){
            valor=0;
        }

        void imprimir(){
            cout<<"Valor: "<<valor<<endl;
        }
};

int main(){
    Contador c;

    c.valor=10;

    c.imprimir();

    c.incrementar();
    c.incrementar();

    c.imprimir();

    c.decrementar();

    c.incrementarEn(5);

    c.imprimir();

    c.reset();

    c.imprimir();

    return 0;
}
