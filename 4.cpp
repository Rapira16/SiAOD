#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;

int c = 0;

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

bool compareFunction(std::string a, std::string b) { return a < b; }

void merge_sort1() {
    int len = 15;
    int output, input_1, input_2;
    for (int i = 1; i <= len; i *= 2) {
        ifstream inA("C:/Users/DIMOOON/source/repos/siaod_4_1/A.txt");
        ofstream outB("B.txt"), outC("C.txt");
        bool flag = true;
        while (flag) {
            for (int k = 0; k < i; k++) {
                if (inA >> output) outB << output << " ";
                else flag = false;
            }
            for (int k = 0; k < i; k++) {
                if (inA >> output) outC << output << " ";
                else flag = false;
            }
        }
        inA.close();
        outB.close();
        outC.close();
        ifstream B("B.txt"), C("C.txt");
        ofstream A("A.txt");
        vector<int> buffer;
        while (true) {
            while (B >> input_1) {
                buffer.push_back(input_1);
            }
            while (C >> input_2){
                buffer.push_back(input_2);
            }
            if (buffer.size() == 0)
                break;
            shellSort(buffer);
            ostream_iterator<int> out_itr(A, " ");
            copy(buffer.begin(), buffer.end(), out_itr);
            buffer.clear();
        }
        B.close();
        C.close();
        A.close();
    }
}

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
                    c++;
                }
                else check = false;
            }
            for (int k = 0; k < i; k++) {
                if (getline(inA, n)) { 
                    outC << n << '\n';
                    c++;
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
            c += 16;
            copy(buffer.begin(), buffer.end(), out_itr);
            buffer.clear();
        }
        B.close();
        C.close();
        A.close();
    }
}





void naturalsort1()
{
    int len = 20;
    int output, input_1, input_2;
    vector<int> buffer;
    for (int gap = 1; gap <= len; gap *= 2) {
        bool flag = 1;
        ifstream A_2("C:/Users/DIMOOON/source/repos/siaod_4_1/A_2.txt");
        ofstream B("C:/Users/DIMOOON/source/repos/siaod_4_1/B.txt"), C("C:/Users/DIMOOON/source/repos/siaod_4_1/C.txt");
        vector<int> buffer_1, buffer_2;
        while (flag) {
            for (int i = 0; i < gap; i++) {
                if (A_2 >> output)
                    buffer.push_back(output);
            }
            if (buffer.size() == 0)
                break;
            shellSort(buffer);
            for (int i = 0; i < buffer.size(); i++) {
                B << buffer[i] << " ";
                c++;
            }
            buffer.clear();
            for (int k = 0; k < gap; k++) {
                if (A_2 >> output)
                    buffer.push_back(output);
            }
            if (buffer.size() == 0)
                break;
            shellSort(buffer);
            for (int i = 0; i < buffer.size(); i++) {
                C << buffer[i] << " ";
                c++;
            }
            buffer.clear();
        }
        B.close();
        C.close();
        A_2.close();
        ifstream B_2("C:/Users/DIMOOON/source/repos/siaod_4_1/B.txt"), C_2("C:/Users/DIMOOON/source/repos/siaod_4_1/C.txt");
        ofstream A_2_2("C:/Users/DIMOOON/source/repos/siaod_4_1/A_2.txt");
        while (true) {
            for (int j = 0; j < gap; j++) {
                if (B_2 >> input_1)
                    buffer_1.push_back(input_1);
                else
                    break;
            }
            for (int j = 0; j < gap; j++) {
                if (C_2 >> input_2)
                    buffer_2.push_back(input_2);
                else
                    break;
            }
            if (buffer_1.size() == 0 && buffer_2.size() == 0)
                break;
            int size_buffer_1 = 0, size_buffer_2 = 0;
            while (size_buffer_1 < buffer_1.size() && size_buffer_2 < buffer_2.size()) {
                if (buffer_1[size_buffer_1] < buffer_2[size_buffer_2]) {
                    A_2_2 << buffer_1[size_buffer_1] << " ";
                    c++;
                    size_buffer_1++;
                }
                else {
                    A_2_2 << buffer_2[size_buffer_2] << " ";
                    size_buffer_2++;
                }
            }
            for (size_buffer_1; size_buffer_1 < buffer_1.size(); size_buffer_1++) {
                A_2_2 << buffer_1[size_buffer_1] << " ";
                c++;
            }
            for (size_buffer_2; size_buffer_2 < buffer_2.size(); size_buffer_2++) {
                A_2_2 << buffer_2[size_buffer_2] << " ";
                c++;
            }
            buffer_1.clear();
            buffer_2.clear();
        }
        B_2.close();
        C_2.close();
        A_2_2.close();
    }
}

