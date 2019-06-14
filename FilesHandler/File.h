#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/**
 * @author David Urbina.
 * Helper template to handle operations over fstream files.
 */
template <class T>
class File {
    public:
        File() { init("", NULL, NULL); }
        File(char *name) { init(name, NULL, NULL); }

        /**
         * Contructor for setting pointers to transformation functions which transforms
         * from string to type T instances and viceversa.
         * @param name the name of the file.
         * @param (*toObject) pointer of function that takes a char sequence as argument and returns
         * an instance of the type T composed from the argument.
         * @param (*toString) pointer of function that takes an instance of the type T as argument
         * and return the char sequence representation of the argument.
         */
        File(char *name, T(*toObject)(char *str), void(*toString)(T Obj, char *buffer) ) { init(name, toObject, toString); }
        ~File(){}

        /**
         * Opens the fstream with the given open mode flags.
         * This method involves a verification to determine whether the name is valid.
         * @param flags the flags for opening the fstream.
         */
        void open(const ios_base::openmode &flags);
        void close(){ file.close(); }

        //Reading and writing for text files.
        void read(char* dest)   { file.getline(dest, 300, '\n'); }
        void write(char *source){ file<<source<<endl; }

        //Reading and writing for binary files.
        T read(){
            file.read( reinterpret_cast<char*> (&buffer), sizeof(T) );
            return buffer;
        }
        void write(T &source){ file.write( reinterpret_cast<char*> (&source), sizeof(T) ); }
        void write(){ write(buffer); }

        //Basic position operations.
        void realocate(int pos, bool read = true){
            read?
                file.seekg(pos*sizeof(T), ios::beg):
                file.seekp(pos*sizeof(T), ios::beg);
        }
        void gotoEOF(bool read = true){ realocate(length, read); }
        void gotoSOF(bool read = true){ // Go to the start of the file.
            realocate(0, read);

             //Clear the raised fstream flags.
            file.clear();
        }

        //Basic return operations.
        bool isEOF()    { return file.eof();  }
        bool isFail()   { return file.fail(); }
        T getBuffer()   { return buffer;      }
        int getLength() { return length;      }

        /*
         * Compute the length of the file, in lines.
         */
        int computeLength(){ return file.tellg()/sizeof(T); }

        void setName(char* name){ strcpy(this->name, name); }

        //Transformation operations.
        void asObject(char* str){ buffer = toObject(str);  }
        void asString(char *dest){ toString(buffer, dest); }

        void print();

    protected:

    private:
        char name[30];
        fstream file;
        int length;
        T buffer;

        //Transformation function pointers.
        T(*toObject)(char *str);
        void(*toString)(T Obj, char *buffer);

        /**
         * Initialization method to avoid code duplication, called in constructors.
         * @param name the name of the file.
         * @param (*toObject) pointer of function that takes a char sequence as argument and returns
         * an instance of the type T composed from the argument.
         * @param (*toString) pointer of function that takes an instance of the type T as argument
         * and return the char sequence representation of the argument.
         */
        void init(char* name, T(*toObject)(char *str), void(*toString)(T Obj, char *buffer) );
};

template <typename T>
void File<T>::init(char* name, T(*toObject)(char *str), void(*toString)(T Obj, char *buffer) ){
    strcpy(this->name, name);
    this->toObject = toObject;
    this->toString = toString;
    length = 0;
}

template <typename T>
void File<T>::open(const ios_base::openmode &flags){
    if(strcmp(name, "") == 0){
        cout<<"Error, es necesario especificar un nombre de archivo."<<endl;
        return;
    }
    file.open(name, flags);
    length = computeLength();
}

template <typename T>
void File<T>::print(){
    gotoSOF();
    while(true){
        read();
        if(isEOF()) break;
        cout<<buffer<<endl;
    }
}

#endif // FILE_H
