//
// Created by miner on 09/01/2025.
//
// Matrix.h

#include <iostream>
#include "Matrix.h"
#include <cmath>

#define ERORR_MATRIX_SIZE "Invalid Matrix Size:"\
" Dimensions must be greater than 0."
#define MULT_ERROR "Matrix dimensions"\
"do not align for multiplication"
#define INDEX_ERROR "Invalid Index"
#define FILL_ERROR "Insufficient data to fill the matrix"
// You don't have to use the struct. Can help you with MlpNetwork.h

// Insert Matrix class here...



Matrix::Matrix(int row, int col):rows(row),cols(col) {
    if(row <= 0 || col <= 0) {
        throw std::invalid_argument(ERORR_MATRIX_SIZE);
    }
    data = new float [row * col]();
}

Matrix::Matrix():rows(1),cols(1)
{
    data = new float [1]();
}
Matrix::Matrix(const Matrix& m):rows(m.rows),cols(m.cols) {
    data = new float [rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = m.data[i];
    }
}
Matrix::~Matrix() {
    delete[] data;
}
int Matrix::get_rows() const
{
    return rows;
}
int Matrix:: get_cols() const{
    return cols;
}
Matrix &Matrix:: transpose() {
    float *new_data = new float[cols* rows]();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_data[j*rows + i] = data[i * cols + j];
        }
    }
    delete[] data;
    data = new_data;
    std::swap(rows, cols);

    return *this;
}
Matrix &Matrix::vectorize(){
    rows = rows * cols;
    cols = 1;
    return *this;
}

void Matrix::plain_print() const {
    for (int i = 0; i < rows * cols; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

Matrix Matrix::dot(const Matrix &other)const{
if(other.rows != rows || other.cols != cols) {
    throw std::invalid_argument(ERORR_MATRIX_SIZE);
}
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i*cols + j] =
                data[i*cols + j] * other.data[i*cols + j];
        }
    }
    return result;
}

float Matrix::norm() const {
    float result = 0;
    for (int i = 0; i < rows * cols; i++) {
        result += (data[i] * data[i]);
    }
    return std::sqrt(result);
}
// [1,2,3| |4,5,6] there is 2 rows so there is two pivots in each row
// we take the first element in the first
// row and make sure that all of the elements
// below it are 0 by multiplying the first row and subtracting it
// for one dimensional array we have i*cols +j to irritate for each item
Matrix Matrix::rref() const{
    Matrix result = Matrix(*this);
    float pivot = 0;
    for(int i = 0; i < rows; i++) {
        int pivot_index = i*cols + i;
        pivot = data[pivot_index];
        if (data[pivot_index] == 0) {
            for (int k = i + 1; k < rows; k++) {
                if (data[k * cols + i] != 0) {
                    for (int j = 0; j < cols; j++) {
                        std::swap(data[i * cols + j],
                            data[k * cols + j]);
                    }
                    break;
                }
            }
        }
        if(pivot == 0) {
            continue;
        }
        if(pivot != 1) {
            for(int j = 0; j < cols; j++) {
                data[i*cols + j] /= pivot;
                // in the example above after this we
                // the matrix [1,2,3 | (4/5),1,(6/5)]
                // now we want to make sure the every item
                // below or above the number one are 0
            }
        }
        for(int k =0; k < rows; k++) {
            if(k != i) {
                float factor = data[k * cols + i];
                for(int l = 0; l < cols; l++) {
                    if(data[k * cols + l] != 0) {
                        data[k * cols + l] -= data[i * cols + l] * factor;
                    }
                }
            }
        }
    }
    return result;
}

int Matrix::argmax() const {
    int index = 0;
    float max_value = data[0];
    for (int i = 1; i < rows * cols; ++i) {
        if (data[i] > max_value) {
            max_value = data[i];
            index = i;
        }
    }
    return index;
}

float Matrix::sum() const {
    float sum = 0;
    for (int i = 0; i < rows *cols; i++) {
            sum += data[i];
    }
    return sum;
}

Matrix& Matrix::operator+=(const Matrix &other) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i*cols + j] += other.data[i*cols + j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i*cols + j] =data[i*cols + j]
                + other.data[i*cols + j];
        }
    }
    return result;

}

Matrix& Matrix::operator=(const Matrix &other) {
    if(data != nullptr) {
        delete[] data;
    }
    if (rows != other.rows || cols != other.cols) {
        rows = other.rows;
        cols = other.cols;
    }
    data = new float[rows * cols];
    for (int i = 0; i < rows*cols; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) const{
    if (cols != other.rows) {
        throw std::invalid_argument(MULT_ERROR);
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            float sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += data[i * cols + k] *
                    other.data[k * other.cols + j];
            }
            result.data[i * result.cols + j] = sum;
        }
    }
    return result;
}
Matrix Matrix::operator*(const float &other) const{
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] =data[i] *  other;
    }
    return result;
}
Matrix operator*(float scaler , const Matrix &other)  {
    int rows = other.get_rows();
    int cols = other.get_cols();
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = scaler *  other.data[i];
    }
    return result;
}

float &Matrix::operator()(int row , int col) const{
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::invalid_argument(INDEX_ERROR);
    }
    return data[row * cols + col];
}
float &Matrix::operator[](int k) const {
    if (k < 0 || k >= rows *cols) {
        throw std::invalid_argument(INDEX_ERROR);
    }
    return data[k];
}
std::ostream& operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (m.data[i * m.cols + j] > 0.1) {
                os << "**";
            } else {
                os << "  ";
            }
        }
        os << "\n";
    }
    return os;
}
std::istream& operator>>(std::istream& is, Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (!is.read(reinterpret_cast<char*>
                (&m.data[i * m.cols + j]), sizeof(float))) {
                throw std::runtime_error(FILL_ERROR);
            }
        }
    }
    return is;
}


