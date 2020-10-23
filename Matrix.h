#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;




class Matrix{
private:
    int rows, cols;
    double **data;
    
public:
    Matrix(int, int);
    Matrix(const Matrix &mrhs);
    ~Matrix();
    Matrix operator+(Matrix &mrhs);
    Matrix operator-(Matrix &mrhs);
    Matrix& operator+=(const Matrix &mrhs);
    Matrix& operator-=(const Matrix &mrhs);
    Matrix operator*(const Matrix &mrhs);
    friend ostream& operator << (ostream &output, const Matrix &data);
    friend istream& operator >> (istream &input, const Matrix &data);
    Matrix& operator = (const Matrix &m);


};
#endif