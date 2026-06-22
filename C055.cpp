#include<iostream>
#include<iomanip>
using namespace std;

class Instrumento{
    public:
        virtual void tocar() const=0;
        virtual string getFamilia() const=0;
        virtual double getPrecio() const=0;
        virtual void imprimir() const{
            cout<<getFamilia()<<" | Precio: $"<<getPrecio()<<endl;
        }
        virtual ~Instrumento(){}
};

class Cuerdas:public Instrumento{
    public:
        string getFamilia() const override{
            return "Cuerdas";
        }
        virtual int getCuerdas() const=0;
};

class Viento:public Instrumento{
    public:
        string getFamilia() const override{
            return "Viento";
        }
        virtual string getMaterial() const=0;
};

class Percusion:public Instrumento{
    public:
        string getFamilia() const override{
            return "Percusion";
        }
};

class Guitarra:public Cuerdas{
    private:
        int cuerdas;
        double precio;
    public:
        Guitarra(int c,double p){
            cuerdas=c;
            precio=p;
        }
        void tocar() const override{
            cout<<"La guitarra suena: strum strum"<<endl;
        }
        int getCuerdas() const override{
            return cuerdas;
        }
        double getPrecio() const override{
            return precio;
        }
        void imprimir() const override{
            cout<<"Guitarra | Familia: "<<getFamilia()<<" | Cuerdas: "<<cuerdas<<" | Precio: $"<<precio<<endl;
        }
};

class Violin:public Cuerdas{
    private:
        int cuerdas;
        double precio;
    public:
        Violin(int c,double p){
            cuerdas=c;
            precio=p;
        }
        void tocar() const override{
            cout<<"El violin suena: fiiin fiiin"<<endl;
        }
        int getCuerdas() const override{
            return cuerdas;
        }
        double getPrecio() const override{
            return precio;
        }
        void imprimir() const override{
            cout<<"Violin | Familia: "<<getFamilia()<<" | Cuerdas: "<<cuerdas<<" | Precio: $"<<precio<<endl;
        }
};

class Trompeta:public Viento{
    private:
        string material;
        double precio;
    public:
        Trompeta(string m,double p){
            material=m;
            precio=p;
        }
        void tocar() const override{
            cout<<"La trompeta suena: taran taran"<<endl;
        }
        string getMaterial() const override{
            return material;
        }
        double getPrecio() const override{
            return precio;
        }
        void imprimir() const override{
            cout<<"Trompeta | Familia: "<<getFamilia()<<" | Material: "<<material<<" | Precio: $"<<precio<<endl;
        }
};

class Flauta:public Viento{
    private:
        string material;
        double precio;
    public:
        Flauta(string m,double p){
            material=m;
            precio=p;
        }
        void tocar() const override{
            cout<<"La flauta suena: fuuu fuuu"<<endl;
        }
        string getMaterial() const override{
            return material;
        }
        double getPrecio() const override{
            return precio;
        }
        void imprimir() const override{
            cout<<"Flauta | Familia: "<<getFamilia()<<" | Material: "<<material<<" | Precio: $"<<precio<<endl;
        }
};

class Bateria:public Percusion{
    private:
        int piezas;
        double precio;
    public:
        Bateria(int pi,double p){
            piezas=pi;
            precio=p;
        }
        void tocar() const override{
            cout<<"La bateria suena: pum pum crash"<<endl;
        }
        double getPrecio() const override{
            return precio;
        }
        void imprimir() const override{
            cout<<"Bateria | Familia: "<<getFamilia()<<" | Piezas: "<<piezas<<" | Precio: $"<<precio<<endl;
        }
};

class Tambor:public Percusion{
    private:
        double diametro;
        double precio;
    public:
        Tambor(double d,double p){
            diametro=d;
            precio=p;
        }
        void tocar() const override{
            cout<<"El tambor suena: tum tum"<<endl;
        }
        double getPrecio() const override{
            return precio;
        }
        void imprimir() const override{
            cout<<"Tambor | Familia: "<<getFamilia()<<" | Diametro: "<<diametro<<" | Precio: $"<<precio<<endl;
        }
};

int main(){
    Instrumento* orquesta[8];

    orquesta[0]=new Guitarra(6,450.00);
    orquesta[1]=new Violin(4,700.00);
    orquesta[2]=new Trompeta("Metal",550.00);
    orquesta[3]=new Flauta("Plata",300.00);
    orquesta[4]=new Bateria(5,1200.00);
    orquesta[5]=new Tambor(14.0,250.00);
    orquesta[6]=new Guitarra(12,650.00);
    orquesta[7]=new Flauta("Madera",280.00);

    int cuerdas=0,viento=0,percusion=0;
    double total=0;

    cout<<fixed<<setprecision(2);

    cout<<"=== Orquesta tocando ==="<<endl;
    for(int i=0;i<8;i++){
        orquesta[i]->tocar();
    }

    cout<<endl;
    cout<<"=== Instrumentos ==="<<endl;
    for(int i=0;i<8;i++){
        orquesta[i]->imprimir();
        total=total+orquesta[i]->getPrecio();

        if(orquesta[i]->getFamilia()=="Cuerdas"){
            cuerdas++;
        }
        else if(orquesta[i]->getFamilia()=="Viento"){
            viento++;
        }
        else if(orquesta[i]->getFamilia()=="Percusion"){
            percusion++;
        }
    }

    cout<<endl;
    cout<<"=== Cantidad por familia ==="<<endl;
    cout<<"Cuerdas: "<<cuerdas<<endl;
    cout<<"Viento: "<<viento<<endl;
    cout<<"Percusion: "<<percusion<<endl;

    cout<<endl;
    cout<<"Valor total de la orquesta: $"<<total<<endl;

    for(int i=0;i<8;i++){
        delete orquesta[i];
    }
}
