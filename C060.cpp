#include<iostream>
#include<iomanip>
using namespace std;

class Patrimonio{
    private:
        string nombre,ubicacion;
        int siglo;
    public:
        Patrimonio(string n,string u,int s):nombre(n),ubicacion(u),siglo(s){}
        string getNombre() const{
            return nombre;
        }
        string getUbicacion() const{
            return ubicacion;
        }
        int getSiglo() const{
            return siglo;
        }
        virtual string getTipo() const=0;
        virtual double calcularValorCultural() const=0;
        virtual double calcularTiempoVisita() const=0;
        virtual void imprimir() const{
            cout<<getTipo()<<" | "<<nombre<<" | Ubicacion: "<<ubicacion<<" | Siglo: "<<siglo;
        }
        virtual ~Patrimonio(){}
};

class ObraArte:public Patrimonio{
    private:
        string autor,sala;
    public:
        ObraArte(string n,string u,int s,string a,string sa):Patrimonio(n,u,s),autor(a),sala(sa){}
        string getAutor() const{
            return autor;
        }
        string getSala() const{
            return sala;
        }
        virtual string getMaterialPrincipal() const=0;
        void imprimir() const override{
            Patrimonio::imprimir();
            cout<<" | Autor: "<<autor<<" | Sala: "<<sala;
        }
};

class Pintura:public ObraArte{
    private:
        double ancho,alto;
    public:
        Pintura(string n,string u,int s,string a,string sa,double an,double al):ObraArte(n,u,s,a,sa),ancho(an),alto(al){}
        string getTipo() const override{
            return "Pintura";
        }
        string getMaterialPrincipal() const override{
            return "Oleo";
        }
        double calcularValorCultural() const override{
            return (ancho*alto)*12+getSiglo()*1.5;
        }
        double calcularTiempoVisita() const override{
            return 18;
        }
        void imprimir() const override{
            ObraArte::imprimir();
            cout<<" | Material: "<<getMaterialPrincipal()<<" | Tamano: "<<ancho<<"x"<<alto<<" | Valor cultural: "<<calcularValorCultural()<<" | Tiempo: "<<calcularTiempoVisita()<<" min"<<endl;
        }
};

class Escultura:public ObraArte{
    private:
        double altura,peso;
    public:
        Escultura(string n,string u,int s,string a,string sa,double al,double p):ObraArte(n,u,s,a,sa),altura(al),peso(p){}
        string getTipo() const override{
            return "Escultura";
        }
        string getMaterialPrincipal() const override{
            return "Marmol";
        }
        double calcularValorCultural() const override{
            return altura*20+peso*0.8+getSiglo()*2;
        }
        double calcularTiempoVisita() const override{
            return 14;
        }
        void imprimir() const override{
            ObraArte::imprimir();
            cout<<" | Material: "<<getMaterialPrincipal()<<" | Altura: "<<altura<<"m | Peso: "<<peso<<"kg | Valor cultural: "<<calcularValorCultural()<<" | Tiempo: "<<calcularTiempoVisita()<<" min"<<endl;
        }
};

class ArtefactoHistorico:public ObraArte{
    private:
        string civilizacion;
        double rareza;
    public:
        ArtefactoHistorico(string n,string u,int s,string a,string sa,string c,double r):ObraArte(n,u,s,a,sa),civilizacion(c),rareza(r){}
        string getTipo() const override{
            return "Artefacto historico";
        }
        string getMaterialPrincipal() const override{
            return "Piedra";
        }
        double calcularValorCultural() const override{
            return rareza*100+getSiglo()*3;
        }
        double calcularTiempoVisita() const override{
            return 16;
        }
        void imprimir() const override{
            ObraArte::imprimir();
            cout<<" | Civilizacion: "<<civilizacion<<" | Material: "<<getMaterialPrincipal()<<" | Rareza: "<<rareza<<" | Valor cultural: "<<calcularValorCultural()<<" | Tiempo: "<<calcularTiempoVisita()<<" min"<<endl;
        }
};

class Manuscrito:public ObraArte{
    private:
        int paginas;
        string idioma;
    public:
        Manuscrito(string n,string u,int s,string a,string sa,int p,string i):ObraArte(n,u,s,a,sa),paginas(p),idioma(i){}
        string getTipo() const override{
            return "Manuscrito";
        }
        string getMaterialPrincipal() const override{
            return "Pergamino";
        }
        double calcularValorCultural() const override{
            return paginas*1.5+getSiglo()*2.5;
        }
        double calcularTiempoVisita() const override{
            return 10;
        }
        void imprimir() const override{
            ObraArte::imprimir();
            cout<<" | Idioma: "<<idioma<<" | Paginas: "<<paginas<<" | Material: "<<getMaterialPrincipal()<<" | Valor cultural: "<<calcularValorCultural()<<" | Tiempo: "<<calcularTiempoVisita()<<" min"<<endl;
        }
};

