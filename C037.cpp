#include<iostream>
#include<iomanip>
using namespace std;

class Empleado{
    protected:
        string nombre;
        double salario;

    public:
        Empleado(string nombre,double salario){
            this->nombre=nombre;
            this->salario=salario;
        }

        string getNombre() const{
            return nombre;
        }

        double getSalario() const{
            return salario;
        }

        virtual double calcularBono() const{
            return 0;
        }

        virtual void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<nombre<<": $"<<salario<<" | Bono: $"<<calcularBono()<<endl;
        }
};

class Programador:public Empleado{
    private:
        string lenguaje;

    public:
        Programador(string nombre,double salario,string lenguaje):Empleado(nombre,salario){
            this->lenguaje=lenguaje;
        }

        double calcularBono() const override{
            return salario*0.10;
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);
            cout<<nombre<<" (Programador/"<<lenguaje<<"): $"<<salario<<" | Bono: $"<<calcularBono()<<endl;
        }
};

class Gerente:public Empleado{
    private:
        string departamento;

    public:
        Gerente(string nombre,double salario,string departamento):Empleado(nombre,salario){
            this->departamento=departamento;
        }

        double calcularBono() const override{
            return salario*0.20;
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);
            cout<<nombre<<" (Gerente/"<<departamento<<"): $"<<salario<<" | Bono: $"<<calcularBono()<<endl;
        }
};

class Director:public Gerente{
    private:
        double presupuesto;

    public:
        Director(string nombre,double salario,string departamento,double presupuesto):Gerente(nombre,salario,departamento){
            this->presupuesto=presupuesto;
        }

        double calcularBono() const override{
            return getSalario()*0.30;
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);
            cout<<getNombre()<<" (Director): $"<<getSalario()<<" | Bono: $"<<calcularBono()<<" | Ppto: $"<<presupuesto<<endl;
        }
};

int main(){
    Programador p1("Ana",3000.0,"Python");
    Gerente g1("Luis",5000.0,"Sistemas");
    Director d1("Carla",8000.0,"General",500000.0);

    p1.imprimir();
    g1.imprimir();
    d1.imprimir();

    return 0;
}
