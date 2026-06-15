#include<iostream>
#include<iomanip>
using namespace std;

class Producto{
    public:
        string nombre;
        double precio;
        int stock;

        Producto(string n,double p,int s){
            nombre=n;

            if(p>=0){
                precio=p;
            }else{
                precio=0;
            }

            if(s>=0){
                stock=s;
            }else{
                stock=0;
            }
        }

        Producto(string n,double p){
            nombre=n;

            if(p>=0){
                precio=p;
            }else{
                precio=0;
            }

            stock=0;
        }

        ~Producto(){
            cout<<"Producto "<<nombre<<" eliminado del sistema."<<endl;
        }

        void vender(int cantidad){
            if(stock>=cantidad){
                stock-=cantidad;
                cout<<"Venta exitosa. Stock restante: "<<stock<<endl;
            }else{
                cout<<"Stock insuficiente."<<endl;
            }
        }

        void reabastecer(int cantidad){
            stock+=cantidad;
            cout<<"Reabastecer: "<<cantidad<<" unidades. Stock: "<<stock<<endl;
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<nombre<<" | $"<<precio<<" | Stock: "<<stock<<endl;
        }
};

int main(){
    Producto p1("Laptop",1200.0,5);

    p1.imprimir();
    p1.vender(2);
    p1.vender(10);
    p1.reabastecer(10);
    p1.imprimir();

    return 0;
}
