#include <iostream>
using namespace std;

void printArray(int* array, int length) {
    cout << "array = ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << "\nlength = " << length << endl;
}

int* randomNumberArray(int size) {
    int* array = new int[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 5;
    }
    return array;
}

void delFirstMethod(int* x, int n, int key) {
    int count = 0;
    int i = 0;
    count++;
    while (i < n) {
        count++;
        if (x[i] == key) {
            count++;
            for (int j = i; j < n - 1; j++) {
                count += 1;
                x[j] = x[j + 1];
                count++;
            }
            count++;
            n = n - 1;
            count++;
        }
        else {
            count++;
            i = i + 1;
            count++;
        }
    }
    count++;

    printArray(x, n);
    cout << "all operations = " << count << "\n";
}

void delOtherMethod(int* x, int n, int key) {
    int count = 0;
    int j = 0;
    count++;
    for (int i = 0; i < n; i++) {
        count++;
        x[j] = x[i];
        count++;
        if (x[i] != key) {
            j++;
            count++;
        }
        count++;
    }
    count++;
    n = j;
    count++;

    printArray(x, n);
    cout << "all operations = " << count << "\n";

}

int main() {
    int size_1 = 10;
    int key_1 = 3;
    int* array_1_random = new int[size_1];

    array_1_random = randomNumberArray(size_1);
    int* array_best = new int[10]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int* array_worst = new int[10]{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

    cout << "delFirstMethod: \n";
    cout << "random ";
    delFirstMethod(array_1_random, size_1, key_1);
    cout << "\n";
    cout << "best ";
    delFirstMethod(array_best, 10, key_1);
    cout << "\n";
    cout << "worst ";
    delFirstMethod(array_worst, 10, key_1);
    cout << "\ndelOtherMethod: \n";
    cout << "\n";
    cout << "random ";
    delOtherMethod(array_1_random, size_1, key_1);
    cout << "\n";
    cout << "worst ";
    delOtherMethod(array_best, 10, key_1);
    cout << "\n";
    cout << "best ";
    delOtherMethod(array_worst, 10, key_1);

    delete[] array_1_random;
    return 0;
}
