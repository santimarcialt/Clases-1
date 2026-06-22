#include<iostream>
#include<iomanip>
using namespace std;

class Producto{
    private:
        int codigo;
        string nombre;
        double precio;
    public:
        Producto(int c,string n,double p){
            codigo=c;
            nombre=n;
            precio=p;
        }
        int getCodigo() const{
            return codigo;
        }
        string getNombre() const{
            return nombre;
        }
        double getPrecio() const{
            return precio;
        }
        void setPrecio(double p){
            precio=p;
        }
        virtual string getCategoria() const=0;
        virtual double calcularPrecioFinal() const=0;
        virtual void imprimir() const{
            cout<<"Codigo: "<<codigo<<" | Nombre: "<<nombre<<" | Categoria: "<<getCategoria()<<" | Precio final: $"<<calcularPrecioFinal()<<endl;
        }
        virtual ~Producto(){}
};

class ProductoFisico:public Producto{
    private:
        double peso;
        string dimensiones;
    public:
        ProductoFisico(int c,string n,double p,double pe,string d):Producto(c,n,p){
            peso=pe;
            dimensiones=d;
        }
        string getCategoria() const override{
            return "Fisico";
        }
        double calcularPrecioFinal() const override{
            double envio=peso*2.5;
            return getPrecio()+envio;
        }
        void imprimir() const override{
            cout<<"Codigo: "<<getCodigo()<<" | Nombre: "<<getNombre()<<" | Categoria: "<<getCategoria()<<" | Peso: "<<peso<<"kg | Dimensiones: "<<dimensiones<<" | Precio final: $"<<calcularPrecioFinal()<<endl;
        }
};

class ProductoDigital:public Producto{
    private:
        double tamanoMB;
        string plataforma;
    public:
        ProductoDigital(int c,string n,double p,double t,string pl):Producto(c,n,p){
            tamanoMB=t;
            plataforma=pl;
        }
        string getCategoria() const override{
            return "Digital";
        }
        double calcularPrecioFinal() const override{
            return getPrecio()*0.85;
        }
        void imprimir() const override{
            cout<<"Codigo: "<<getCodigo()<<" | Nombre: "<<getNombre()<<" | Categoria: "<<getCategoria()<<" | Tamano: "<<tamanoMB<<"MB | Plataforma: "<<plataforma<<" | Precio final: $"<<calcularPrecioFinal()<<endl;
        }
};

class ProductoSuscripcion:public Producto{
    private:
        int periodoMeses;
        bool renovacionAutomatica;
    public:
        ProductoSuscripcion(int c,string n,double p,int m,bool r):Producto(c,n,p){
            periodoMeses=m;
            renovacionAutomatica=r;
        }
        string getCategoria() const override{
            return "Suscripcion";
        }
        double calcularPrecioFinal() const override{
            return getPrecio()*periodoMeses;
        }
        void imprimir() const override{
            cout<<"Codigo: "<<getCodigo()<<" | Nombre: "<<getNombre()<<" | Categoria: "<<getCategoria()<<" | Meses: "<<periodoMeses<<" | Renovacion: ";
            if(renovacionAutomatica){
                cout<<"Si";
            }
            else{
                cout<<"No";
            }
            cout<<" | Precio final: $"<<calcularPrecioFinal()<<endl;
        }
};

class Inventario{
    private:
        Producto* productos[100];
        int cantidad;
    public:
        Inventario(){
            cantidad=0;
        }
        void agregar(Producto* p){
            if(cantidad<100){
                productos[cantidad]=p;
                cantidad++;
            }
        }
        void listar() const{
            cout<<"=== Inventario ==="<<endl;
            for(int i=0;i<cantidad;i++){
                productos[i]->imprimir();
            }
        }
        Producto* buscar(int codigo) const{
            for(int i=0;i<cantidad;i++){
                if(productos[i]->getCodigo()==codigo){
                    return productos[i];
                }
            }
            return nullptr;
        }
        void actualizarPrecio(int codigo,double nuevoPrecio){
            Producto* p=buscar(codigo);
            if(p!=nullptr){
                p->setPrecio(nuevoPrecio);
                cout<<"Precio actualizado."<<endl;
            }
            else{
                cout<<"Producto no encontrado."<<endl;
            }
        }
        void eliminar(int codigo){
            int pos=-1;
            for(int i=0;i<cantidad;i++){
                if(productos[i]->getCodigo()==codigo){
                    pos=i;
                    break;
                }
            }
            if(pos!=-1){
                delete productos[pos];
                for(int i=pos;i<cantidad-1;i++){
                    productos[i]=productos[i+1];
                }
                cantidad--;
                cout<<"Producto eliminado."<<endl;
            }
            else{
                cout<<"Producto no encontrado."<<endl;
            }
        }
        double valorTotal() const{
            double total=0;
            for(int i=0;i<cantidad;i++){
                total=total+productos[i]->calcularPrecioFinal();
            }
            return total;
        }
        void reporte() const{
            listar();
            cout<<"Valor total del inventario: $"<<valorTotal()<<endl;
        }
        ~Inventario(){
            for(int i=0;i<cantidad;i++){
                delete productos[i];
            }
        }
};

int main(){
    Inventario inventario;

    inventario.agregar(new ProductoFisico(101,"Laptop",1200.00,2.5,"35x25x3"));
    inventario.agregar(new ProductoFisico(102,"Silla",80.00,7.0,"90x40x40"));
    inventario.agregar(new ProductoDigital(201,"CursoCpp",100.00,850,"Web"));
    inventario.agregar(new ProductoDigital(202,"Antivirus",60.00,300,"Windows"));
    inventario.agregar(new ProductoSuscripcion(301,"Netflix",12.00,6,true));
    inventario.agregar(new ProductoSuscripcion(302,"Gimnasio",25.00,3,false));

    cout<<fixed<<setprecision(2);

    inventario.reporte();

    cout<<endl;
    cout<<"=== Buscar producto 201 ==="<<endl;
    Producto* encontrado=inventario.buscar(201);
    if(encontrado!=nullptr){
        encontrado->imprimir();
    }
    else{
        cout<<"Producto no encontrado."<<endl;
    }

    cout<<endl;
    cout<<"=== Actualizar precio 102 ==="<<endl;
    inventario.actualizarPrecio(102,95.00);

    cout<<endl;
    cout<<"=== Eliminar producto 202 ==="<<endl;
    inventario.eliminar(202);

    cout<<endl;
    inventario.reporte();
}
