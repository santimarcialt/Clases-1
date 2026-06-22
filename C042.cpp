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
        virtual ~Figura(){}
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
    Figura* figuras[5];

    figuras[0]=new Circulo(5.0,"rojo");
    figuras[1]=new Rectangulo(6.0,4.0,"azul");
    figuras[2]=new Triangulo(3.0,4.0,"verde");
    figuras[3]=new Circulo(2.0,"amarillo");
    figuras[4]=new Rectangulo(5.0,3.0,"negro");

    double areaTotal=0;

    cout<<fixed<<setprecision(2);

    for(int i=0;i<5;i++){
        figuras[i]->imprimir();
        areaTotal=areaTotal+figuras[i]->calcularArea();
    }

    cout<<"Area total: "<<areaTotal<<endl;

    for(int i=0;i<5;i++){
        delete figuras[i];
    }
}
