#include<iostream>
#include<iomanip>
using namespace std;

class Persona{
    protected:
        string nombre,cedula,email,telefono;
    public:
        Persona(string n,string c,string e,string t){
            nombre=n;
            cedula=c;
            email=e;
            telefono=t;
        }
        string getNombre() const{
            return nombre;
        }
        string getCedula() const{
            return cedula;
        }
        string getEmail() const{
            return email;
        }
        string getTelefono() const{
            return telefono;
        }
        virtual void imprimir() const{
            cout<<nombre<<" | Cedula: "<<cedula<<" | Email: "<<email<<" | Telefono: "<<telefono;
        }
        virtual ~Persona(){}
};

class Estudiante:public Persona{
    private:
        string matricula,carrera;
        int semestre,numNotas;
        double notas[10];
    public:
        Estudiante(string n,string c,string e,string t,string m,string ca,int s):Persona(n,c,e,t){
            matricula=m;
            carrera=ca;
            semestre=s;
            numNotas=0;
        }
        void agregarNota(double nota){
            if(numNotas<10){
                notas[numNotas]=nota;
                numNotas++;
            }
        }
        double calcularPromedio() const{
            if(numNotas==0){
                return 0;
            }
            double suma=0;
            for(int i=0;i<numNotas;i++){
                suma=suma+notas[i];
            }
            return suma/numNotas;
        }
        bool estaEnRiesgo() const{
            return calcularPromedio()<70;
        }
        void imprimir() const override{
            Persona::imprimir();
            cout<<" | Matricula: "<<matricula<<" | Carrera: "<<carrera<<" | Semestre: "<<semestre<<" | Promedio: "<<calcularPromedio();
            if(estaEnRiesgo()){
                cout<<" | En riesgo";
            }
            else{
                cout<<" | Aprobado";
            }
            cout<<endl;
        }
};

class Profesor:public Persona{
    protected:
        string titulo,departamento;
        double salario;
        string materias[5];
        int numMaterias;
    public:
        Profesor(string n,string c,string e,string t,string ti,string d,double s):Persona(n,c,e,t){
            titulo=ti;
            departamento=d;
            salario=s;
            numMaterias=0;
        }
        void agregarMateria(string m){
            if(numMaterias<5){
                materias[numMaterias]=m;
                numMaterias++;
            }
        }
        virtual double calcularBono() const=0;
        virtual string getTipo() const=0;
        double getSalario() const{
            return salario;
        }
        void imprimir() const override{
            Persona::imprimir();
            cout<<" | "<<getTipo()<<" | Titulo: "<<titulo<<" | Departamento: "<<departamento<<" | Salario: $"<<salario<<" | Bono: $"<<calcularBono()<<endl;
            cout<<"Materias: ";
            for(int i=0;i<numMaterias;i++){
                cout<<materias[i];
                if(i<numMaterias-1){
                    cout<<", ";
                }
            }
            cout<<endl;
        }
};

class ProfesorTitular:public Profesor{
    public:
        ProfesorTitular(string n,string c,string e,string t,string ti,string d,double s):Profesor(n,c,e,t,ti,d,s){}
        double calcularBono() const override{
            return salario*0.15;
        }
        string getTipo() const override{
            return "Profesor titular";
        }
};

class ProfesorContratado:public Profesor{
    public:
        ProfesorContratado(string n,string c,string e,string t,string ti,string d,double s):Profesor(n,c,e,t,ti,d,s){}
        double calcularBono() const override{
            return salario*0.05;
        }
        string getTipo() const override{
            return "Profesor contratado";
        }
};

class Universidad{
    private:
        Estudiante* estudiantes[500];
        Profesor* profesores[100];
        int numEstudiantes,numProfesores;
    public:
        Universidad(){
            numEstudiantes=0;
            numProfesores=0;
        }
        void matricularEstudiante(Estudiante* e){
            if(numEstudiantes<500){
                estudiantes[numEstudiantes]=e;
                numEstudiantes++;
            }
        }
        void contratarProfesor(Profesor* p){
            if(numProfesores<100){
                profesores[numProfesores]=p;
                numProfesores++;
            }
        }
        void listarEstudiantesRiesgo() const{
            cout<<"=== Estudiantes en riesgo ==="<<endl;
            for(int i=0;i<numEstudiantes;i++){
                if(estudiantes[i]->estaEnRiesgo()){
                    estudiantes[i]->imprimir();
                }
            }
        }
        void listarProfesoresBono() const{
            cout<<"=== Profesores con bono ==="<<endl;
            for(int i=0;i<numProfesores;i++){
                profesores[i]->imprimir();
            }
        }
        double presupuestoNomina() const{
            double total=0;
            for(int i=0;i<numProfesores;i++){
                total=total+profesores[i]->getSalario()+profesores[i]->calcularBono();
            }
            return total;
        }
        void listarTodo() const{
            cout<<"=== Estudiantes ==="<<endl;
            for(int i=0;i<numEstudiantes;i++){
                estudiantes[i]->imprimir();
            }
            cout<<endl;
            cout<<"=== Profesores ==="<<endl;
            for(int i=0;i<numProfesores;i++){
                profesores[i]->imprimir();
            }
        }
        ~Universidad(){
            for(int i=0;i<numEstudiantes;i++){
                delete estudiantes[i];
            }
            for(int i=0;i<numProfesores;i++){
                delete profesores[i];
            }
        }
};

int main(){
    Universidad u;

    Estudiante* e1=new Estudiante("Ana","1765437212","ana@gmail.com","099111","M001","Computacion",2);
    e1->agregarNota(85);
    e1->agregarNota(90);
    e1->agregarNota(80);

    Estudiante* e2=new Estudiante("Luis","1788894563","luis@gmail.com","099222","M002","Matematicas",1);
    e2->agregarNota(60);
    e2->agregarNota(65);
    e2->agregarNota(68);

    Estudiante* e3=new Estudiante("Carla","1723456549","carla@gmail.com","099333","M003","Fisica",3);
    e3->agregarNota(95);
    e3->agregarNota(88);
    e3->agregarNota(92);

    ProfesorTitular* p1=new ProfesorTitular("Dr. Perez","1723456789","perez@gmail.com","098111","PhD","Ciencias",3000);
    p1->agregarMateria("Calculo");
    p1->agregarMateria("Algebra");

    ProfesorContratado* p2=new ProfesorContratado("Ing. Mora","1719876543","mora@gmail.com","098222","MSc","Computacion",1800);
    p2->agregarMateria("Programacion");
    p2->agregarMateria("Bases de datos");

    u.matricularEstudiante(e1);
    u.matricularEstudiante(e2);
    u.matricularEstudiante(e3);

    u.contratarProfesor(p1);
    u.contratarProfesor(p2);

    cout<<fixed<<setprecision(2);

    u.listarTodo();
    cout<<endl;

    u.listarEstudiantesRiesgo();
    cout<<endl;

    u.listarProfesoresBono();
    cout<<endl;

    cout<<"Presupuesto nomina: $"<<u.presupuestoNomina();
}
