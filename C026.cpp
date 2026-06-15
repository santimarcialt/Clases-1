#include<iostream>
using namespace std;

class Semaforo{
    private:
        string estado;

    public:
        Semaforo(){
            estado="rojo";
        }

        void avanzar(){
            if(estado=="rojo"){
                estado="verde";
            }else if(estado=="verde"){
                estado="amarillo";
            }else{
                estado="rojo";
            }
        }

        string getEstado() const{
            return estado;
        }

        void imprimir() const{
            cout<<"Estado: "<<getEstado()<<endl;
        }
};

int main(){
    Semaforo s1;

    s1.imprimir();

    for(int i=1;i<=7;i++){
        s1.avanzar();
        s1.imprimir();
    }

    return 0;
}
