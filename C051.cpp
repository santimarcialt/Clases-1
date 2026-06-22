#include<iostream>
using namespace std;

class Material{
    private:
        int codigo,anio;
        string titulo;
    public:
        Material(int c,string t,int a){
            codigo=c;
            titulo=t;
            anio=a;
        }
        int getCodigo() const{
            return codigo;
        }
        string getTitulo() const{
            return titulo;
        }
        int getAnio() const{
            return anio;
        }
        virtual string getTipo() const=0;
        virtual bool esPrestable() const=0;
        virtual void imprimir() const{
            cout<<"["<<getTipo()<<"] ";
            cout<<"Codigo: "<<codigo<<" | Titulo: "<<titulo<<" | Anio: "<<anio;
            if(esPrestable()){
                cout<<" | Prestable";
            }
            else{
                cout<<" | No prestable";
            }
        }
        virtual ~Material(){}
};

class Libro:public Material{
    private:
        string autor;
        int paginas;
    public:
        Libro(int c,string t,int a,string au,int p):Material(c,t,a){
            autor=au;
            paginas=p;
        }
        string getTipo() const override{
            return "Libro";
        }
        bool esPrestable() const override{
            return true;
        }
        void imprimir() const override{
            Material::imprimir();
            cout<<" | Autor: "<<autor<<" | Paginas: "<<paginas<<endl;
        }
};

class Revista:public Material{
    private:
        int numero;
        string editorial;
    public:
        Revista(int c,string t,int a,int n,string e):Material(c,t,a){
            numero=n;
            editorial=e;
        }
        string getTipo() const override{
            return "Revista";
        }
        bool esPrestable() const override{
            return numero<50;
        }
        void imprimir() const override{
            Material::imprimir();
            cout<<" | Numero: "<<numero<<" | Editorial: "<<editorial<<endl;
        }
};

class DVD:public Material{
    private:
        int duracionMin;
        string clasificacion;
    public:
        DVD(int c,string t,int a,int d,string cl):Material(c,t,a){
            duracionMin=d;
            clasificacion=cl;
        }
        string getTipo() const override{
            return "DVD";
        }
        bool esPrestable() const override{
            return clasificacion!="18+";
        }
        void imprimir() const override{
            Material::imprimir();
            cout<<" | Duracion: "<<duracionMin<<" min | Clasificacion: "<<clasificacion<<endl;
        }
};

class Biblioteca{
    private:
        Material* catalogo[100];
        int cantidad;
    public:
        Biblioteca(){
            cantidad=0;
        }
        void agregar(Material* m){
            if(cantidad<100){
                catalogo[cantidad]=m;
                cantidad++;
            }
        }
        void listarTodo() const{
            cout<<"=== Catalogo completo ==="<<endl;
            for(int i=0;i<cantidad;i++){
                catalogo[i]->imprimir();
            }
        }
        void listarPrestables() const{
            cout<<"=== Materiales prestables ==="<<endl;
            for(int i=0;i<cantidad;i++){
                if(catalogo[i]->esPrestable()){
                    catalogo[i]->imprimir();
                }
            }
        }
        void buscarPorTitulo(string titulo) const{
            bool encontrado=false;
            cout<<"=== Busqueda por titulo: "<<titulo<<" ==="<<endl;
            for(int i=0;i<cantidad;i++){
                if(catalogo[i]->getTitulo()==titulo){
                    catalogo[i]->imprimir();
                    encontrado=true;
                }
            }
            if(!encontrado){
                cout<<"No se encontro el material."<<endl;
            }
        }
        ~Biblioteca(){
            for(int i=0;i<cantidad;i++){
                delete catalogo[i];
            }
        }
};

int main(){
    Biblioteca b;

    b.agregar(new Libro(101,"El Quijote",1605,"Cervantes",863));
    b.agregar(new Libro(102,"Cien anios de soledad",1967,"Garcia Marquez",417));
    b.agregar(new Revista(201,"Ciencia Hoy",2020,35,"Andes"));
    b.agregar(new Revista(202,"Historia Mundial",1995,80,"Global"));
    b.agregar(new DVD(301,"Interestelar",2014,169,"13+"));
    b.agregar(new DVD(302,"Pelicula adulta",2021,120,"18+"));

    b.listarTodo();
    cout<<endl;

    b.listarPrestables();
    cout<<endl;

    b.buscarPorTitulo("Interestelar");
    cout<<endl;

    b.buscarPorTitulo("Libro inexistente");
}
