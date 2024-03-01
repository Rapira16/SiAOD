#include <iostream>

int *randomNumberArray(int &size){
    int *array = new int[size];
    srand(time(nullptr));

    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%5;
    }
    return array;
}

void printArray(int* array, int len){
    for(int i = 0; i < len; i++){
        std::cout << array[i] << " ";
    }
}

void selectionSort(int* data, int lenD)
{
    int j = 0;
    int tmp = 0;
    for(int i=0; i<lenD; i++){
        j = i;
        for(int k = i; k<lenD; k++){
            if(data[j]>data[k]){
                j = k;
            }
        }
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
    printArray(data, lenD);
}

void bubbleSort(int* v, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    printArray(v, n);
}
int main(){
    int len = 100;
    int* arr;
    arr = randomNumberArray(len);
    bubbleSort(arr, len);
    delete[] arr;
}
