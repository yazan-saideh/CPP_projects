// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <ostream>


// You don't have to use the struct. Can help you with MlpNetwork.h
struct matrix_dims {
    int rows, cols;
};


// Insert Matrix class here...
class Matrix {
private:
    int rows, cols;
    float* data;
    int col_{};

public:

    Matrix(int row, int col);
    Matrix();
    Matrix(const Matrix& m);
    ~Matrix();
    int get_rows() const;
    int get_cols() const;
    Matrix &transpose();
    Matrix &vectorize();
    void plain_print() const;
    Matrix dot(const Matrix& other) const;
    float norm() const;
    Matrix rref() const;
    int argmax() const;
    float sum() const;
    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix &operator=(const Matrix& other) ;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(const float& other)const;


    friend Matrix operator*(float scalar,const Matrix& other);
    float &operator()(int row, int col) const;
    float &operator[](int k) const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};



#endif //MATRIX_H