#ifndef HASHER_H
#define HASHER_H

#include <string.h>

class Hasher
{

public:
    // Hashes an char Element.
    int hash(char *element, int maxSize)
    {
        int hashIndex = 0;
        int suma = 0, valor = 0, multiplicador = 1;
        for (int i = 0; i < strlen(element); i++)
        {
            valor = element[i];
            valor *= multiplicador;
            suma += valor;
            multiplicador *= 10;
        }
        if (suma < 0)
            suma *= -1;
        while (suma >= maxSize)
        {
            suma /= 10;
        }
        hashIndex = suma;
        return hashIndex;
    }

    // Hashes an int Element.
    int hash(int element, int maxSize)
    {
        int hashIndex = 0;
        int suma = 0, valor = 0, multiplicador = 1000000000;
        while (multiplicador > 1)
        {
            if (element / multiplicador < 1)
            {
                multiplicador /= 10;
            }
            else
            {
                break;
            }
        }
        bool flag = false;
        while (true)
        {
            if (flag)
            {
                valor += element / multiplicador;
                suma += valor;
                flag = !flag;
                valor = 0;
            }
            else
            {
                valor += element / multiplicador;
                flag = !flag;
            }
            if (multiplicador <= 1)
                break;
            element %= 10;
            multiplicador /= 10;
        }
        if (!flag)
        {
            suma += valor;
        }
        if (suma < 0)
            suma *= -1;
        while (suma >= maxSize)
        {
            suma /= 10;
        }
        hashIndex = suma;
        return hashIndex;
    }

    // Hashes a bidimentional char array.
    char **hash(char **dictionary, int size, int *sizeH)
    {
        char **hashed;
        if (size < 1)
        {
            return dictionary;
        }
        else if (size < 10)
        {
            *sizeH = 10;
            int newSize = *sizeH;
            hashed = new char *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = new char[35];
                strcpy(hashed[i], "zzziioo");
            }
        }
        else if (size < 100)
        {
            *sizeH = 100;
            int newSize = *sizeH;
            hashed = new char *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = new char[35];
                strcpy(hashed[i], "zzziioo");
            }
        }
        else if (size < 1000)
        {
            *sizeH = 1000;
            int newSize = *sizeH;
            hashed = new char *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = new char[35];
                strcpy(hashed[i], "zzziioo");
            }
        }
        else if (size < 10000)
        {
            *sizeH = 10000;
            int newSize = *sizeH;
            hashed = new char *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = new char[35];
                strcpy(hashed[i], "zzziioo");
            }
        }
        else if (size < 100000)
        {
            *sizeH = 100000;
            int newSize = *sizeH;
            hashed = new char *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = new char[35];
                strcpy(hashed[i], "zzziioo");
            }
        }
        else if (size > 100000)
        {
            return dictionary;
        }

        for (int i = 0; i < size; i++)
        {
            int hashIndex = hash(dictionary[i], *sizeH);
            while (strcmp(hashed[hashIndex], "zzziioo") != 0)
            {
                hashIndex++;
                if (hashIndex == *sizeH)
                    hashIndex = 0;
            }
            strcpy(hashed[hashIndex], dictionary[i]);
        }

        return hashed;
    }

    // Hashes an int array.
    int *hash(int S[], int size, int *sizeH)
    {
        int *hashed;
        if (size < 1)
        {
            return S;
        }
        else if (size < 10)
        {
            *sizeH = 10;
            int newSize = *sizeH;
            hashed = new int[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = -11111;
            }
        }
        else if (size < 100)
        {
            *sizeH = 100;
            int newSize = *sizeH;
            hashed = new int[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = -11111;
            }
        }
        else if (size < 1000)
        {
            *sizeH = 1000;
            int newSize = *sizeH;
            hashed = new int[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = -11111;
            }
        }
        else if (size < 10000)
        {
            *sizeH = 10000;
            int newSize = *sizeH;
            hashed = new int[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = -11111;
            }
        }
        else if (size < 100000)
        {
            *sizeH = 100000;
            int newSize = *sizeH;
            hashed = new int[newSize];
            for (int i = 0; i < newSize; i++)
            {
                hashed[i] = -11111;
            }
        }
        else if (size > 100000)
        {
            return S;
        }

        for (int i = 0; i < size; i++)
        {
            int hashIndex = hash(S[i], *sizeH);
            while (hashed[hashIndex] != -11111)
            {
                hashIndex++;
                if (hashIndex == *sizeH)
                    hashIndex = 0;
            }
            hashed[hashIndex] = S[i];
        }

        return hashed;
    }

    // Searchs for an element on a bidimentional char array.
    int search(char **hashedArray, int sizeH, char *element)
    {
        int hashIndex = hash(element, sizeH);
        for (int i = 0; i < sizeH; i++)
        {
            if (strcmp(element, hashedArray[hashIndex]) == 0)
                return hashIndex;
            else
            {
                hashIndex++;
            }
            if (hashIndex == sizeH)
                hashIndex = 0;
        }
        return -1;
    }

    // Searchs for an element on an int array.
    int search(int hashedArray[], int sizeH, int element)
    {
        int hashIndex = hash(element, sizeH);
        for (int i = 0; i < sizeH; i++)
        {
            if (element == hashedArray[hashIndex])
                return hashIndex;
            else
            {
                hashIndex++;
            }
            if (hashIndex == sizeH)
                hashIndex = 0;
        }
        return -1;
    }
};

#endif
