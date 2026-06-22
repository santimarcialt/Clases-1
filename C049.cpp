#include<iostream>
#include<iomanip>
using namespace std;

class Figura{
    protected:
        string color;
    public:
        Figura(string c){
            color=c;
        }
        virtual double calcularArea() const=0;
        virtual void imprimir() const=0;
        virtual ~Figura(){}
};

class Circulo:public Figura{
    private:
        double radio;
    public:
        Circulo(double r,string c):Figura(c){
            radio=r;
        }
        double calcularArea() const override{
            double PI=3.14159;
            return PI*radio*radio;
        }
        void imprimir() const override{
            cout<<"Circulo (r="<<radio<<"): Area="<<calcularArea()<<endl;
        }
};

class Rectangulo:public Figura{
    private:
        double base,altura;
    public:
        Rectangulo(double b,double h,string c):Figura(c){
            base=b;
            altura=h;
        }
        double calcularArea() const override{
            return base*altura;
        }
        void imprimir() const override{
            cout<<"Rect("<<base<<"x"<<altura<<"): Area="<<calcularArea()<<endl;
        }
};

Figura* crearFigura(string tipo,double a,double b){
    if(tipo=="circulo"){
        return new Circulo(a,"rojo");
    }
    else if(tipo=="rectangulo"){
        return new Rectangulo(a,b,"azul");
    }
    else{
        return nullptr;
    }
}

int main(){
    string tipo1,tipo2;
    double a1,b1,a2,b2;

    cin>>tipo1>>a1>>b1;
    cin>>tipo2>>a2>>b2;

    Figura* f1=crearFigura(tipo1,a1,b1);
    Figura* f2=crearFigura(tipo2,a2,b2);

    cout<<fixed<<setprecision(2);

    if(f1!=nullptr){
        f1->imprimir();
    }
    if(f2!=nullptr){
        f2->imprimir();
    }

    delete f1;
    delete f2;
}
