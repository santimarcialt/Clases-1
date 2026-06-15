#include<iostream>
#include<iomanip>
using namespace std;

class Libro{
    private:
        string titulo;
        string autor;
        int anio;
        double precio;

    public:
        Libro(string titulo,string autor,int anio,double precio){
            this->titulo=titulo;
            this->autor=autor;
            this->anio=anio;
            this->precio=0;
            setPrecio(precio);
        }

        const string& getTitulo() const{
            return titulo;
        }

        const string& getAutor() const{
            return autor;
        }

        int getAnio() const{
            return anio;
        }

        double getPrecio() const{
            return precio;
        }

        void setPrecio(double p){
            if(p>=0){
                precio=p;
            }else{
                cout<<"Precio invalido."<<endl;
            }
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"Titulo: "<<getTitulo()<<endl;
            cout<<"Autor: "<<getAutor()<<endl;
            cout<<"Anio: "<<getAnio()<<endl;
            cout<<"Precio: $"<<getPrecio()<<endl;
        }
};

int main(){
    Libro l1("El Principito","Antoine de Saint-Exupery",1943,12.50);

    l1.imprimir();

    return 0;
}
