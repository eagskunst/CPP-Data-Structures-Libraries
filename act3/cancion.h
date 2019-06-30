#include <string.h>
#include <iostream>

class Cancion
{
private:
public:
    int minutos, segundos;
    char nombre[100];
    Cancion() {strcpy(nombre,""); minutos = 0; segundos = 0;}
    Cancion(char *datos);
    void cargarDatos(char *datos);
    ~Cancion();
};

Cancion::Cancion(char *datos)
{
    char *token = strtok(datos, ",");
    strcpy(this->nombre, token);
    token = strtok(NULL, ",");
    this->minutos = atoi(token);
    token = strtok(NULL, ",");
    this->segundos = atoi(token);
}

void Cancion::cargarDatos(char *datos)
{
    char *token = strtok(datos, ",");
    strcpy(this->nombre, token);
    token = strtok(NULL, ",");
    this->minutos = atoi(token);
    token = strtok(NULL, ",");
    this->segundos = atoi(token);
}

Cancion::~Cancion()
{
}
