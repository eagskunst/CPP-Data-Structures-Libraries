#ifndef SEARCHER_H
#define SEARCHER_H

#include <string.h>
#include <time.h>

class Searcher
{

    // Variables for time
    clock_t initialTime, finalTime;
    double secs;

public:
    //Utility methods.

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

    // Searching Methods for Arrays.

    // Binary Search for int arrays. Quick Method but requires array to be ordered.
    int binarySearch(int S[], int size, int target)
    {
        int low, mid, high;
        bool found = false;
        low = 0;
        high = size;

        while ((low + 1) != high)
        {
            mid = (low + high) / 2;
            if (S[mid] == target)
            {
                found = true;
                break;
            }
            else if (S[mid] > target)
            {
                high = mid;
                mid = (low + high) / 2;
            }
            else if (S[mid] < target)
            {
                low = mid;
                mid = (low + high) / 2;
            }
        }

        if (found)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }

    // Binary Search for char arrays. Quick Method but requires array to be ordered.
    int binarySearch(char S[], int size, char target)
    {
        int low, mid, high;
        bool found = false;
        low = 0;
        high = size;

        while ((low + 1) != high)
        {
            mid = (low + high) / 2;
            if (S[mid] == target)
            {
                found = true;
                break;
            }
            else if (S[mid] > target)
            {
                high = mid;
                mid = (low + high) / 2;
            }
            else if (S[mid] < target)
            {
                low = mid;
                mid = (low + high) / 2;
            }
        }

        if (found)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }

    // Secuential Block Search for int array. Quick Method but requires array to be ordered.
    int secuentialBlockSearch(int S[], int size, int target)
    {
        int foundpos, part;
        bool found = false;
        if (size / 2 > 1)
        {
            if (size / 4 > 1)
            {
                if (size / 8 > 1)
                {
                    if (size / 16 > 1)
                    {
                        part = size / 16;
                    }
                    else
                    {
                        part = size / 8;
                    }
                }
                else
                {
                    part = size / 4;
                }
            }
            else
            {
                part = size / 2;
            }
        }
        else
        {
            part = 1;
        }
        for (int i = part; i < size; i += part)
        {
            if (S[i] > target)
            {
                for (int j = i - part; (j <= i) && (found == false); j++)
                {
                    if (S[j] == target)
                    {
                        foundpos = j;
                        found = true;
                        break;
                    }
                }
            }
            else if (S[i] < target)
            {
                for (int j = i; (j <= i + part) && (found == false) && (j < size); j++)
                {
                    if (S[j] == target)
                    {
                        foundpos = j;
                        found = true;
                        break;
                    }
                }
            }
            else if (S[i] == target)
            {
                foundpos = i;
                found = true;
                break;
            }
        }
        if (found)
        {
            return foundpos;
        }
        else
        {
            return -1;
        }
    }

    // Secuential Block Search for char array. Quick Method but requires array to be ordered.
    int secuentialBlockSearch(char S[], int size, char target)
    {
        int foundpos, part;
        bool found = false;
        if (size / 2 > 1)
        {
            if (size / 4 > 1)
            {
                if (size / 8 > 1)
                {
                    if (size / 16 > 1)
                    {
                        part = size / 16;
                    }
                    else
                    {
                        part = size / 8;
                    }
                }
                else
                {
                    part = size / 4;
                }
            }
            else
            {
                part = size / 2;
            }
        }
        else
        {
            part = 1;
        }
        for (int i = part; i < size; i += part)
        {
            if (S[i] > target)
            {
                for (int j = i - part; (j <= i) && (found == false); j++)
                {
                    if (S[j] == target)
                    {
                        foundpos = j;
                        found = true;
                        break;
                    }
                }
            }
            if (S[i] < target)
            {
                for (int j = i; (j <= i + part) && (j < size); j++)
                {
                    if (S[j] == target)
                    {
                        foundpos = j;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (found)
        {
            return foundpos;
        }
        else
        {
            return -1;
        }
    }

    // Secuential Search for int array. Slow Method but doesn't require array to be ordered.
    int secuentialSearch(int S[], int size, int target)
    {
        for(int i = 0; i < size; i++)
        {
            if(S[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    // Secuential Search for char array. Slow Method but doesn't require array to be ordered.
    int secuentialSearch(char S[], int size, char target)
    {
        for(int i = 0; i < size; i++)
        {
            if(S[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    // Searching Methods for bidimentional char arrays.

    // Binary Search for bidimentional char array. Quick Method but requires array to be ordered.
    int binarySearch(char **dictionary, int size, char *target)
    {
        int low, mid, high;
        bool found = false;
        low = 0;
        high = size;

        while ((low + 1) != high)
        {
            mid = (low + high) / 2;
            if (strcmp(dictionary[mid], target) == 0)
            {
                found = true;
                break;
            }
            else if (strcmp(dictionary[mid], target) > 0)
            {
                high = mid;
                mid = (low + high) / 2;
            }
            else if (strcmp(dictionary[mid], target) < 0)
            {
                low = mid;
                mid = (low + high) / 2;
            }
        }

        if (found)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }

    // Secuential Block Search for bidimentional char array. Quick Method but requires array to be ordered.
    int secuentialBlockSearch(char **dictionary, int size, char *target)
    {
        int foundpos, part;
        bool found = false;
        if (size / 2 > 1)
        {
            if (size / 4 > 1)
            {
                if (size / 8 > 1)
                {
                    if (size / 16 > 1)
                    {
                        part = size / 16;
                    }
                    else
                    {
                        part = size / 8;
                    }
                }
                else
                {
                    part = size / 4;
                }
            }
            else
            {
                part = size / 2;
            }
        }
        else
        {
            part = 1;
        }
        for (int i = part; i < size; i += part)
        {
            if (strcmp(dictionary[i], target) > 0)
            {
                for (int j = i - part; (j <= i) && (found == false); j++)
                {
                    if (strcmp(dictionary[j], target) == 0)
                    {
                        foundpos = j;
                        found = true;
                        break;
                    }
                }
            }
            if (strcmp(dictionary[i], target) < 0)
            {
                for (int j = i; (j <= i + part) && (j < size); j++)
                {
                    if (strcmp(dictionary[j], target) == 0)
                    {
                        foundpos = j;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (found)
        {
            return foundpos;
        }
        else
        {
            return -1;
        }
    }

    // Secuential Search for bidimentional char array. Slow Method but doesn't require array to be ordered.
    int secuentialSearch(char **dictionary, int size, char *target)
    {
        for(int i = 0; i < size; i++)
        {
            if(strcmp(dictionary[i], target))
            {
                return i;
            }
        }
        return -1;
    }
};

#endif