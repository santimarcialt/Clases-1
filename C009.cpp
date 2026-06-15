#include<iostream>
#include<iomanip>
using namespace std;

class Matematica{
    public:
        static int maximo(int a,int b){
            if(a>b){
                return a;
            }else{
                return b;
            }
        }

        static int minimo(int a,int b){
            if(a<b){
                return a;
            }else{
                return b;
            }
        }

        static bool esPrimo(int n){
            if(n<=1){
                return false;
            }

            for(int i=2;i<n;i++){
                if(n%i==0){
                    return false;
                }
            }

            return true;
        }

        static double potencia(double base,int exp){
            double resultado=1;

            for(int i=1;i<=exp;i++){
                resultado*=base;
            }

            return resultado;
        }
};

int main(){
    cout<<"Maximo(8, 3): "<<Matematica::maximo(8,3)<<endl;
    cout<<"Minimo(8, 3): "<<Matematica::minimo(8,3)<<endl;

    if(Matematica::esPrimo(7)){
        cout<<"Es primo 7: SI"<<endl;
    }else{
        cout<<"Es primo 7: NO"<<endl;
    }

    if(Matematica::esPrimo(9)){
        cout<<"Es primo 9: SI"<<endl;
    }else{
        cout<<"Es primo 9: NO"<<endl;
    }

    cout<<fixed<<setprecision(2);
    cout<<"2 elevado a 10: "<<Matematica::potencia(2,10)<<endl;

    return 0;
}
