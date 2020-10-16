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
    Matrix operator+(Matrix mat);

};



Matrix::Matrix(int rows, int cols){
    
    this->rows = rows;
    this->cols = cols;
}



Matrix Matrix::operator+(Matrix mat){

    if(this->rows != mat.rows || this->cols != mat.cols){
        "Assert Goes here";
    }
    int n = 0;
    double sum;
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            sum = this->data[i][j]+mat.data[i][j];
            if(n < this->cols){
                n++;
                cout << sum << " ";
            }
            else if (n == this->cols){
                cout << endl;
                n = 0;
            }
        }
    }


}




