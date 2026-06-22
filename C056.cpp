#include<iostream>
#include<iomanip>
using namespace std;

class Cuenta{
    private:
        string numeroCuenta,titular;
        double saldo;
    protected:
        void setSaldo(double s){
            saldo=s;
        }
    public:
        Cuenta(string n,string t,double s){
            numeroCuenta=n;
            titular=t;
            if(s>=0){
                saldo=s;
            }
            else{
                saldo=0;
            }
        }
        string getNumeroCuenta() const{
            return numeroCuenta;
        }
        string getTitular() const{
            return titular;
        }
        double getSaldo() const{
            return saldo;
        }
        virtual string getTipo() const=0;
        virtual double calcularInteres() const=0;
        virtual void depositar(double monto){
            if(monto>0){
                saldo=saldo+monto;
                cout<<"Deposito realizado."<<endl;
            }
            else{
                cout<<"Monto invalido."<<endl;
            }
        }
        virtual void retirar(double monto){
            if(monto>0&&monto<=saldo){
                saldo=saldo-monto;
                cout<<"Retiro realizado."<<endl;
            }
            else{
                cout<<"Retiro invalido."<<endl;
            }
        }
        virtual void imprimir() const{
            cout<<"Cuenta: "<<numeroCuenta<<" | Titular: "<<titular<<" | Tipo: "<<getTipo()<<" | Saldo: $"<<saldo<<endl;
        }
        virtual ~Cuenta(){}
};

class CuentaAhorro:public Cuenta{
    private:
        double tasaInteresAnual,saldoMinimo;
    public:
        CuentaAhorro(string n,string t,double s,double tasa,double minimo):Cuenta(n,t,s){
            tasaInteresAnual=tasa;
            saldoMinimo=minimo;
        }
        string getTipo() const override{
            return "Ahorro";
        }
        double calcularInteres() const override{
            return getSaldo()*tasaInteresAnual;
        }
        void retirar(double monto) override{
            if(monto<=0){
                cout<<"Retiro invalido."<<endl;
            }
            else if(getSaldo()-monto>=saldoMinimo){
                setSaldo(getSaldo()-monto);
                cout<<"Retiro realizado."<<endl;
            }
            else{
                cout<<"Retiro rechazado: saldo minimo protegido."<<endl;
            }
        }
        void imprimir() const override{
            Cuenta::imprimir();
            cout<<"Tasa interes: "<<tasaInteresAnual<<" | Saldo minimo: $"<<saldoMinimo<<" | Interes: $"<<calcularInteres()<<endl;
        }
};

class CuentaCorriente:public Cuenta{
    private:
        double limiteCredito,cargoMensual;
    public:
        CuentaCorriente(string n,string t,double s,double limite,double cargo):Cuenta(n,t,s){
            limiteCredito=limite;
            cargoMensual=cargo;
        }
        string getTipo() const override{
            return "Corriente";
        }
        double calcularInteres() const override{
            return 0;
        }
        void retirar(double monto) override{
            if(monto<=0){
                cout<<"Retiro invalido."<<endl;
            }
            else if(getSaldo()-monto>=-limiteCredito){
                setSaldo(getSaldo()-monto);
                cout<<"Retiro realizado."<<endl;
            }
            else{
                cout<<"Retiro rechazado: excede limite de credito."<<endl;
            }
        }
        void aplicarCargoMensual(){
            setSaldo(getSaldo()-cargoMensual);
        }
        void imprimir() const override{
            Cuenta::imprimir();
            cout<<"Limite credito: $"<<limiteCredito<<" | Cargo mensual: $"<<cargoMensual<<" | Interes: $"<<calcularInteres()<<endl;
        }
};

class CuentaInversion:public Cuenta{
    private:
        string portafolio[5];
        int cantidadActivos;
        string riesgo;
    public:
        CuentaInversion(string n,string t,double s,string r):Cuenta(n,t,s){
            riesgo=r;
            cantidadActivos=0;
        }
        void agregarActivo(string activo){
            if(cantidadActivos<5){
                portafolio[cantidadActivos]=activo;
                cantidadActivos++;
            }
        }
        string getTipo() const override{
            return "Inversion";
        }
        double calcularInteres() const override{
            if(riesgo=="bajo"){
                return getSaldo()*0.03;
            }
            else if(riesgo=="medio"){
                return getSaldo()*0.07;
            }
            else{
                return getSaldo()*0.12;
            }
        }
        void imprimir() const override{
            Cuenta::imprimir();
            cout<<"Riesgo: "<<riesgo<<" | Interes: $"<<calcularInteres()<<endl;
            cout<<"Activos: ";
            for(int i=0;i<cantidadActivos;i++){
                cout<<portafolio[i];
                if(i<cantidadActivos-1){
                    cout<<", ";
                }
            }
            cout<<endl;
        }
};

