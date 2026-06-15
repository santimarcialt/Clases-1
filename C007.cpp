#include<iostream>
#include<iomanip>
using namespace std;

class Temperatura{
    public:
        double celsius;

        double getCelsius();
        double getFahrenheit();
        double getKelvin();
        void imprimir();
};

double Temperatura::getCelsius(){
    return celsius;
}

double Temperatura::getFahrenheit(){
    return celsius*9/5+32;
}

double Temperatura::getKelvin(){
    return celsius+273.15;
}

void Temperatura::imprimir(){
    cout<<fixed<<setprecision(2);
    cout<<"Celsius: "<<getCelsius()<<endl<<endl;
    cout<<"Fahrenheit: "<<getFahrenheit()<<endl<<endl;
    cout<<"Kelvin: "<<getKelvin()<<endl;
}

int main(){
    Temperatura t1;

    t1.celsius=100.0;

    t1.imprimir();

    return 0;
}
