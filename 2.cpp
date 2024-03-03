#include <iostream>
#include <chrono>
using namespace std;

int* randomNumberArray(int& size) {
    int* array = new int[size];
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }
    return array;
}

void printArray(int* array, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }
}

void selectionSort(int* data, int lenD)
{
    int key;
    for (int j = 1; j < lenD; j++) {
        key = data[j];
        int i = j - 1;
        while ((i >= 0) && (data[i] > key)) {
            data[i + 1] = data[i];
            i -= 1;
        }
        data[i + 1] = key;
    }
    //printArray(data, lenD);
}

void bubbleSort(int* v, int n) {
    long long count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 1; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                count+=3;
            }
            count++;
        }
        count++;
    }
    count++;
    cout << count;
    //printArray(v, n);
}
int main() {
    int len = 100000;
    int* arr = new int[len];
    arr = randomNumberArray(len);
    /*for (int i = 0; i < len; i++) {
        arr[i] = i;
    }*/
    //auto start = chrono::steady_clock::now();
    bubbleSort(arr, len);
    //auto end = chrono::steady_clock::now();
    //auto diff = end - start;
    //cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    delete[] arr;
}
