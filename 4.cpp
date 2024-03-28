#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <chrono>
#include <sstream>
#include <algorithm>

using namespace std::chrono;
using namespace std;


template <class T> void shellSort(std::vector<T>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}



void merge_sort1() {
    int len = 15;
    int n, n1, n2;
    for (int i = 1; i <= len; i *= 2) {
        ifstream inA("A.txt");
        ofstream outB("B.txt"), outC("C.txt");

        int k = 0;
        bool check = true;
        while (check) {
            for (int k = 0; k < i; k++) {
                if (inA >> n) outB << n << " ";
                else check = false;
            }
            for (int k = 0; k < i; k++) {
                if (inA >> n) outC << n << " ";
                else check = false;
            }
        }
        inA.close();
        outB.close();
        outC.close();
        ifstream B("B.txt"), C("C.txt");
        ofstream A("A.txt");
        vector<int> buffer;
        while (true) {
            while (B >> n1) {
                buffer.push_back(n1);
            }
            while (C >> n2){
                buffer.push_back(n2);
            }
            if (buffer.size() == 0)
                break;
            //shellSort(buffer);
            ostream_iterator<int> out_itr(A, " ");
            copy(buffer.begin(), buffer.end(), out_itr);
            buffer.clear();
        }
        B.close();
        C.close();
        A.close();
    }
}

bool compareFunction(std::string a, std::string b) { return a < b; }

void merge_sort2() {
    int len = 32;
    string n, n1, n2;
    for (int i = 1; i <= len; i *= 2) {
        ifstream inA("C:/Users/DIMOOON/source/repos/siaod_4_1/base.txt");
        ofstream outB("B.txt"), outC("C.txt");

        int k = 0;
        bool check = true;
        while (check) {
            for (int k = 0; k < i; k++) {
                if (getline(inA, n)) { 
                    outB << n << '\n';
                }
                else check = false;
            }
            for (int k = 0; k < i; k++) {
                if (getline(inA, n)) { 
                    outC << n << '\n';
                }
                else check = false;
            }
        }
        inA.close();
        outB.close();
        outC.close();
        ifstream B("B.txt"), C("C.txt");
        ofstream A("C:/Users/DIMOOON/source/repos/siaod_4_1/base.txt");
        vector<string> buffer;
        while (true) {
            while (getline(B, n1)) {
                buffer.push_back(n1);
            }
            while (getline(C, n2)) {
                buffer.push_back(n2);
            }
            if (buffer.size() == 0)
                break;
            sort(buffer.begin(), buffer.end(), compareFunction);
            
            ostream_iterator<string> out_itr(A, "\n");
            copy(buffer.begin(), buffer.end(), out_itr);
            buffer.clear();
        }
        B.close();
        C.close();
        A.close();
    }
}

void read_file() {
    ifstream file("base.txt");
    string n;
    while (!file.eof()) {
        n = "";
        getline(file, n);
        cout << n;
    }
}

int main()
{
    merge_sort2();
}
