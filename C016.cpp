#include<iostream>
#include<iomanip>
using namespace std;

class Fecha{
    public:
        int dia;
        int mes;
        int ano;

        Fecha(){
            dia=1;
            mes=1;
            ano=2000;
        }

        Fecha(int d,int m,int a){
            dia=d;
            mes=m;
            ano=a;
        }

        Fecha(int d,int m){
            dia=d;
            mes=m;
            ano=2024;
        }

        void imprimir(){
            cout<<setfill('0')<<setw(2)<<dia<<"/";
            cout<<setfill('0')<<setw(2)<<mes<<"/";
            cout<<setfill('0')<<setw(4)<<ano<<endl;
        }
};

int main(){
    Fecha f1;
    Fecha f2(15,6,1999);
    Fecha f3(22,3);

    f1.imprimir();
    f2.imprimir();
    f3.imprimir();

    return 0;
}