class JoyaReal:public ObraArte{
    private:
        double quilates;
        string metal;
    public:
        JoyaReal(string n,string u,int s,string a,string sa,double q,string m):ObraArte(n,u,s,a,sa),quilates(q),metal(m){}
        string getTipo() const override{
            return "Joya real";
        }
        string getMaterialPrincipal() const override{
            return metal;
        }
        double calcularValorCultural() const override{
            return quilates*30+getSiglo()*4;
        }
        double calcularTiempoVisita() const override{
            return 12;
        }
        void imprimir() const override{
            ObraArte::imprimir();
            cout<<" | Metal: "<<metal<<" | Quilates: "<<quilates<<" | Valor cultural: "<<calcularValorCultural()<<" | Tiempo: "<<calcularTiempoVisita()<<" min"<<endl;
        }
};

class Visitante{
    private:
        string nombre,tipoEntrada;
        int edad;
    public:
        Visitante(string n,int e,string t):nombre(n),edad(e),tipoEntrada(t){}
        string getNombre() const{
            return nombre;
        }
        int getEdad() const{
            return edad;
        }
        string getTipoEntrada() const{
            return tipoEntrada;
        }
        double calcularTarifa() const{
            if(edad<18){
                return 0;
            }
            else if(tipoEntrada=="estudiante"){
                return 10;
            }
            else{
                return 17;
            }
        }
        void imprimir() const{
            cout<<"Visitante: "<<nombre<<" | Edad: "<<edad<<" | Entrada: "<<tipoEntrada<<" | Tarifa: "<<calcularTarifa()<<endl;
        }
};

class Recorrido{
    private:
        string nombreGuia;
        Patrimonio* piezas[20];
        int cantidad;
    public:
        Recorrido(string g):nombreGuia(g),cantidad(0){}
        void agregarPieza(Patrimonio* p){
            if(cantidad<20){
                piezas[cantidad]=p;
                cantidad++;
            }
        }
        double tiempoTotal() const{
            double total=0;
            for(int i=0;i<cantidad;i++){
                total=total+piezas[i]->calcularTiempoVisita();
            }
            return total;
        }
        void imprimirRecorrido() const{
            cout<<"=== Recorrido guiado por "<<nombreGuia<<" ==="<<endl;
            for(int i=0;i<cantidad;i++){
                cout<<i+1<<". "<<piezas[i]->getNombre()<<" | "<<piezas[i]->getTipo()<<" | Tiempo: "<<piezas[i]->calcularTiempoVisita()<<" min"<<endl;
            }
            cout<<"Tiempo total del recorrido: "<<tiempoTotal()<<" min"<<endl;
        }
};

class MuseoLouvre{
    private:
        Patrimonio* catalogo[100];
        Visitante* visitantes[100];
        int cantidadPiezas,cantidadVisitantes;
    public:
        MuseoLouvre():cantidadPiezas(0),cantidadVisitantes(0){}
        void agregarPieza(Patrimonio* p){
            if(cantidadPiezas<100){
                catalogo[cantidadPiezas]=p;
                cantidadPiezas++;
            }
        }
        void agregarVisitante(Visitante* v){
            if(cantidadVisitantes<100){
                visitantes[cantidadVisitantes]=v;
                cantidadVisitantes++;
            }
        }
        void imprimirCatalogo() const{
            cout<<"=== Catalogo del Museo del Louvre ==="<<endl;
            for(int i=0;i<cantidadPiezas;i++){
                catalogo[i]->imprimir();
            }
        }
        double valorCulturalTotal() const{
            double total=0;
            for(int i=0;i<cantidadPiezas;i++){
                total=total+catalogo[i]->calcularValorCultural();
            }
            return total;
        }
        Patrimonio* piezaMayorValor() const{
            if(cantidadPiezas==0){
                return nullptr;
            }
            int pos=0;
            for(int i=1;i<cantidadPiezas;i++){
                if(catalogo[i]->calcularValorCultural()>catalogo[pos]->calcularValorCultural()){
                    pos=i;
                }
            }
            return catalogo[pos];
        }
        Patrimonio* buscarPieza(string nombre) const{
            for(int i=0;i<cantidadPiezas;i++){
                if(catalogo[i]->getNombre()==nombre){
                    return catalogo[i];
                }
            }
            return nullptr;
        }
        void imprimirVisitantes() const{
            cout<<"=== Visitantes ==="<<endl;
            for(int i=0;i<cantidadVisitantes;i++){
                visitantes[i]->imprimir();
            }
        }
        double ingresosEntradas() const{
            double total=0;
            for(int i=0;i<cantidadVisitantes;i++){
                total=total+visitantes[i]->calcularTarifa();
            }
            return total;
        }
        Patrimonio* getPieza(int pos) const{
            if(pos>=0&&pos<cantidadPiezas){
                return catalogo[pos];
            }
            return nullptr;
        }
        ~MuseoLouvre(){
            for(int i=0;i<cantidadPiezas;i++){
                delete catalogo[i];
            }
            for(int i=0;i<cantidadVisitantes;i++){
                delete visitantes[i];
            }
        }
};

