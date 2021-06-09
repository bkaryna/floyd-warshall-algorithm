//
// Created by Karyna Babenko on 02/06/2021.
//

#ifndef FLOYD_WARSHALL_ALGORITHM_MATRIX_H
#define FLOYD_WARSHALL_ALGORITHM_MATRIX_H
#include <iostream>
#include <string>
using namespace std;
const int INF = 10500;
const int NIL = -10500;

struct Matrix {
    int** data;
    int size;

    Matrix(int n){
        size = n;
        data = new int* [n];
        for (int i = 0; i<n; i++)
            data[i] = new int[n];
        initialize();
    }

    Matrix(Matrix const &A){
        size = A.size;
        data = new int* [size];
        for (int i = 0; i<size; i++)
            data[i] = new int[size];
        *this = A;
    }

    ~Matrix(){
        for (int i = 0; i<size; i++)
            delete[] data[i];
        delete[] data;
    }

    void print_D(){
        for (int i = 0; i<size; i++){
            for (int j = 0; j<size; j++){
                cout<<(data[i][j] == INF ? "inf\t\t" : to_string(data[i][j])+"\t\t");
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void print_P(){
        for (int i = 0; i<size; i++){
            for (int j = 0; j<size; j++){
                cout<<(data[i][j] == NIL ? "nil\t\t" : to_string(data[i][j])+"\t\t");
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void initialize(){
        for (int i = 0; i<size; i++) {
            for (int j = 0; j < size; j++) {
                data[i][j] = 0;
            }
        }
    }

    Matrix & operator=(const Matrix &A ){
        this->size = A.size;
        this->data = new int* [size];
        for (int i = 0; i<size; i++)
            this->data[i] = new int[size];

        if (this != &A) {
            for (int i = 0; i < A.size; i++)
                for (int j = 0; j < A.size; j++)
                    this->data[i][j] = A.data[i][j];
        }
        return *this;
    }
};


#endif//FLOYD_WARSHALL_ALGORITHM_MATRIX_H
