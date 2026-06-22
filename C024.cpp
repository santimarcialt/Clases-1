#include <iostream>
using namespace std;

class Empleado {
private:
    string nombre;
    double salario;
    int edad;
    string contrasena;

public:
    void setNombre(string n) {
        nombre = n;
    }

    string getNombre() const {
        return nombre;
    }

    void setSalario(double s) {
        if (s >= 0) {
            salario = s;
        } else {
            salario = 0;
        }
    }

    double getSalario() const {
        return salario;
    }

    void setEdad(int e) {
        if (e >= 18) {
            edad = e;
        } else {
            edad = 18;
        }
    }

    int getEdad() const {
        return edad;
    }

    void setContrasena(string c) {
        if (c.length() >= 8) {
            contrasena = c;
        }
    }
};
