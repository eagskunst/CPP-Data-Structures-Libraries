#ifndef SORTER_H
#define SORTER_H

#include <string.h>
#include <time.h>

// Class with various sorting/utility methods
class Sorter
{
    // Variables for time
    clock_t initialTime, finalTime;
    double secs;

    // Finds the pilar for Quick Sort
    int pilar(int low, int high)
    {
        int mid = (low + high) / 2;
        int pilar = (low + mid + high) / 3;
        return pilar;
    }

    // Count sort of arr[].
    void countSort(int arr[], int size, int exp)
    {
        int output[size], count[10] = {0};

        for (int i = 0; i < size; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
            arr[i] = output[i];
    }

public:
    //Utility methods.

    // Swaps char arrays.
    void swap(char *a, char *b)
    {
        char aux[999];
        strcpy(aux, a);
        strcpy(a, b);
        strcpy(b, aux);
    }

    // Swaps chars.
    void swap(char &a, char &b)
    {
        char aux;
        aux = a;
        a = b;
        b = aux;
    }

    // Swaps integers.
    void swap(int &a, int &b)
    {
        int aux;
        aux = a;
        a = b;
        b = aux;
    }

    // Swaps int arrays.
    void swap(int *a, int *b, int size)
    {
        for (int i = 0; i < size; i++)
        {
            int aux = a[i];
            a[i] = b[i];
            b[i] = aux;
        }
    }

    // Unsorts an int array.
    void unSort(int S[], int size)
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            int num = rand() % size;
            swap(S[i], S[num]);
        }
    }

    // Unsorts a char array.
    void unSort(char S[], int size)
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            int num = rand() % size;
            swap(S[i], S[num]);
        }
    }

    // Unsorts a bidimentional char array.
    void unSort(char **dictionary, int size)
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            int num = rand() % size;
            swap(dictionary[i], dictionary[num]);
        }
    }

    // Get maximum value from an int array.
    int getMax(int arr[], int size)
    {
        int max = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    // Get maximum value from a char array.
    int getMax(char arr[], int size)
    {
        char max = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    // Starts a timer
    void startTimer()
    {
        initialTime = clock();
    }

    // Stops the timer.
    void stopTimer()
    {
        finalTime = clock();
    }

    // Get the time in seconds.
    double getTime()
    {
        secs = (double)(finalTime - initialTime) / CLOCKS_PER_SEC;
        return secs;
    }

    // Sorting Methods for arrays,

    // Bubble Sort for Int Arrays.
    void bubbleSort(int S[], int size)
    {
        int flag = 1;
        for (int i = 0; i < size - 1 && flag == 1; i++)
        {
            flag = 0;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (S[j] > S[j + 1])
                {
                    swap(S[j], S[j + 1]);
                    flag = 1;
                }
            }
        }
    }

    // Bubble Sort for Char Arrays.
    void bubbleSort(char S[], int size)
    {
        int flag = 1;
        for (int i = 0; i < size - 1 && flag == 1; i++)
        {
            flag = 0;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (S[j] > S[j + 1])
                {
                    swap(S[j], S[j + 1]);
                    flag = 1;
                }
            }
        }
    }

    // Selection Sort for Int Arrays.
    void selectionSort(int S[], int size)
    {
        int minor;
        for (int i = 0; i < size; i++)
        {
            minor = i;
            for (int j = i; j < size; j++)
            {
                if (S[j] < S[minor])
                {
                    minor = j;
                }
            }
            swap(S[i], S[minor]);
        }
    }

    // Selection Sort for Char Arrays.
    void selectionSort(char S[], int size)
    {
        int minor;
        for (int i = 0; i < size; i++)
        {
            minor = i;
            for (int j = i; j < size; j++)
            {
                if (S[j] < S[minor])
                {
                    minor = j;
                }
            }
            swap(S[i], S[minor]);
        }
    }

    // Shaker Sort for Int Arrays
    void shakerSort(int S[], int size)
    {
        bool cambio = true;
        for (int i = 0; i < (size / 2) && cambio; i++)
        {
            cambio = false;
            for (int j = i; j < size - i - 1; j++)
            {
                if (S[j] > S[j + 1] || S[j] == S[j + 1])
                {
                    swap(S[j], S[j + 1]);
                    cambio = true;
                }
            }
            for (int j = size - i - 2; j > i; j--)
            {
                if (S[j] < S[j - 1] || S[j] == S[j - 1])
                {
                    swap(S[j], S[j - 1]);
                    cambio = true;
                }
            }
        }
    }

    // Shaker Sort for Char Arrays
    void shakerSort(char S[], int size)
    {
        bool cambio = true;
        for (int i = 0; i < (size / 2) && cambio; i++)
        {
            cambio = false;
            for (int j = i; j < size - i - 1; j++)
            {
                if (S[j] > S[j + 1] || S[j] == S[j + 1])
                {
                    swap(S[j], S[j + 1]);
                    cambio = true;
                }
            }
            for (int j = size - i - 2; j > i; j--)
            {
                if (S[j] < S[j - 1] || S[j] == S[j - 1])
                {
                    swap(S[j], S[j - 1]);
                    cambio = true;
                }
            }
        }
    }

    // Direct Insertion for Int Arrays
    void directInsertion(int S[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            int aux;
            aux = S[i];
            int j = i - 1;
            while (j >= 0 && S[j] > aux)
            {
                S[j + 1] = S[j];
                j--;
            }
            S[j + 1] = aux;
        }
    }

    // Direct Insertion for Char Arays
    void directInsertion(char S[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            char aux;
            aux = S[i];
            int j = i - 1;
            while (j >= 0 && S[j] > aux)
            {
                S[j + 1] = S[j];
                j--;
            }
            S[j + 1] = aux;
        }
    }

    // Direct Selection for Int Arrays
    void directSelection(int S[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int minor = i;
            for (int j = i; j < size; j++)
            {
                if (S[j] < S[minor])
                    minor = j;
            }
            swap(S[i], S[minor]);
        }
    }

    // Direct Selection for Char Arrays
    void directSelection(char S[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int minor = i;
            for (int j = i; j < size; j++)
            {
                if (S[j] < S[minor])
                    minor = j;
            }
            swap(S[i], S[minor]);
        }
    }

    // Radix Sort for Int Arrays
    void radixSort(int arr[], int size)
    {
        int m = getMax(arr, size);

        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, size, exp);
    }

    // Shell Sort for Int Arrays
    void shellSort(int S[], int size)
    {
        for (int i = size / 2; i > 0; i = i / 2)
        {
            for (int j = i; j < size; j++)
            {
                for (int k = j - i; k >= 0; k = k - i)
                {
                    if (S[k + i] >= S[k])
                        break;
                    else
                    {
                        swap(S[k + i], S[k]);
                    }
                }
            }
        }
    }

    // Shell Sort for Char Arrays
    void shellSort(char S[], int size)
    {
        for (int i = size / 2; i > 0; i = i / 2)
        {
            for (int j = i; j < size; j++)
            {
                for (int k = j - i; k >= 0; k = k - i)
                {
                    if (S[k + i] >= S[k])
                        break;
                    else
                    {
                        swap(S[k + i], S[k]);
                    }
                }
            }
        }
    }

    // Quick Sort for Int Arrays
    void quickSort(int S[], int i, int j)
    {
        int pi = pilar(i, j);
        bool ci = false, cj = false;
        int low = i, high = j;
        if (high > low)
        {
            while (i <= j)
            {
                if (S[i] < S[pi])
                {
                    i++;
                    ci = false;
                }
                else
                    ci = true;
                if (S[j] > S[pi])
                {
                    j--;
                    cj = false;
                }
                else
                    cj = true;
                if (ci && cj)
                {
                    swap(S[i], S[j]);
                    if (i == pi)
                    {
                        pi = j;
                        j++;
                    }
                    else if (j == pi)
                    {
                        pi = i;
                        i--;
                    }
                    i++;
                    j--;
                }
            }
            quickSort(S, low, pi - 1);
            quickSort(S, pi + 1, high);
        }
    }

    // Quick Sort for Char Arrays
    void quickSort(char S[], int i, int j)
    {
        int pi = pilar(i, j);
        bool ci = false, cj = false;
        int low = i, high = j;
        if (high > low)
        {
            while (i <= j)
            {
                if (S[i] < S[pi])
                {
                    i++;
                    ci = false;
                }
                else
                    ci = true;
                if (S[j] > S[pi])
                {
                    j--;
                    cj = false;
                }
                else
                    cj = true;
                if (ci && cj)
                {
                    swap(S[i], S[j]);
                    if (i == pi)
                    {
                        pi = j;
                        j++;
                    }
                    else if (j == pi)
                    {
                        pi = i;
                        i--;
                    }
                    i++;
                    j--;
                }
            }
            quickSort(S, low, pi - 1);
            quickSort(S, pi + 1, high);
        }
    }

    // Sorting Algorithms for bidimentional Char Arrays

    // Bubble Sort for Bidimentional Char Array
    void bubbleSort(char **dictionary, int size)
    {
        bool cambio = true;
        for (int i = 0; i < size - 1 && cambio; i++)
        {
            cambio = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (strcmp(dictionary[j], dictionary[j + 1]) > 0 || strcmp(dictionary[j], dictionary[j + 1]) == 0)
                {
                    swap(dictionary[j], dictionary[j + 1]);
                    cambio = true;
                }
            }
        }
    }

    // Shaker Sort for Bidimentional Char Array
    void shakerSort(char **dictionary, int size)
    {
        bool cambio = true;
        for (int i = 0; i < (size / 2) && cambio; i++)
        {
            cambio = false;
            for (int j = i; j < size - i - 1; j++)
            {
                if (strcmp(dictionary[j], dictionary[j + 1]) > 0 || strcmp(dictionary[j], dictionary[j + 1]) == 0)
                {
                    swap(dictionary[j], dictionary[j + 1]);
                    cambio = true;
                }
            }
            for (int j = size - i - 2; j > i; j--)
            {
                if (strcmp(dictionary[j], dictionary[j - 1]) < 0 || strcmp(dictionary[j], dictionary[j - 1]) == 0)
                {
                    swap(dictionary[j], dictionary[j - 1]);
                    cambio = true;
                }
            }
        }
    }

    // Direct Insertion for Bidimentional Char Array
    void directInsertion(char **dictionary, int size)
    {
        for (int i = 1; i < size; i++)
        {
            char palabra[200];
            strcpy(palabra, dictionary[i]);
            int j = i - 1;
            while (j >= 0 && (strcmp(dictionary[j], palabra) > 0))
            {
                strcpy(dictionary[j + 1], dictionary[j]);
                j--;
            }
            strcpy(dictionary[j + 1], palabra);
        }
    }

    // Direct Selection for Bidimentional Char Array
    void directSelection(char **dictionary, int size)
    {
        for (int i = 0; i < size; i++)
        {
            int menor = i;
            for (int j = i; j < size; j++)
            {
                if (strcmp(dictionary[j], dictionary[menor]) < 0)
                    menor = j;
            }
            swap(dictionary[i], dictionary[menor]);
        }
    }

    // Shell Sort for Bidimentional Char Array
    void shellSort(char **dictionary, int size)
    {
        for (int i = size / 2; i > 0; i = i / 2)
        {
            for (int j = i; j < size; j++)
            {
                for (int k = j - i; k >= 0; k = k - i)
                {
                    if (strcmp(dictionary[k + i], dictionary[k]) >= 0)
                        break;
                    else
                    {
                        swap(dictionary[k + i], dictionary[k]);
                    }
                }
            }
        }
    }

    // Quick Sort for Bidimentional Char Array
    void quickSort(char **dictionary, int i, int j)
    {
        int pi = pilar(i, j);
        bool ci = false, cj = false;
        int low = i, high = j;
        if (high > low)
        {
            while (i <= j)
            {
                if (strcmp(dictionary[i], dictionary[pi]) < 0)
                {
                    i++;
                    ci = false;
                }
                else
                    ci = true;
                if (strcmp(dictionary[j], dictionary[pi]) > 0)
                {
                    j--;
                    cj = false;
                }
                else
                    cj = true;
                if (ci && cj)
                {
                    swap(dictionary[i], dictionary[j]);
                    if (i == pi)
                    {
                        pi = j;
                        j++;
                    }
                    else if (j == pi)
                    {
                        pi = i;
                        i--;
                    }
                    i++;
                    j--;
                }
            }
            quickSort(dictionary, low, pi - 1);
            quickSort(dictionary, pi + 1, high);
        }
    }
};

#endif