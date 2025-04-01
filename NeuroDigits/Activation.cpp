//
// Created by miner on 10/01/2025.
//
#include "Activation.h"
#include <cmath>


namespace activation {
    Matrix relu(const Matrix &m) {
        int row = m.get_rows();
        int col = m.get_cols();
        Matrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                float value = m(i, j);
                result(i, j) = std::max(0.0f, value);
            }
        }
        return result;
    }
    Matrix softmax(const Matrix &m) {
        int row = m.get_rows();
        int col = m.get_cols();
        Matrix result(row, col);
        float sum_exp = 0;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                result(j, i) = std::exp(m(j, i));
                sum_exp += result(j, i);
            }
        }
        for (int j = 0; j < row; j++) {
            for (int i = 0; i < col; i++) {
                result(j, i) /= sum_exp;
            }
        }

        return result;
    }



    }