void describirObra(const Patrimonio& p){
    cout<<"Descripcion polimorfica:"<<endl;
    p.imprimir();
}

void compararObras(const Patrimonio& a,const Patrimonio& b){
    cout<<"=== Comparacion de obras ==="<<endl;
    cout<<a.getNombre()<<" -> "<<a.calcularValorCultural()<<endl;
    cout<<b.getNombre()<<" -> "<<b.calcularValorCultural()<<endl;
    if(a.calcularValorCultural()>b.calcularValorCultural()){
        cout<<"Mayor valor cultural: "<<a.getNombre()<<endl;
    }
    else{
        cout<<"Mayor valor cultural: "<<b.getNombre()<<endl;
    }
}

int main(){
    MuseoLouvre museo;

    museo.agregarPieza(new Pintura("Mona Lisa","Ala Denon",16,"Leonardo da Vinci","Sala 711",0.77,0.53));
    museo.agregarPieza(new Escultura("Venus de Milo","Ala Sully",-2,"Desconocido","Sala 345",2.04,900));
    museo.agregarPieza(new Escultura("Victoria de Samotracia","Ala Denon",-2,"Desconocido","Escalera Daru",2.75,1200));
    museo.agregarPieza(new ArtefactoHistorico("Codigo de Hammurabi","Ala Richelieu",-18,"Desconocido","Sala 227","Babilonica",9.8));
    museo.agregarPieza(new ArtefactoHistorico("Esfinge de Tanis","Ala Sully",-26,"Desconocido","Sala 338","Egipcia",8.7));
    museo.agregarPieza(new Manuscrito("Libro de Horas","Ala Richelieu",15,"Copistas medievales","Sala 505",220,"Latin"));
    museo.agregarPieza(new JoyaReal("Corona de Luis XV","Ala Richelieu",18,"Taller real","Galeria de Apolo",282.0,"Oro"));
    museo.agregarPieza(new Pintura("La Libertad guiando al pueblo","Ala Denon",19,"Eugene Delacroix","Sala 700",3.25,2.60));

    museo.agregarVisitante(new Visitante("Ana",16,"estudiante"));
    museo.agregarVisitante(new Visitante("Luis",20,"estudiante"));
    museo.agregarVisitante(new Visitante("Carla",35,"general"));
    museo.agregarVisitante(new Visitante("Pedro",12,"general"));

    cout<<fixed<<setprecision(2);

    museo.imprimirCatalogo();
    cout<<endl;

    museo.imprimirVisitantes();
    cout<<"Ingresos por entradas: "<<museo.ingresosEntradas()<<endl;
    cout<<endl;

    cout<<"Valor cultural total del museo: "<<museo.valorCulturalTotal()<<endl;
    cout<<endl;

    cout<<"=== Obra con mayor valor cultural ==="<<endl;
    Patrimonio* mayor=museo.piezaMayorValor();
    if(mayor!=nullptr){
        mayor->imprimir();
    }
    cout<<endl;

    cout<<"=== Busqueda ==="<<endl;
    Patrimonio* encontrada=museo.buscarPieza("Mona Lisa");
    if(encontrada!=nullptr){
        encontrada->imprimir();
    }
    else{
        cout<<"Obra no encontrada."<<endl;
    }
    cout<<endl;

    describirObra(*museo.getPieza(1));
    cout<<endl;

    compararObras(*museo.getPieza(0),*museo.getPieza(3));
    cout<<endl;

    Recorrido recorrido("Claire");
    recorrido.agregarPieza(museo.getPieza(0));
    recorrido.agregarPieza(museo.getPieza(2));
    recorrido.agregarPieza(museo.getPieza(3));
    recorrido.agregarPieza(museo.getPieza(6));
    recorrido.imprimirRecorrido();
}
