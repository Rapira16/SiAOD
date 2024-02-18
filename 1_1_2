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
    for (int i = 0; i < height; ++i) {
        cout << Matrix[i] << "\n";
    }
}

void multiply(int** matrix, int* vector, int height, int width){
    int* result = new int[height];
    for (int i = 0; i < height; ++i) {
        int summ_row = 0;
        for (int j = 0; j < width; ++j) {
            summ_row += matrix[i][j]*vector[j];
        }
        result[i] = summ_row;
    }

    printMatrix(result, height);

}

int main() {
    int height = 3, width = 2;
    int** matrix = randomMatrix(height, width);
    int* vector = randomVector(width);
    multiply(matrix, vector, height, width);

    return 0;
}
