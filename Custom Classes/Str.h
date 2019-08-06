#include <string.h>
#include <iostream>
using namespace std;
#define max_l 200

class Str {

    char cadena[max_l];
    int lenght = -1;
    static const char CHARACTER_EXCEEDS = ' ';

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

    void operator+=(const char a){
        char temp[max_l];
        char toAdd[2];
        toAdd[0] = a;
        strcpy(temp, cadena);
        strcat(temp, toAdd);
        setWord(temp);
    }

    char getCharAt(int i){
        if(lenght == -1){
            lenght = strlen(cadena);
        }

        if(i<lenght){
            return cadena[i];
        }
        else{
            return CHARACTER_EXCEEDS;
        }
    }

    int getLenght(){
        if(lenght == -1) lenght = strlen(cadena);
        return lenght;
    }


    friend ostream & operator << (ostream &salida, Str A){
        salida << A.cadena;
        return salida;
    }

    static Str toObject(char *str){
        Str temp;
        strcpy(temp.cadena, str);
        return temp;
    }

    static void toString(Str obj, char* dest){
        strcpy(dest, obj.cadena);
    }

};

