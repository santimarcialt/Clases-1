#include<iostream>
#include<iomanip>
using namespace std;

class CuentaBancaria{
    private:
        string titular;
        double saldo;

    public:
        CuentaBancaria(string titular,double saldo){
            this->titular=titular;

            if(saldo>=0){
                this->saldo=saldo;
            }else{
                this->saldo=0;
                cout<<this->titular<<": $"<<fixed<<setprecision(2)<<this->saldo<<" iniciado con saldo negativo, corregido."<<endl;
            }
        }

        void depositar(double monto){
            if(monto>0){
                saldo+=monto;
                cout<<"Deposito: $"<<fixed<<setprecision(2)<<monto<<". Saldo: $"<<saldo<<endl;
            }else{
                cout<<"Error: monto debe ser positivo."<<endl;
            }
        }

        void retirar(double monto){
            if(monto<=0){
                cout<<"Error: monto debe ser positivo."<<endl;
            }else if(monto<=saldo){
                saldo-=monto;
                cout<<"Retiro: $"<<fixed<<setprecision(2)<<monto<<". Saldo: $"<<saldo<<endl;
            }else{
                cout<<"Error: saldo insuficiente."<<endl;
            }
        }

        string getTitular() const{
            return titular;
        }

        double getSaldo() const{
            return saldo;
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<titular<<": $"<<saldo<<endl;
        }
};

int main(){
    CuentaBancaria cuenta("Ana Torres",-50.0);

    cuenta.depositar(500.0);
    cuenta.retirar(200.0);
    cuenta.retirar(500.0);
    cuenta.depositar(-100.0);
    cuenta.imprimir();

    return 0;
}
