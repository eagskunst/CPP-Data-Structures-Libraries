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
        static char* asString(Tester t){ return t.getStr(); }

        friend ostream& operator<<(ostream &os, Tester t){
            cout<<t.str;
            return os;
        }

    protected:

    private:
        char str[50];
};

#endif // TESTER_H
