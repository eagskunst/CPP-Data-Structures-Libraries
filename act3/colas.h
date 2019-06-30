#include <iostream>

template <class T>
class colaCircular
{
private:
    T cola[1000];
    int maxSize;
    int frente, fin;

public:
    colaCircular(int size);
    void agregarNodo(T &nodo);
    T retirarNodo()
    {
        if (fin == -1)
        {
            std::cout << "La cola esta vacia" << std::endl;
            return NULL;
        }
        else
        {
            T buffer = cola[frente];
            cola[frente] = NULL;
            if (frente == fin)
            {
                frente = 0;
                fin = -1;
            }
            else
            {
                frente++;
                if (frente == maxSize)
                    frente = 0;
            }
            return buffer;
        }
    }
    void eliminarNodo();
    ~colaCircular() {}
};

template <typename T>
colaCircular<T>::colaCircular(int size)
{
    this->maxSize = size;
    this->frente = 0;
    this->fin = -1;//Por sia xdxd
    for(int i = 0;i<size;i++)
        cola[i] = NULL;
}

template <typename T>
void colaCircular<T>::agregarNodo(T &nodo)
{
    fin++;
    if (fin == maxSize)
        fin = 0;
    if (cola[fin] == NULL)
        cola[fin] = nodo;
    else
    {
        std::cout << "La cola esta llena." << std::endl;
        fin--;
        if (fin == -1)
            fin = maxSize - 1;
    }
}

template <typename T>
void colaCircular<T>::eliminarNodo()
{
    if (fin == -1)
    {
        std::cout << "La cola ya esta vacia" << std::endl;
    }
    else
    {
        cola[frente] = NULL;
        if (frente == fin)
        {
            frente = 0;
            fin = -1;
        }
        else
        {
            frente++;
            if (frente == maxSize)
                frente = 0;
        }
    }
}
