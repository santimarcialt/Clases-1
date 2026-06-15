#include<iostream>
#include<iomanip>
using namespace std;

class Rectangulo{
    private:
        double base;
        double altura;

    public:
        Rectangulo(double base,double altura){
            this->base=0;
            this->altura=0;
            setBase(base);
            setAltura(altura);
        }

        void setBase(double base){
            if(base>0){
                this->base=base;
            }else{
                cout<<"Base debe ser positiva."<<endl;
            }
        }

        void setAltura(double altura){
            if(altura>0){
                this->altura=altura;
            }else{
                cout<<"Altura debe ser positiva."<<endl;
            }
        }

        double getBase() const{
            return base;
        }

        double getAltura() const{
            return altura;
        }

        double calcularArea() const{
            return base*altura;
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"Base: "<<base<<", Altura: "<<altura<<", Area: "<<calcularArea()<<endl;
        }
};

int main(){
    Rectangulo r1(5.0,3.0);

    r1.imprimir();

    r1.setBase(-2.0);
    r1.imprimir();

    r1.setBase(8.0);
    r1.imprimir();

    return 0;
}
