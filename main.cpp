#include <iostream>
using namespace std;

void printArray(int *array, int length){
    for (int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << "\n" << length << endl;
}

int *randomNumberArray(int &size){
    int *array = new int[size];
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%5;
    }
    return array;
}

void delFirstMethod(int *x, int n, int key){
    int i = 0;
    while(i < n) {
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                x[j] = x[j + 1];
            }
            n = n - 1;
        } else {
            i = i + 1;
        }
    }

    printArray(x, n);

}

void delOtherMethod(int *x, int n, int key){
    int j = 0;
    for(int i = 0; i < n; i++){
        x[j] = x[i];
        if (x[i] != key){
            j++;
        }
    }
    n = j;

    printArray(x, n);

}

int main() {
    int size_1 = 10;
    int size_2 = 100;
    int key_1 = 3;
    int key_2 = 4;

    int *array_1_random = randomNumberArray(size_1);
    int *array_2_random = randomNumberArray(size_2);
    int *array_best = new int[10]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int *array_worst = new int[10]{3, 3, 3, 3, 3, 3 ,3, 3, 3, 3};

    delFirstMethod(array_1_random, size_1, key_1);
    cout << "\n";
    delFirstMethod(array_2_random, size_2, key_2);
    cout << "\n";
    delFirstMethod(array_best, 10, key_1);
    cout << "\n";
    delFirstMethod(array_worst, 10, key_1);
    cout << "\n";
    delOtherMethod(array_1_random, size_1, key_1);
    cout << "\n";
    delOtherMethod(array_2_random, size_2, key_2);
    cout << "\n";
    delOtherMethod(array_best, 10, key_1);
    cout << "\n";
    delOtherMethod(array_worst, 10, key_1);

    delete[] array_1_random;
    delete[] array_2_random;
    return 0;
}
