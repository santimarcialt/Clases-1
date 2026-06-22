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
        virtual double calcularArea()=0;
        virtual double calcularPerimetro()=0;
        virtual void imprimir() const=0;
};

class Circulo:public Figura{
    private:
        double radio;
    public:
        Circulo(double r,string c):Figura(c){
            radio=r;
        }
        double calcularArea() override{
            double PI=3.14159;
            return PI*radio*radio;
        }
        double calcularPerimetro() override{
            double PI=3.14159;
            return 2*PI*radio;
        }
        void imprimir() const override{
            double PI=3.14159;
            cout<<"Circulo "<<color<<" | Radio: "<<radio<<" | Area: "<<PI*radio*radio<<" | Perim: "<<2*PI*radio<<endl;
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
        double calcularArea() override{
            return base*altura;
        }
        double calcularPerimetro() override{
            return 2*(base+altura);
        }
        void imprimir() const override{
            cout<<"Rectangulo "<<color<<" | "<<base<<"x"<<altura<<" | Area: "<<base*altura<<" | Perim: "<<2*(base+altura)<<endl;
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
        double calcularArea() override{
            return (base*altura)/2;
        }
        double calcularPerimetro() override{
            return 0;
        }
        void imprimir() const override{
            cout<<"Triangulo "<<color<<" | Base: "<<base<<" Altura: "<<altura<<" | Area: "<<(base*altura)/2<<endl;
        }
};

int main(){
    Circulo c(5.0,"rojo");
    Rectangulo r(6,4,"azul");
    Triangulo t(3,4,"verde");

    cout<<fixed<<setprecision(2);

    c.imprimir();
    r.imprimir();
    t.imprimir();
}
