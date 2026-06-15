#include<iostream>
using namespace std;

class Volador{
    public:
        virtual void volar(){
            cout<<"Volando..."<<endl;
        }
};

class Nadador{
    public:
        virtual void nadar(){
            cout<<"Nadando..."<<endl;
        }
};

class Pato:public Volador,public Nadador{
    private:
        string nombre;

    public:
        Pato(string nombre){
            this->nombre=nombre;
        }

        void volar() override{
            cout<<nombre<<" vuela: Fiu fiu!"<<endl;
        }

        void nadar() override{
            cout<<nombre<<" nada: Splash!"<<endl;
        }
};

class Cisne:public Volador,public Nadador{
    private:
        string nombre;

    public:
        Cisne(string nombre){
            this->nombre=nombre;
        }

        void volar() override{
            cout<<nombre<<" vuela: Aleteo elegante."<<endl;
        }

        void nadar() override{
            cout<<nombre<<" nada: Deslizamiento suave."<<endl;
        }
};

int main(){
    Pato p1("Donald");
    Cisne c1("Odette");

    p1.volar();
    p1.nadar();

    c1.volar();
    c1.nadar();

    return 0;
}