void naturalsort2()
{
    int len = 8;
    string output, input_1, input_2;
    int gap = 1;
    vector<string> buffer;
    for (int gap = 1; gap <= len; gap *= 2) {
        bool flag = 1;
        ifstream base("C:/Users/DIMOOON/source/repos/siaod_4_1/base.txt");
        ofstream B("C:/Users/DIMOOON/source/repos/siaod_4_1/B.txt"), C("C:/Users/DIMOOON/source/repos/siaod_4_1/C.txt");
        vector<string> buffer_1, buffer_2;
        while (flag) {
            for (int i = 0; i < gap; i++) {
                if (getline(base, output))
                    buffer.push_back(output);
            }
            if (buffer.size() == 0)
                break;
            sort(buffer.begin(), buffer.end(), compareFunction);
            for (int i = 0; i < buffer.size(); i++) {
                B << buffer[i] << "\n";
                c++;
            }
            buffer.clear();
            for (int k = 0; k < gap; k++) {
                if (getline(base, output))
                    buffer.push_back(output);
            }
            if (buffer.size() == 0)
                break;
            sort(buffer.begin(), buffer.end(), compareFunction);
            for (int i = 0; i < buffer.size(); i++) {
                C << buffer[i] << "\n";
                c++;
            }
            buffer.clear();
        }
        B.close();
        C.close();
        base.close();
        flag = 0;
        ifstream B_2("C:/Users/DIMOOON/source/repos/siaod_4_1/B.txt"), C_2("C:/Users/DIMOOON/source/repos/siaod_4_1/C.txt");
        ofstream base_2("C:/Users/DIMOOON/source/repos/siaod_4_1/base.txt");
        while (true) {
            for (int j = 0; j < gap; j++) {
                if (getline(B_2, input_1))
                    buffer_1.push_back(input_1);
                else
                    break;
            }
            for (int j = 0; j < gap; j++) {
                if (getline(C_2, input_2))
                    buffer_2.push_back(input_2);
                else
                    break;
            }
            if (buffer_1.size() == 0 && buffer_2.size() == 0)
                break;
            int size_buffer_1 = 0, size_buffer_2 = 0;
            while (size_buffer_1 < buffer_1.size() && size_buffer_2 < buffer_2.size()) {
                if (buffer_1[size_buffer_1] < buffer_2[size_buffer_2]) {
                    base_2 << buffer_1[size_buffer_1] << "\n";
                    c++;
                    size_buffer_1++;
                }
                else {
                    base_2 << buffer_2[size_buffer_2] << "\n";
                    c++;
                    size_buffer_2++;
                }
            }
            for (size_buffer_1; size_buffer_1 < buffer_1.size(); size_buffer_1++) {
                base_2 << buffer_1[size_buffer_1] << "\n";
                c++;
            }
            for (size_buffer_2; size_buffer_2 < buffer_2.size(); size_buffer_2++) {
                base_2 << buffer_2[size_buffer_2] << "\n";
                c++;
            }
            buffer_1.clear();
            buffer_2.clear();
        }
        B_2.close();
        C_2.close();
        base_2.close();
    }
}


void main()
{
    auto start = std::chrono::steady_clock::now();
    naturalsort2();
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;
    cout << c;
}

