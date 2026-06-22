#include<iostream>
#include<iomanip>
using namespace std;

class Empleado{
    protected:
        string nombre;
    public:
        Empleado(string n){
            nombre=n;
        }
        string getNombre() const{
            return nombre;
        }
        virtual double calcularSalarioMensual() const=0;
        virtual double calcularImpuesto() const=0;
        virtual void imprimir() const=0;
        virtual ~Empleado(){}
};

class EmpleadoFijo:public Empleado{
    private:
        double salarioMensual;
    public:
        EmpleadoFijo(string n,double s):Empleado(n){
            salarioMensual=s;
        }
        double calcularSalarioMensual() const override{
            return salarioMensual;
        }
        double calcularImpuesto() const override{
            if(salarioMensual>2000){
                return salarioMensual*0.15;
            }
            else{
                return salarioMensual*0.10;
            }
        }
        void imprimir() const override{
            cout<<nombre<<" | Fijo | Bruto: $"<<calcularSalarioMensual()<<" | Impuesto: $"<<calcularImpuesto()<<" | Neto: $"<<calcularSalarioMensual()-calcularImpuesto()<<endl;
        }
};

class EmpleadoHora:public Empleado{
    private:
        double horasSemanales,tarifaHora;
    public:
        EmpleadoHora(string n,double h,double t):Empleado(n){
            horasSemanales=h;
            tarifaHora=t;
        }
        double calcularSalarioMensual() const override{
            return horasSemanales*tarifaHora*4;
        }
        double calcularImpuesto() const override{
            return calcularSalarioMensual()*0.08;
        }
        void imprimir() const override{
            cout<<nombre<<" | Hora | Bruto: $"<<calcularSalarioMensual()<<" | Impuesto: $"<<calcularImpuesto()<<" | Neto: $"<<calcularSalarioMensual()-calcularImpuesto()<<endl;
        }
};

class EmpleadoComision:public Empleado{
    private:
        double salarioBase,ventas,pctComision;
    public:
        EmpleadoComision(string n,double s,double v,double p):Empleado(n){
            salarioBase=s;
            ventas=v;
            pctComision=p;
        }
        double calcularSalarioMensual() const override{
            return salarioBase+(ventas*pctComision);
        }
        double calcularImpuesto() const override{
            return calcularSalarioMensual()*0.12;
        }
        void imprimir() const override{
            cout<<nombre<<" | Comision | Bruto: $"<<calcularSalarioMensual()<<" | Impuesto: $"<<calcularImpuesto()<<" | Neto: $"<<calcularSalarioMensual()-calcularImpuesto()<<endl;
        }
};

class Nomina{
    private:
        Empleado* lista[50];
        int cantidad;
    public:
        Nomina(){
            cantidad=0;
        }
        void agregar(Empleado* e){
            if(cantidad<50){
                lista[cantidad]=e;
                cantidad++;
            }
        }
        double totalBruto() const{
            double total=0;
            for(int i=0;i<cantidad;i++){
                total=total+lista[i]->calcularSalarioMensual();
            }
            return total;
        }
        double totalImpuestos() const{
            double total=0;
            for(int i=0;i<cantidad;i++){
                total=total+lista[i]->calcularImpuesto();
            }
            return total;
        }
        double totalNeto() const{
            return totalBruto()-totalImpuestos();
        }
        void imprimirNomina() const{
            cout<<"=== Nomina ==="<<endl;
            for(int i=0;i<cantidad;i++){
                lista[i]->imprimir();
            }
            cout<<"Total bruto: $"<<totalBruto()<<endl;
            cout<<"Total impuestos: $"<<totalImpuestos()<<endl;
            cout<<"Total neto: $"<<totalNeto()<<endl;
        }
        ~Nomina(){
            for(int i=0;i<cantidad;i++){
                delete lista[i];
            }
        }
};

int main(){
    Nomina nomina;

    nomina.agregar(new EmpleadoFijo("Ana",2500));
    nomina.agregar(new EmpleadoFijo("Luis",1800));
    nomina.agregar(new EmpleadoHora("Carla",40,12));
    nomina.agregar(new EmpleadoHora("Pedro",30,10));
    nomina.agregar(new EmpleadoComision("Maria",1200,5000,0.08));
    nomina.agregar(new EmpleadoComision("Jorge",1500,8000,0.10));

    cout<<fixed<<setprecision(2);

    nomina.imprimirNomina();
}
