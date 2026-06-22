#include<iostream>
#include<iomanip>
using namespace std;

class Transporte{
    protected:
        string origen,destino;
        int capacidadPasajeros;
    public:
        Transporte(string o,string d,int c){
            origen=o;
            destino=d;
            capacidadPasajeros=c;
        }
        virtual double calcularTarifa(double distanciaKm) const=0;
        virtual double tiempoEstimado(double distanciaKm) const=0;
        virtual string getTipo() const=0;
        virtual void imprimir(double distanciaKm) const{
            cout<<getTipo()<<" | "<<origen<<" -> "<<destino<<" | Capacidad: "<<capacidadPasajeros<<" | Distancia: "<<distanciaKm<<" km | Tarifa: $"<<calcularTarifa(distanciaKm)<<" | Tiempo: "<<tiempoEstimado(distanciaKm)<<" h"<<endl;
        }
        virtual ~Transporte(){}
};

class TransporteTerrestre:public Transporte{
    protected:
        double velocidadPromedio,costoPorKm;
    public:
        TransporteTerrestre(string o,string d,int c,double v,double costo):Transporte(o,d,c){
            velocidadPromedio=v;
            costoPorKm=costo;
        }
};

class TransporteAereo:public Transporte{
    protected:
        double costoBase,tasaAeropuerto;
    public:
        TransporteAereo(string o,string d,int c,double base,double tasa):Transporte(o,d,c){
            costoBase=base;
            tasaAeropuerto=tasa;
        }
};

class Bus:public TransporteTerrestre{
    public:
        Bus(string o,string d,int c,double v,double costo):TransporteTerrestre(o,d,c,v,costo){}
        double calcularTarifa(double distanciaKm) const override{
            return distanciaKm*costoPorKm;
        }
        double tiempoEstimado(double distanciaKm) const override{
            return distanciaKm/velocidadPromedio;
        }
        string getTipo() const override{
            return "Bus";
        }
};

class Taxi:public TransporteTerrestre{
    public:
        Taxi(string o,string d,int c,double v,double costo):TransporteTerrestre(o,d,c,v,costo){}
        double calcularTarifa(double distanciaKm) const override{
            return 3.00+(distanciaKm*costoPorKm);
        }
        double tiempoEstimado(double distanciaKm) const override{
            return distanciaKm/velocidadPromedio;
        }
        string getTipo() const override{
            return "Taxi";
        }
};

class Avion:public TransporteAereo{
    public:
        Avion(string o,string d,int c,double base,double tasa):TransporteAereo(o,d,c,base,tasa){}
        double calcularTarifa(double distanciaKm) const override{
            return costoBase+(distanciaKm*0.45)+tasaAeropuerto;
        }
        double tiempoEstimado(double distanciaKm) const override{
            return distanciaKm/750.0;
        }
        string getTipo() const override{
            return "Avion";
        }
};

class Helicoptero:public TransporteAereo{
    public:
        Helicoptero(string o,string d,int c,double base,double tasa):TransporteAereo(o,d,c,base,tasa){}
        double calcularTarifa(double distanciaKm) const override{
            return costoBase+(distanciaKm*1.20)+tasaAeropuerto;
        }
        double tiempoEstimado(double distanciaKm) const override{
            return distanciaKm/220.0;
        }
        string getTipo() const override{
            return "Helicoptero";
        }
};

class Reserva{
    private:
        Transporte* transporte;
        string pasajero,fecha;
        double distancia;
    public:
        Reserva(Transporte* t,string p,string f,double d){
            transporte=t;
            pasajero=p;
            fecha=f;
            distancia=d;
        }
        double calcularCosto() const{
            return transporte->calcularTarifa(distancia);
        }
        void imprimir() const{
            cout<<"Pasajero: "<<pasajero<<" | Fecha: "<<fecha<<" | Costo: $"<<calcularCosto()<<endl;
            transporte->imprimir(distancia);
        }
};

class GestorReservas{
    private:
        Reserva* reservas[100];
        int cantidad;
    public:
        GestorReservas(){
            cantidad=0;
        }
        void agregarReserva(Reserva* r){
            if(cantidad<100){
                reservas[cantidad]=r;
                cantidad++;
            }
        }
        double totalReservas() const{
            double total=0;
            for(int i=0;i<cantidad;i++){
                total=total+reservas[i]->calcularCosto();
            }
            return total;
        }
        void imprimirReservas() const{
            cout<<"=== Reservas de transporte ==="<<endl;
            for(int i=0;i<cantidad;i++){
                reservas[i]->imprimir();
                cout<<endl;
            }
            cout<<"Total reservas: $"<<totalReservas()<<endl;
        }
        ~GestorReservas(){
            for(int i=0;i<cantidad;i++){
                delete reservas[i];
            }
        }
};

int main(){
    GestorReservas gestor;

    Transporte* t1=new Bus("Quito","Latacunga",40,70,0.15);
    Transporte* t2=new Taxi("Centro","Aeropuerto",4,50,0.80);
    Transporte* t3=new Avion("Quito","Guayaquil",180,60,25);
    Transporte* t4=new Helicoptero("Quito","Mindo",5,120,40);

    gestor.agregarReserva(new Reserva(t1,"Ana","2026-06-20",90));
    gestor.agregarReserva(new Reserva(t2,"Luis","2026-06-21",35));
    gestor.agregarReserva(new Reserva(t3,"Carla","2026-06-22",270));
    gestor.agregarReserva(new Reserva(t4,"Pedro","2026-06-23",80));

    cout<<fixed<<setprecision(2);

    gestor.imprimirReservas();

    delete t1;
    delete t2;
    delete t3;
    delete t4;
}
