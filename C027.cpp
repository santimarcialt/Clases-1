#include<iostream>
#include<iomanip>
using namespace std;

class Vector2D{
    private:
        double x;
        double y;

    public:
        Vector2D(double x,double y){
            this->x=x;
            this->y=y;
        }

        void setX(double x){
            this->x=x;
        }

        void setY(double y){
            this->y=y;
        }

        double getX() const{
            return x;
        }

        double getY() const{
            return y;
        }

        void imprimir() const{
            cout<<fixed<<setprecision(2);
            cout<<"("<<x<<", "<<y<<")";
        }
};

int main(){
    Vector2D original(3.0,4.0);

    Vector2D copia=original;

    cout<<"Original: ";
    original.imprimir();
    cout<<endl;

    cout<<"Copia: ";
    copia.imprimir();
    cout<<endl<<endl;

    copia.setX(10.0);
    copia.setY(20.0);

    cout<<"Original: ";
    original.imprimir();
    cout<<" no cambia"<<endl;

    cout<<"Copia: ";
    copia.imprimir();
    cout<<" si cambia"<<endl;

    return 0;
}
