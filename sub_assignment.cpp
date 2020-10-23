#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;




class Matrix{
private:
    int rows, cols;
    double **data;
    
public:
    Matrix(int r, int c){
        this->rows = r;
        this->cols = c;
    }
    Matrix(const Matrix &m2);
    ~Matrix();
    void setData(double * const, const int);
    void print();  
    Matrix operator-=(Matrix mat);

};






Matrix Matrix::operator-=(Matrix mat){

    assert(this->rows != mat.rows || this->cols != mat.cols);
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            this->data[i][j]= this->data[i][j]-mat.data[i][j];
            
        }
    }

}