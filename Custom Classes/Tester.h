#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <cstring>

using namespace std;

class Tester
{
    public:
        Tester() { strcpy(str, "this is a test"); }
        Tester(char* str){ strcpy(this->str, str); }
        ~Tester(){  }

        void setStr(char *str){ strcpy(this -> str, str); }
        char* getStr(){ return str; }

        static Tester asObject(char* str){ return Tester(str); }
        static void asString(Tester t, char *dest){ strcpy(dest, t.getStr() ); }

        friend bool operator==(const Tester &a, const Tester &b){ return strcmp(a.str, b.str) == 0; }

        friend ostream& operator<<(ostream &os, Tester t){
            cout<<t.str;
            return os;
        }

    protected:

    private:
        char str[50];
};

#endif // TESTER_H
