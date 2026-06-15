#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Cuenta{
    public:
        string titular;
        double saldo;

        void depositar(double monto){
            saldo+=monto;
            cout<<"Deposito: $"<<fixed<<setprecision(2)<<monto<<" | Nuevo saldo: $"<<saldo<<endl;
        }

        void retirar(double monto){
            if(tieneSaldo(monto)){
                saldo-=monto;
                cout<<"Retiro: $"<<fixed<<setprecision(2)<<monto<<" | Nuevo saldo: $"<<saldo<<endl;
            }else{
                cout<<"Saldo insuficiente."<<endl;
            }
        }

        void imprimir(){
            cout<<"Titular: "<<titular<<" | Saldo: $"<<fixed<<setprecision(2)<<saldo<<endl;
        }

        bool tieneSaldo(double monto){
            return saldo>=monto;
        }
};

int main(){
    Cuenta c1;

    c1.titular="Ana Torres";
    c1.saldo=500.0;

    c1.imprimir();
    c1.depositar(200.0);
    c1.retirar(100.0);
    c1.retirar(700.0);
    c1.imprimir();

    return 0;
}
