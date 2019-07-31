#include <string.h>
using namespace std;
#define max_l 150

class Str {

    char cadena[max_l];

    private:
    void setWord(char *pal){
        strcpy(this->cadena, pal);
    }

    public:
    Str(){
        strcpy(cadena, "");
    }
    Str(Str* a){
        strcpy(cadena, a->cadena);
    }
    Str(char *pal){
        strcpy(cadena, pal);
    }

    void operator = (const Str &a){
        strcpy(cadena, a.cadena);
    }

    Str* operator= (char* word){
        if(word != NULL) return new Str(word);
        else return NULL;
    }

    friend bool operator!=(const Str &a, const Str &b){
        return strcmpi(a.cadena, b.cadena) != 0;
    }

    friend bool operator==(const Str &a, const Str &b){
        return strcmpi(a.cadena, b.cadena) == 0;
    }

    friend bool operator<(const Str &a, const Str &b){
        return strcmpi(a.cadena, b.cadena)<0;
    }

    friend bool operator>(const Str &a, const Str &b){
        return strcmpi(a.cadena, b.cadena)>0;
    }

    Str operator+(const Str &a){
        char temp[max_l];
        strcpy(temp, cadena);
        strcat(temp, a.cadena);
        return Str(temp);
    }

    void operator+=(const Str &a){
        char temp[max_l];
        strcpy(temp, cadena);
        strcat(temp, a.cadena);
        setWord(temp);
    }

    Str operator+(const char *a){
        char temp[max_l];
        strcpy(temp, cadena);
        strcat(temp, a);
        return Str(temp);
    }

    void operator+=(const char *a){
        char temp[max_l];
        strcpy(temp, cadena);
        strcat(temp, a);
        setWord(temp);
    }


    friend ostream & operator << (ostream &salida, Str A){
        salida << A.cadena;
        return salida;
    }

};

