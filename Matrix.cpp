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
    Matrix(const Matrix &m2);
    ~Matrix();
    void setData(double * const, const int);
    Matrix operator+(const Matrix &m1);
    Matrix operator-(const Matrix &m1);
    Matrix operator+=(const Matrix &m1);
    friend ostream& operator << (ostream &output, const Matrix &data);
    friend istream& operator >> (istream &input, const Matrix &data);
    Matrix& operator = (const Matrix &m);


};



Matrix::Matrix(int rows, int cols){
    
    this->rows = rows;
    this->cols = cols;
    data = new double*[rows];
    for(int i = 0; i < rows; i++){
        data[i] = new double [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data [i][j] = 0;
        }
    }
}





Matrix::Matrix(const Matrix &m2)
{
    rows = m2.rows;
    cols = m2.cols;
    data = new double*[rows];
    for(int i = 0; i < rows; i++){
        data[i] = new double [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = m2.data[i][j];
        }
    }    
}

istream& operator >> (istream &input, const Matrix &m){

    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j <m.cols; j++){
            input >> m.data[i][j];
        }
    } 
    return input;
}

ostream& operator << (ostream &output, const Matrix &m){
    for(int i = 0; i <  m.rows; i++){
        for(int j = 0; j < m.cols; j++){
            output << m.data[i][j] << " ";
        }
        output << endl;
    }
    return output;
};

Matrix & Matrix::operator = (const Matrix &m) {
    rows = m.rows;
    cols = m.cols;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = m.data[i][j];
        }
    }

    return *this;

}

Matrix Matrix::operator+(Matrix mat){

    assert(rows == mat.rows && cols == mat.cols);
    const int x  = this->rows * this->cols;
    double* sum = new double[x];
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            sum[(i*this->cols)+j] = this->data[i][j]+mat.data[i][j];
            
        }
    }
    Matrix addition_mat(this->rows, this->cols);
    addition_mat, setData(sum, this->rows*this->cols);
    return addition_mat;
}

/*
Matrix Matrix::operator+(const Matrix &m1){

    assert(rows == m1.rows);
    assert(cols == m1.cols);
    Matrix temp(rows, cols);

    
    for (int i = 0; i < rows; i++){
        
        for(int j = 0; j < cols; j++){
            temp.data[i][j] = m1.data[i][j] + data[i][j];
        }
    }

    return temp ;
}
*/

Matrix Matrix::operator-(const Matrix &m1){

    assert(rows == m1.rows);
    assert(cols == m1.cols);
    Matrix temp(rows, cols);

    
    for (int i = 0; i < rows; i++){
        
        for(int j = 0; j < cols; j++){
            temp.data[i][j] = data[i][j] - m1.data[i][j];
        }
    }

    return temp ;
}

/*
Matrix Matrix::operator-(const Matrix &m1){

    //assert(m1.cols == cols);

    
    for (int i = 0; i < rows; i++){
        
        for(int j = 0; j < cols; j++){
            data[i][j] = data[i][j] + m1.data[i][j];
        }
    }

    return  ;
}
*/


Matrix::~Matrix(){
    
    for(int i = 0; i < rows; i++){
        delete[] data[i]; 
    }
    delete[] data;
    
}


int main(){
    int in1;
    int in2;
    cout << "Input rows: \n";
    cin >> in1 >> in2;
    cout << endl;

    Matrix a(in1, in2);


    cout << "Input data: " << endl;
    cin >> a;
    cout << endl;
    cout << a;

    cout << "Input rows: \n";
    cin >> in1 >> in2;
    cout << endl;
   
    Matrix b(in1, in2);
    cout << "Input data: " << endl;
    cin >> b; 
    cout << endl;
    cout << b << endl;

    cout << a - b << endl;




}

