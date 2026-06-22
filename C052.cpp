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
        virtual string getTipo() const=0;
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
        string getTipo() const override{
            return "Circulo";
        }
        void imprimir() const override{
            cout<<"Circulo "<<color<<" | Radio: "<<radio<<" | Area: "<<calcularArea()<<endl;
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
        string getTipo() const override{
            return "Rectangulo";
        }
        void imprimir() const override{
            cout<<"Rectangulo "<<color<<" | "<<base<<"x"<<altura<<" | Area: "<<calcularArea()<<endl;
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
        string getTipo() const override{
            return "Triangulo";
        }
        void imprimir() const override{
            cout<<"Triangulo "<<color<<" | Base: "<<base<<" Altura: "<<altura<<" | Area: "<<calcularArea()<<endl;
        }
};

class Cuadrado:public Figura{
    private:
        double lado;
    public:
        Cuadrado(double l,string c):Figura(c){
            lado=l;
        }
        double calcularArea() const override{
            return lado*lado;
        }
        string getTipo() const override{
            return "Cuadrado";
        }
        void imprimir() const override{
            cout<<"Cuadrado "<<color<<" | Lado: "<<lado<<" | Area: "<<calcularArea()<<endl;
        }
};

class Rombo:public Figura{
    private:
        double d1,d2;
    public:
        Rombo(double diagonal1,double diagonal2,string c):Figura(c){
            d1=diagonal1;
            d2=diagonal2;
        }
        double calcularArea() const override{
            return (d1*d2)/2;
        }
        string getTipo() const override{
            return "Rombo";
        }
        void imprimir() const override{
            cout<<"Rombo "<<color<<" | D1: "<<d1<<" D2: "<<d2<<" | Area: "<<calcularArea()<<endl;
        }
};

class Lienzo{
    private:
        Figura* figuras[50];
        int cantidad;
    public:
        Lienzo(){
            cantidad=0;
        }
        void agregar(Figura* f){
            if(cantidad<50){
                figuras[cantidad]=f;
                cantidad++;
            }
        }
        double areaTotalCanvas() const{
            double total=0;
            for(int i=0;i<cantidad;i++){
                total=total+figuras[i]->calcularArea();
            }
            return total;
        }
        double areaPromedio() const{
            if(cantidad==0){
                return 0;
            }
            return areaTotalCanvas()/cantidad;
        }
        Figura* figuraMayor() const{
            if(cantidad==0){
                return nullptr;
            }
            int posMayor=0;
            for(int i=1;i<cantidad;i++){
                if(figuras[i]->calcularArea()>figuras[posMayor]->calcularArea()){
                    posMayor=i;
                }
            }
            return figuras[posMayor];
        }
        Figura* figuraMenor() const{
            if(cantidad==0){
                return nullptr;
            }
            int posMenor=0;
            for(int i=1;i<cantidad;i++){
                if(figuras[i]->calcularArea()<figuras[posMenor]->calcularArea()){
                    posMenor=i;
                }
            }
            return figuras[posMenor];
        }
        void imprimirTodas() const{
            cout<<"=== Figuras del lienzo ==="<<endl;
            for(int i=0;i<cantidad;i++){
                figuras[i]->imprimir();
            }
        }
        ~Lienzo(){
            for(int i=0;i<cantidad;i++){
                delete figuras[i];
            }
        }
};

int main(){
    Lienzo lienzo;

    lienzo.agregar(new Circulo(5.0,"rojo"));
    lienzo.agregar(new Rectangulo(6.0,4.0,"azul"));
    lienzo.agregar(new Triangulo(3.0,4.0,"verde"));
    lienzo.agregar(new Cuadrado(5.0,"amarillo"));
    lienzo.agregar(new Rombo(6.0,8.0,"morado"));
    lienzo.agregar(new Circulo(2.0,"negro"));
    lienzo.agregar(new Rectangulo(10.0,2.0,"blanco"));
    lienzo.agregar(new Triangulo(8.0,5.0,"naranja"));

    cout<<fixed<<setprecision(2);

    lienzo.imprimirTodas();

    cout<<endl;
    cout<<"Area total: "<<lienzo.areaTotalCanvas()<<endl;
    cout<<"Area promedio: "<<lienzo.areaPromedio()<<endl;

    cout<<endl;
    cout<<"Figura de mayor area:"<<endl;
    lienzo.figuraMayor()->imprimir();

    cout<<endl;
    cout<<"Figura de menor area:"<<endl;
    lienzo.figuraMenor()->imprimir();
}
