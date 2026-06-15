#include<iostream>
#include<iomanip>
using namespace std;

class Cuenta{
    protected:
        string titular;
        double saldo;

    public:
        Cuenta(string titular,double saldo){
            this->titular=titular;

            if(saldo>=0){
                this->saldo=saldo;
            }else{
                this->saldo=0;
            }
        }

        string getTitular() const{
            return titular;
        }

        double getSaldo() const{
            return saldo;
        }

        virtual void depositar(double monto){
            if(monto>0){
                saldo+=monto;
                cout<<"Deposito: $"<<fixed<<setprecision(2)<<monto<<". Saldo: $"<<saldo<<endl;
            }else{
                cout<<"Deposito rechazado."<<endl;
            }
        }

        virtual void retirar(double monto){
            if(monto<=0){
                cout<<"Retiro rechazado."<<endl;
            }else if(monto<=saldo){
                saldo-=monto;
                cout<<"Retiro: $"<<fixed<<setprecision(2)<<monto<<". Saldo: $"<<saldo<<endl;
            }else{
                cout<<"Retiro rechazado."<<endl;
            }
        }

        virtual void imprimir() const{
            cout<<titular<<": $"<<fixed<<setprecision(2)<<saldo<<endl;
        }
};

class CuentaAhorro:public Cuenta{
    private:
        double tasaInteres;

    public:
        CuentaAhorro(string titular,double saldo,double tasaInteres):Cuenta(titular,saldo){
            if(tasaInteres>=0){
                this->tasaInteres=tasaInteres;
            }else{
                this->tasaInteres=0;
            }
        }

        void aplicarInteres(){
            saldo=saldo+saldo*tasaInteres;
            cout<<"Interes aplicado. Saldo: $"<<fixed<<setprecision(2)<<saldo<<endl;
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);
            cout<<"[Ahorro] "<<titular<<": $"<<saldo<<" | Interes: "<<tasaInteres*100<<"%"<<endl;
        }
};

class CuentaCorriente:public Cuenta{
    private:
        double sobregiroMax;

    public:
        CuentaCorriente(string titular,double saldo,double sobregiroMax):Cuenta(titular,saldo){
            if(sobregiroMax>=0){
                this->sobregiroMax=sobregiroMax;
            }else{
                this->sobregiroMax=0;
            }
        }

        void retirar(double monto) override{
            if(monto<=0){
                cout<<"Retiro rechazado."<<endl;
            }else if(monto<=saldo+sobregiroMax){
                saldo-=monto;
                cout<<"Retiro: $"<<fixed<<setprecision(2)<<monto<<". Saldo: $"<<saldo<<" | sobregiro permitido"<<endl;
            }else{
                cout<<"Retiro: $"<<fixed<<setprecision(2)<<monto<<" RECHAZADO: supera limite de sobregiro."<<endl;
            }
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);
            cout<<"[Corriente] "<<titular<<": $"<<saldo<<" | Sobregiro max: $"<<sobregiroMax<<endl;
        }
};

int main(){
    CuentaAhorro ahorro("Ana",1000.0,0.05);

    ahorro.imprimir();
    ahorro.depositar(200.0);
    ahorro.aplicarInteres();

    cout<<endl;

    CuentaCorriente corriente("Luis",500.0,200.0);

    corriente.imprimir();
    corriente.retirar(600.0);
    corriente.retirar(200.0);

    return 0;
}