class Banco{
    private:
        Cuenta* cuentas[200];
        int numCuentas;
    public:
        Banco(){
            numCuentas=0;
        }
        void abrirCuenta(Cuenta* c){
            if(numCuentas<200){
                cuentas[numCuentas]=c;
                numCuentas++;
                cout<<"Cuenta abierta."<<endl;
            }
            else{
                cout<<"Banco lleno."<<endl;
            }
        }
        void cerrarCuenta(string numCuenta){
            int pos=-1;
            for(int i=0;i<numCuentas;i++){
                if(cuentas[i]->getNumeroCuenta()==numCuenta){
                    pos=i;
                    break;
                }
            }
            if(pos!=-1){
                delete cuentas[pos];
                for(int i=pos;i<numCuentas-1;i++){
                    cuentas[i]=cuentas[i+1];
                }
                numCuentas--;
                cout<<"Cuenta cerrada."<<endl;
            }
            else{
                cout<<"Cuenta no encontrada."<<endl;
            }
        }
        Cuenta* buscarCuenta(string numCuenta) const{
            for(int i=0;i<numCuentas;i++){
                if(cuentas[i]->getNumeroCuenta()==numCuenta){
                    return cuentas[i];
                }
            }
            return nullptr;
        }
        void aplicarIntereses(){
            for(int i=0;i<numCuentas;i++){
                double interes=cuentas[i]->calcularInteres();
                if(interes>0){
                    cuentas[i]->depositar(interes);
                }
            }
        }
        void imprimirEstadoCuenta(string numCuenta) const{
            Cuenta* c=buscarCuenta(numCuenta);
            if(c!=nullptr){
                c->imprimir();
            }
            else{
                cout<<"Cuenta no encontrada."<<endl;
            }
        }
        double totalDepositado() const{
            double total=0;
            for(int i=0;i<numCuentas;i++){
                total=total+cuentas[i]->getSaldo();
            }
            return total;
        }
        void imprimirTodo() const{
            cout<<"=== Estado del banco ==="<<endl;
            for(int i=0;i<numCuentas;i++){
                cuentas[i]->imprimir();
                cout<<endl;
            }
            cout<<"Total depositado: $"<<totalDepositado()<<endl;
        }
        ~Banco(){
            for(int i=0;i<numCuentas;i++){
                delete cuentas[i];
            }
        }
};

int main(){
    Banco banco;

    CuentaInversion* inv1=new CuentaInversion("INV001","Carla",10000,"alto");
    inv1->agregarActivo("Acciones");
    inv1->agregarActivo("Bonos");
    inv1->agregarActivo("ETF");

    banco.abrirCuenta(new CuentaAhorro("AH001","Ana",2500,0.05,500));
    banco.abrirCuenta(new CuentaCorriente("CC001","Luis",1200,800,25));
    banco.abrirCuenta(inv1);
    banco.abrirCuenta(new CuentaAhorro("AH002","Pedro",900,0.04,300));

    cout<<fixed<<setprecision(2);

    cout<<endl;
    banco.imprimirTodo();

    cout<<endl;
    cout<<"=== Operaciones ==="<<endl;
    Cuenta* c=banco.buscarCuenta("AH001");
    if(c!=nullptr){
        c->depositar(300);
        c->retirar(1000);
    }

    c=banco.buscarCuenta("CC001");
    if(c!=nullptr){
        c->retirar(1700);
    }

    cout<<endl;
    cout<<"=== Estado de cuenta INV001 ==="<<endl;
    banco.imprimirEstadoCuenta("INV001");

    cout<<endl;
    cout<<"=== Aplicando intereses ==="<<endl;
    banco.aplicarIntereses();

    cout<<endl;
    banco.imprimirTodo();

    cout<<endl;
    cout<<"=== Cerrar cuenta AH002 ==="<<endl;
    banco.cerrarCuenta("AH002");

    cout<<endl;
    banco.imprimirTodo();
}
