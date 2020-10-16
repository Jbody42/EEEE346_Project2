#include <iostream>
#include <stdio.h>
using namespace std;




class Matrix{
private:
    int rows, cols;
    double **data;
    
public:
    Matrix(int, int);
    Matrix(const Matrix &m2);
    ~Matrix();
    void setData(double * const, const int);
    void print();  
};

Matrix::Matrix(int rows, int cols){
    
    this->rows = rows;
    this->cols = cols;
    
    data = new double *[rows];
    
    for(int i  = 0; i < rows; i++){
        data[i] = new double[cols];
        
        for(int j = 0; j < cols; j++)
            data[i][j] = 0;
    }
    
}

Matrix::Matrix(const Matrix &m2)
{
    this->rows = m2.rows;
    this->cols = m2.cols;
    
    data = new double *[rows];
    
    for(int i  = 0; i < rows; i++){
        data[i] = new double[cols];
        
        for(int j = 0; j < cols; j++)
            data[i][j] = m2.data[i][j];
    }
}

Matrix::~Matrix(){
    
    for(int i = 0; i < rows; i++){
        delete [] data[i];
    }
    delete [] data;
}