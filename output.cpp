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

/*
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
*/

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



Matrix::~Matrix(){
    
    for(int i = 0; i < rows; i++){
        delete[] data[i]; 
    }
    delete[] data;
    
}


int main(){
    int in1;
    int in2;
    cout << "Input rows: ";
    cin >> in1;
    cout << endl;
    cout << "Input cols: ";
    cin >> in2;
    cout << endl;

    Matrix a(in1, in2);


    cout << "Input data: ";
    cin >> a;
    cout << endl;
    cout << a;

    Matrix b(in1, in2);
    cout << "Input data ";
    cin >> b; 
    cout << endl;
    cout << b << endl;

    b = a;

    cout << b << endl;


}

