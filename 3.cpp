#include <iostream>
#include <chrono>

int* shellSort(int* array, int size){
    for (int gap = size/3 + 1; gap > 0; gap /= 3)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) array[j] = array[j - gap];
            array[j] = temp;
        }
    }
    return array;
}

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

void printArray(int* array, int size){
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
}

int* randomArray(int size){
    int* array = new int[size];
    srand (time(nullptr));
    for(int i = 0; i < size; i++){
        array[i] = rand() % size;
    }
    return array;
}

int main() {
    int size = 100;
    int* array = randomArray(size);
    //printArray(array, size);
    //std::cout << "\n";
    auto start = std::chrono::steady_clock::now();
    quickSort(array, 0, size-1);
    auto end = std::chrono::steady_clock::now();
    //printArray(array, size);
    std::cout << "Elapsed time in milliseconds: "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " ms" << std::endl;
    delete[] array;
    /* shellSort
     * 100 - 0
     * 1000 - 0
     * 10000 - 0
     * 100000 - 9
     * 1000000 - 120
     *
     *
     * quickSort
     * 100 - 0
     * 1000 - 0
     * 10000 - 0
     * 100000 - 6
     * 1000000 - 76
     * */
    return 0;
}
