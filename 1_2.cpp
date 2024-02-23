#include <iostream>
using namespace std;

int** randomMatrix(int row, int column){
    srand(time(NULL));

    int** matrix = new int *[row];

    for (int k = 0; k < row; k++){
        matrix[k] = new int[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand()%10;
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return matrix;
}

int* randomVector(int height){

    int* vector = new int[height];

    for (int i = 0; i < height; ++i) {
        vector[i] = rand()%10;
        cout << vector[i] << "\n";
    }
    return vector;
}

void printMatrix(int* Matrix, int height){
    cout << "result\n";
    for (int i = 0; i < height; ++i) {
        cout << Matrix[i] << "\n";
    }
}

void multiply(int** matrix, int* vector, int height, int width){
    int count = 0;
    int* result = new int[height];
    count++;
    for (int i = 0; i < height; ++i) {
        count++;
        int summ_row = 0;
        count++;
        for (int j = 0; j < width; ++j) {
            count++;
            summ_row += matrix[i][j]*vector[j];
            count++;
        }
        count++;
        result[i] = summ_row;
        count++;
    }
    count++;

    cout << "operations = " << count << "\n";
    printMatrix(result, height);

}

int main() {
    int height = 6, width = 5;
    int** matrix = randomMatrix(height, width);
    int* vector = randomVector(width);
    multiply(matrix, vector, height, width);

    return 0;
}
