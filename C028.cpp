#include<iostream>
#include<iomanip>
using namespace std;

class ItemInventario{
    private:
        string codigo;
        string nombre;
        int cantidad;
        double precio;

    public:
        ItemInventario(string codigo,string nombre,int cantidad,double precio){
            this->codigo=codigo;
            this->nombre=nombre;
            this->cantidad=0;
            this->precio=0;
            setCantidad(cantidad);
            setPrecio(precio);
        }

        string getCodigo() const{
            return codigo;
        }

        string getNombre() const{
            return nombre;
        }

        int getCantidad() const{
            return cantidad;
        }

        double getPrecio() const{
            return precio;
        }

        void setCantidad(int cantidad){
            if(cantidad>=0){
                this->cantidad=cantidad;
            }else{
                cout<<"Cantidad invalida."<<endl;
            }
        }

        void setPrecio(double precio){
            if(precio>=0){
                this->precio=precio;
            }else{
                cout<<"Precio invalido."<<endl;
            }
        }

        double valorTotal() const{
            return cantidad*precio;
        }

        void vender(int n){
            if(n<=0){
                cout<<"Cantidad invalida."<<endl;
            }else if(n<=cantidad){
                cantidad-=n;
                cout<<"Venta de "<<n<<" unidades. Quedan: "<<cantidad<<endl;
            }else{
                cout<<"Stock insuficiente. Solo hay "<<cantidad<<" unidades."<<endl;
            }
        }

        void reabastecer(int n){
            if(n>0){
                cantidad+=n;
                cout<<"Reabastecido: +"<<n<<" unidades. Total: "<<cantidad<<endl;
            }else{
                cout<<"Cantidad invalida."<<endl;
            }
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"["<<codigo<<"] "<<nombre<<" | Cant: "<<cantidad<<" | Precio: $"<<precio<<" | Total: $"<<valorTotal()<<endl;
        }
};

int main(){
    ItemInventario item("A001","Laptop",10,1200.0);

    item.imprimir();
    item.vender(3);
    item.vender(10);
    item.reabastecer(20);
    item.imprimir();

    return 0;
}
