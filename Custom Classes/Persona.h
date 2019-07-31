#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class Persona
{
private:
    

public:
    string nombre;
    int edad;
    Persona(){
        this->nombre = "";
        this->edad = 0;
    }
    Persona(string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
    }
    static Persona transform(char* buffer){
        string temp = buffer;
        const string delim = "-";
        size_t pos = temp.find(delim);
        string nombre = temp.substr(0, pos);
        string ed = temp.substr(pos + delim.length());
        int edad = stoi(ed);
        Persona p(nombre, edad);
        return p;
    }

    static void toString(Persona p, char* dest){
        string str =  p.nombre+"-"+to_string(p.edad);
        strcpy(dest, str.c_str());
    }

    Persona* operator= (const Persona *a){
        if(a == NULL) return NULL;
        return new Persona(a->nombre, a->edad);
    }

    friend bool operator==(const Persona &a, const Persona &b){
        if(a.nombre == b.nombre && a.edad == b.edad){
            return true;
        }
        else{
            return false;
        }
    }

    friend bool operator!=(const Persona &a, const Persona &b){
        if(a.nombre != b.nombre && a.edad != b.edad){
            return true;
        }
        else{
            return false;
        }
    }

    friend ostream & operator << (ostream &salida, Persona A){
        salida << "Nombre: "<< A.nombre<<
        " Edad: "<< A.edad<<endl;
        return salida;
    }
};
