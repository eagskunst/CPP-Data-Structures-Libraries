#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

const int OPENMODE_READING_TXT =  1;
const int OPENMODE_WRITING_TXT =  2;
const int OPENMODE_ADDING_TXT =  3;
const int OPENMODE_READING_BIN =  4;
const int OPENMODE_WRITING_BIN =  5;
const int OPENMODE_ADDING_BIN =  6;
const bool TEXT_FILE = true;
const bool BIN_FILE = false;

using namespace std;

template <class T>
class fileManager
{
    fstream file;
    char name[40];
    T fileBuffer;
    int size;
    bool isTxt = false;

    public:

    // CONSTRUCTORS

    fileManager()                                           { strcpy(name, ""); size = sizeof(T); }
    fileManager(char *name_)                                { strcpy(name, name_); size = sizeof(T); }
    fileManager(char *name_, const std::_Ios_Openmode &t)   { strcpy(name, name_); size = sizeof(T); file.open(name, t); }
    fileManager(char *name_, int openmode)                  { strcpy(name, name_); size = sizeof(T); 
                                                              if(openmode == OPENMODE_READING_TXT) file.open(name, ios::in);
                                                              else if(openmode == OPENMODE_WRITING_TXT) file.open(name, ios::out);
                                                              else if(openmode == OPENMODE_ADDING_TXT) file.open(name, ios::out | ios::app);
                                                              else if(openmode == OPENMODE_READING_BIN) file.open(name, ios::in | ios::binary);
                                                              else if(openmode == OPENMODE_WRITING_BIN) file.open(name, ios::out | ios::binary);
                                                              else if(openmode == OPENMODE_ADDING_BIN) file.open(name, ios::out | ios::app | ios::binary); 
                                                              if(openmode <= OPENMODE_ADDING_TXT) isTxt = true;
                                                              else isTxt = false; }

    // UTILITY METHODS

    void setName(char *name_)                               { strcpy(name, name_); }
    char *getName()                                         { return name; }
    void open(const std::_Ios_Openmode &t)                  { if(!file.is_open()) file.open(name, t); }
    void open(int openmode)                                 { if(!file.is_open()) {
                                                             if(openmode == OPENMODE_READING_TXT) file.open(name, ios::in);
                                                             else if(openmode == OPENMODE_WRITING_TXT) file.open(name, ios::out);
                                                             else if(openmode == OPENMODE_ADDING_TXT) file.open(name, ios::out | ios::app);
                                                             else if(openmode == OPENMODE_READING_BIN) file.open(name, ios::in | ios::binary);
                                                             else if(openmode == OPENMODE_WRITING_BIN) file.open(name, ios::out | ios::binary);
                                                             else if(openmode == OPENMODE_ADDING_BIN) file.open(name, ios::out | ios::app | ios::binary); 
                                                             if(openmode <= OPENMODE_ADDING_TXT) isTxt = true;
                                                             else isTxt = false; } }
    void close()                                            { if(file.is_open()) file.close(); }
    void read(char *line_)                                  { char line[300]; file.getline(line, 300, '\n'); strcpy(line_, line); }
    void read(T &b)                                         { file.read(reinterpret_cast<char *>(&b), size); }
    void readAndConvert(T &b, T(*convertion)(char *str))    { char line[300]; file.getline(line, 300, '\n'); fileBuffer = convertion(line);}
    void write(char *line_)                                 { strcat(*line_, "\n"); file << line_; }
    void write(T &b)                                        { file.write(reinterpret_cast<char *>(&b), size); }
    void readFrom(int pos)                                  { file.seekg(pos*size, ios::beg); }
    void writeFrom(int pos)                                 { file.seekp(pos*size, ios::beg); }
    int getReadPos()                                        { return (file.tellg() / size); }
    int getWritePos()                                       { return (file.tellp() / size); }
    int getSize(bool filetype)                              { if(filetype == BIN_FILE) { int previousPos = getReadPos(); file.seekg(0, ios::end);
                                                                int sizeOfFile = file.tellg() / size; readFrom(previousPos); return sizeOfFile; } 
                                                              else { int previousPos = getReadPos(); file.seekg(0, ios::end); int i = 0;
                                                                while (!file.eof()){char temp[300]; read(temp); if(strcmp(temp, "") != 0) i++;}
                                                                readFrom(previousPos); return i; } }
    bool getEOF()                                           { return file.eof(); }
    bool getFail()                                          { return file.fail(); }
    bool getIsTxt()                                         { return isTxt;}
    T getBuffer()                                           { return fileBuffer; }

};

#endif