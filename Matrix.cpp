#include "Matrix.h"
using namespace std;






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





Matrix::Matrix(const Matrix &mC)
{
    rows = mC.rows;
    cols = mC.cols;
    data = new double*[rows];
    for(int i = 0; i < rows; i++){
        data[i] = new double [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = mC.data[i][j];
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

Matrix Matrix::operator+(Matrix &mrhs){

    assert(this->rows == mrhs.rows && this->cols == mrhs.cols);
    Matrix addition_mat(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            addition_mat.data[i][j] = this->data[i][j]+mrhs.data[i][j];
            
        }
    }
    return addition_mat;
}


Matrix& Matrix::operator+=(const Matrix &mrhs){

    assert(this->rows == mrhs.rows || this->cols == mrhs.cols);
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            this->data[i][j]= this->data[i][j]+mrhs.data[i][j];
            
        }
    }
    return *this;
}


Matrix Matrix::operator-(Matrix &mrhs){

    assert(rows == mrhs.rows);
    assert(cols == mrhs.cols);
    Matrix temp(rows, cols);

    
    for (int i = 0; i < rows; i++){
        
        for(int j = 0; j < cols; j++){
            temp.data[i][j] = data[i][j] - mrhs.data[i][j];
        }
    }

    return temp ;
}



Matrix& Matrix::operator-=(const Matrix &mrhs){

    assert(this->rows == mrhs.rows || this->cols == mrhs.cols);
    for (int i = 0; i < this->rows; i++){
        
        for(int j = 0; j < this->cols; j++){
            this->data[i][j]= this->data[i][j]-mrhs.data[i][j];
            
        }
    }
    return *this;
}


Matrix Matrix::operator*(const Matrix &mrhs){

    assert(this->cols == mrhs.rows);
    int x  = rows * cols;
	Matrix mult_mat(this->rows, mrhs.cols);
    for (int i = 0; i < this->rows; i++){
        for(int j = 0; j < mrhs.cols; j++){

            mult_mat.data[i][j] = 0;
            for(int k = 0; k < this->cols; k++){
                mult_mat.data[i][j]+= this->data[i][k] * mrhs.data[k][j];
            }  
        }
    }

	return mult_mat;

}





Matrix::~Matrix(){
    
    for(int i = 0; i < rows; i++){
        delete[] data[i]; 
    }
    delete[] data;
    
}



