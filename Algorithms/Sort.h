#ifndef SORT_H
#define SORT_H

#include <iostream>

using namespace std;

template <class T>
class Sort {
    public:
        Sort() {}
        ~Sort() {}

        void bubble(T *v, int length) {
            bool isSwap = false;

            for(int i = 0; (i < length - 2) && !isSwap; i++) {
                isSwap = true;

                for(int j = 0; j < (length - i - 1); j++)
                    if(v[j] > v[j+1]) {
                        swap(v[j], v[j+1]);
                        isSwap = false;
                    }
            }

            //print(v, length);
        }

        void print(T *v,int  length){
            for(int i = 0; i < length; i++)
                cout<<v[i]<<endl;
        }

        void shaker(T *v, int length) {
            for (int i = 0; i < length/2; i++) {
                bool swapped = false;

                for (int j = i; j < length - i - 1; j++)
                    if (v[j] > v[j+1]) {
                        swap(v[j], v[j+1]);
                        swapped = true;
                    }

                for (int j = length - 2 - i; j > i; j--)
                    if (v[j] < v[j-1]) {
                        swap(v[j], v[j-1]);
                        swapped = true;
                    }

                if(!swapped)
                    break;
            }
        }

        void directInsertion(T *v, int length) {
            T aux;

            for(int i = 1; i < length; i++) {
                aux = v[i];
                int j;

                for(j = i - 1; j >= 0 && v[j] > aux; j--)
                    v[j + 1] = v[j];

                v[j + 1] = aux;
            }
        }

        void radix(T *v, int length);

        void shell(T *v, int length) {
            for (int gap = length/2; gap > 0; gap /= 2)

                for (int i = gap; i < length; i++) {
                    T temp = v[i];

                    int j;
                    for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                        v[j] = v[j - gap];

                    v[j] = temp;
                }
        }

        void quicksort(T *v, int length) {
            if(length <= 1)
                return;

            int pivot = findPivot(v, length);
            quicksort(v, pivot);
            quicksort(v + pivot + 1, length - pivot - 1);

        }

    protected:

    private:
        int findPivot(T *v, int length) {
            int low = 0, high = length - 1;

            while(low < high) {
                while(true) {
                    if(v[low] > v[high]) {
                        swap(v[low], v[high]);
                        break;
                    }

                    high--;

                    if(high <= low)
                        return low;
                }

                while(true) {
                    if(v[high] < v[low]) {
                        swap(v[high], v[low]);
                        break;
                    }

                    low++;

                    if(low >= high)
                        return high;
                }
            }

            return -1;
        }

};

#endif // SORT_H

