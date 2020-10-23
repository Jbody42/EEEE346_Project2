#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;
/*************************************************************************************
**************************************************************************************
*************************************************************************************/
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
    Matrix operator*(Matrix &mrhs);

};
/************************************************************************************
**************************************************************************************
*************************************************************************************/
Matrix Matrix::operator*(Matrix &mrhs){

    assert(this->cols == mrhs.rows);
    int x  = rows * cols;
    double prod[x];
    for (int i = 0; i < this->rows; i++){
        for(int j = 0; j < mrhs.cols; j++){

            prod[(i * mrhs.cols) + j] = 0;
            for(int k = 0; k < this->cols; k++){
                prod[(i * mrhs.cols) + j] = this->data[i][k] * mrhs.data[k][j];
            }
            
            
        }
    }
    Matrix addition_mat(this->rows, this->cols);
    addition_mat, setData(prod, this->rows*this->cols);

}
/**************************************************************************************
 * 
 *                                  PSEUDOCODE
 * 
multiplication& operator* (multiplication &output, const Matrix &m){

    // Some formatting definitions, dimmensions dim1 x dim2 are for Matrix A, meanwhile
    // dim 3 x dim4 are for Matrix B. dim2 SHOULD BE EQUAL TO dim3. If not then assert
    // fails

    this->dim1 = a.rows;
    this->dim2 = a.cols;
    this->dim3 = b.rows;
    this->dim4 = b.cols;

    assert(dim2 == dim3); //IF dim2 and dim3 are not equal, the code will BREAK

    for(int i = 0; i < dim1; i++){
        for(int j = 0; j < dim4; j++){
            
            m3.data[i][j] = 0;
            for(int k = 0; k < dim3; k++){
                m3.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }

        }
    }

}
**************************************************************************************/