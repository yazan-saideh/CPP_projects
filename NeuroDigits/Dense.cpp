//
// Created by miner on 11/01/2025.
//
#include "Dense.h"
#include "Matrix.h"
Dense::Dense(Matrix weights, Matrix bias,
    activation::ActivationFunction activation)
    : weights(weights), bias(bias), activation(activation){}


Matrix Dense::get_weights() const{
    return weights;
}
Matrix Dense::get_bias() const{
    return bias;
}
activation::ActivationFunction Dense::get_activation() const{
    return activation;
}
Matrix Dense::operator()(const Matrix &m) const{
    Matrix result = (weights * m) + bias;
    result = activation(result);
    return result;
}


