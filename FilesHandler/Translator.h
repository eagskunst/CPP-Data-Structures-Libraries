#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include "File.h"

template <class T>
class Translator {
    public:
        Translator(){}
        ~Translator(){}

        static void translate(char* in, char* out, T(*pf)(char* str)) {
            File<char*> source(in);
            File<T> dest(out, pf, NULL);

            source.open(ios::in);
            dest.open(ios::out | ios::binary);

            while(true) {
                char buffer[300];
                source.read(buffer);

                if(source.isEOF() )
                    break;

                dest.asObject(buffer);
                dest.write();
            }
        }

        static void translate(char* in, char* out, char*(*pf)(T obj) ){
        	File<T> source(in, NULL, pf);
        	File<char*> dest(out);

        	source.open(ios::in | ios::binary);
        	dest.open(ios::out);

        	while(true){
        		T buffer = source.read();

        		if(source.isEOF() ) break;

        		//FIXME: function asString returning thrash.
        		dest.write( source.asString(buffer) );
        	}
        }

    protected:

    private:
};

#endif // Translator_H
