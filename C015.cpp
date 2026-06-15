#include<iostream>
#include<string>
using namespace std;

class Recurso{
    public:
        string nombre;

        Recurso(string n){
            nombre=n;
            cout<<nombre<<" creado."<<endl;
        }

        ~Recurso(){
            cout<<nombre<<" destruido."<<endl;
        }
};

int main(){
    Recurso r1("A");

    {
        Recurso r2("B");

        {
            Recurso r3("C");
        }
    }

    return 0;
}
