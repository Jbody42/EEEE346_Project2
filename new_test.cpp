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
    void print();  
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend ostream& operator << (ostream &output, const Matrix &data);
    friend istream& operator >> (istream &input, const Matrix &data);
    Matrix& operator = (const Matrix &m);
    Matrix operator-=(Matrix mat);
    Matrix operator+=(Matrix mat);
    Matrix operator+(Matrix mat);
    Matrix operator-(Matrix mat);

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


Matrix operator+ (const Matrix &m1, const Matrix &m2){

    assert(m1.rows == m2.rows);
    assert(m1.cols == m2.cols);
    int rows1 = m1.rows;
    int cols1 = m1.cols; 

    double tempData[rows1][cols1];
    for (int i = 0; i < rows1; i++){
        
        for(int j = 0; j < cols1; j++){
            tempData[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }

    return ;
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

Matrix Matrix::operator+=(Matrix mat){

    assert(this->rows != mat.rows || this->cols != mat.cols);
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            this->data[i][j]= this->data[i][j]+mat.data[i][j];
            
        }
    }

}

Matrix Matrix::operator-=(Matrix mat){

    assert(this->rows != mat.rows || this->cols != mat.cols);

    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            this->data[i][j]= this->data[i][j]-mat.data[i][j];
            
        }
    }

}





Matrix Matrix::operator-(Matrix mat){

    assert(this->rows != mat.rows || this->cols != mat.cols);
    int x  = rows * cols;
    double* diff = new double[x];
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            diff[(i*this->cols)+j] = this->data[i][j]-mat.data[i][j];
            
        }
    }
    Matrix addition_mat(this->rows, this->cols);
    addition_mat, setData(diff, this->rows*this->cols);
    return addition_mat;

}

Matrix Matrix::operator+(Matrix mat){

    assert(this->rows != mat.rows || this->cols != mat.cols);
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

    b = a;

    cout << b << endl;


}

