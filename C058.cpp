#include<iostream>
using namespace std;

class Personaje{
    private:
        string nombre;
        int vida,ataque,defensa,nivel;
    protected:
        void setVida(int v){
            if(v<0){
                vida=0;
            }
            else{
                vida=v;
            }
        }
    public:
        Personaje(string n,int v,int a,int d,int nv){
            nombre=n;
            vida=v;
            ataque=a;
            defensa=d;
            nivel=nv;
        }
        string getNombre() const{
            return nombre;
        }
        int getVida() const{
            return vida;
        }
        int getAtaque() const{
            return ataque;
        }
        int getDefensa() const{
            return defensa;
        }
        int getNivel() const{
            return nivel;
        }
        virtual string getClase() const=0;
        virtual int habilidadEspecial()=0;
        virtual void recibirDano(int dano){
            int danoReal=dano-defensa;
            if(danoReal<0){
                danoReal=0;
            }
            setVida(vida-danoReal);
        }
        bool estaVivo() const{
            return vida>0;
        }
        virtual void imprimir() const{
            cout<<nombre<<" | "<<getClase()<<" | Vida: "<<vida<<" | Ataque: "<<ataque<<" | Defensa: "<<defensa<<" | Nivel: "<<nivel<<endl;
        }
        virtual ~Personaje(){}
};

class Guerrero:public Personaje{
    public:
        Guerrero(string n,int v,int a,int d,int nv):Personaje(n,v,a,d,nv){}
        string getClase() const override{
            return "Guerrero";
        }
        int habilidadEspecial() override{
            return getAtaque()*2;
        }
};

class Mago:public Personaje{
    public:
        Mago(string n,int v,int a,int d,int nv):Personaje(n,v,a,d,nv){}
        string getClase() const override{
            return "Mago";
        }
        int habilidadEspecial() override{
            return getAtaque()*3;
        }
};

class Arquero:public Personaje{
    public:
        Arquero(string n,int v,int a,int d,int nv):Personaje(n,v,a,d,nv){}
        string getClase() const override{
            return "Arquero";
        }
        int habilidadEspecial() override{
            return getAtaque()*1.5;
        }
};

class Paladin:public Guerrero{
    public:
        Paladin(string n,int v,int a,int d,int nv):Guerrero(n,v,a,d,nv){}
        string getClase() const override{
            return "Paladin";
        }
        int habilidadEspecial() override{
            setVida(getVida()+20);
            return getAtaque()*2;
        }
};

void combatir(Personaje& p1,Personaje& p2){
    cout<<"=== Combate: "<<p1.getNombre()<<" vs "<<p2.getNombre()<<" ==="<<endl;
    while(p1.estaVivo()&&p2.estaVivo()){
        int dano1=p1.habilidadEspecial();
        p2.recibirDano(dano1);
        cout<<p1.getNombre()<<" ataca con "<<dano1<<" de dano."<<endl;

        if(p2.estaVivo()){
            int dano2=p2.habilidadEspecial();
            p1.recibirDano(dano2);
            cout<<p2.getNombre()<<" ataca con "<<dano2<<" de dano."<<endl;
        }

        p1.imprimir();
        p2.imprimir();
        cout<<endl;
    }

    if(p1.estaVivo()){
        cout<<"Ganador: "<<p1.getNombre()<<endl;
    }
    else{
        cout<<"Ganador: "<<p2.getNombre()<<endl;
    }
}

void torneo(Personaje* participantes[],int n){
    cout<<"=== Torneo ==="<<endl;
    for(int i=0;i<n;i++){
        participantes[i]->imprimir();
    }
    cout<<endl;

    for(int i=0;i<n-1;i=i+2){
        combatir(*participantes[i],*participantes[i+1]);
        cout<<endl;
    }
}

int main(){
    Personaje* participantes[4];

    participantes[0]=new Guerrero("Ragnar",120,25,8,5);
    participantes[1]=new Mago("Merlin",90,30,5,6);
    participantes[2]=new Arquero("Legolas",100,22,6,5);
    participantes[3]=new Paladin("Arthur",130,24,10,7);

    torneo(participantes,4);

    for(int i=0;i<4;i++){
        delete participantes[i];
    }
}
