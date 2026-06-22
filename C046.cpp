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
        virtual double calcularPerimetro() const=0;
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
        double calcularPerimetro() const override{
            double PI=3.14159;
            return 2*PI*radio;
        }
        void imprimir() const override{
            cout<<"Circulo "<<color<<" | Radio: "<<radio<<" | Area: "<<calcularArea()<<" | Perim: "<<calcularPerimetro()<<endl;
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
        double calcularPerimetro() const override{
            return 2*(base+altura);
        }
        void imprimir() const override{
            cout<<"Rectangulo "<<color<<" | "<<base<<"x"<<altura<<" | Area: "<<calcularArea()<<" | Perim: "<<calcularPerimetro()<<endl;
        }
};

class Triangulo:public Figura{
    private:
        double base,altura;
    public:
        Triangulo(double b,double h,string c):Figura(c){
            base=b;
            altura=h;
        }
        double calcularArea() const override{
            return (base*altura)/2;
        }
        double calcularPerimetro() const override{
            return 0;
        }
        void imprimir() const override{
            cout<<"Triangulo "<<color<<" | Base: "<<base<<" Altura: "<<altura<<" | Area: "<<calcularArea()<<endl;
        }
};

void describir(const Figura& f){
    f.imprimir();
    cout<<"Area calculada desde describir: "<<f.calcularArea()<<endl;
}

int main(){
    Circulo c(5.0,"rojo");
    Rectangulo r(6.0,4.0,"azul");
    Triangulo t(3.0,4.0,"verde");

    cout<<fixed<<setprecision(2);

    describir(c);
    describir(r);
    describir(t);
}
