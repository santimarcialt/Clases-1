#include<iostream>
#include<iomanip>
using namespace std;

class Persona{
    protected:
        string nombre;
        int edad;

    public:
        Persona(string n,int e):nombre(n),edad(e){}

        virtual void imprimir() const{
            cout<<nombre<<" | "<<edad<<" anios";
        }
};

class Empleado:public Persona{
    private:
        string empresa;
        double salario;

    public:
        Empleado(string n,int e,string emp,double sal):Persona(n,e){
            empresa=emp;
            salario=sal;
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);
            cout<<nombre<<" | "<<edad<<" anios | Empresa: "<<empresa<<" | Salario: $"<<salario<<endl;
        }
};

class Estudiante:public Persona{
    private:
        string carrera;
        int semestre;

    public:
        Estudiante(string n,int e,string c,int s):Persona(n,e){
            carrera=c;
            semestre=s;
        }

        void imprimir() const override{
            cout<<nombre<<" | "<<edad<<" anios | Carrera: "<<carrera<<" | Semestre: "<<semestre<<endl;
        }
};

int main(){
    Empleado emp1("Ana Torres",28,"USFQ",2500.0);
    Estudiante est1("Luis Mora",20,"Computacion",4);

    emp1.imprimir();
    est1.imprimir();

    return 0;
}
