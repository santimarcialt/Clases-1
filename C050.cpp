#include<iostream>
#include<iomanip>
using namespace std;

class Vehiculo{
    protected:
        string marca,modelo;
        int anio;
        double precioBase;
    public:
        Vehiculo(string ma,string mo,int a,double p){
            marca=ma;
            modelo=mo;
            anio=a;
            precioBase=p;
        }
        string getMarca() const{
            return marca;
        }
        string getModelo() const{
            return modelo;
        }
        int getAnio() const{
            return anio;
        }
        double getPrecioBase() const{
            return precioBase;
        }
        virtual double calcularCosto() const=0;
        virtual string getTipo() const=0;
        void imprimir() const{
            cout<<marca<<" "<<modelo<<" | "<<anio<<" | "<<getTipo()<<" | Costo: $"<<calcularCosto()<<endl;
        }
        virtual ~Vehiculo(){}
};

class Auto:public Vehiculo{
    public:
        Auto(string ma,string mo,int a,double p):Vehiculo(ma,mo,a,p){}
        double calcularCosto() const override{
            if(anio>2020){
                return precioBase*1.10;
            }
            else{
                return precioBase;
            }
        }
        string getTipo() const override{
            return "Auto";
        }
};

class Moto:public Vehiculo{
    public:
        Moto(string ma,string mo,int a,double p):Vehiculo(ma,mo,a,p){}
        double calcularCosto() const override{
            return precioBase*0.70;
        }
        string getTipo() const override{
            return "Moto";
        }
};

class Camion:public Vehiculo{
    public:
        Camion(string ma,string mo,int a,double p):Vehiculo(ma,mo,a,p){}
        double calcularCosto() const override{
            return precioBase*2.5;
        }
        string getTipo() const override{
            return "Camion";
        }
};

void ordenarPorCosto(Vehiculo* v[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j]->calcularCosto()<v[j+1]->calcularCosto()){
                Vehiculo* aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

int main(){
    Vehiculo* vehiculos[6];

    vehiculos[0]=new Auto("Toyota","Corolla",2022,20000);
    vehiculos[1]=new Moto("Yamaha","FZ",2021,5000);
    vehiculos[2]=new Camion("Volvo","FH",2019,40000);
    vehiculos[3]=new Auto("Kia","Rio",2018,15000);
    vehiculos[4]=new Moto("Honda","CBR",2023,8000);
    vehiculos[5]=new Camion("Mercedes","Actros",2020,45000);

    double total=0;

    cout<<fixed<<setprecision(2);

    ordenarPorCosto(vehiculos,6);

    cout<<"=== Vehiculos ordenados por costo ==="<<endl;

    for(int i=0;i<6;i++){
        vehiculos[i]->imprimir();
        total=total+vehiculos[i]->calcularCosto();
    }

    cout<<"Costo total de flota: $"<<total<<endl;

    for(int i=0;i<6;i++){
        delete vehiculos[i];
    }
}
