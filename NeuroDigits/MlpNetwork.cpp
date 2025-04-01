#include "MlpNetwork.h"
//
// Created by miner on 11/01/2025.
//
MlpNetwork::MlpNetwork(const Matrix
    weights[MLP_SIZE], const Matrix biases[MLP_SIZE]):
layers{(Dense(weights[0], biases[0],
    activation::relu))
    ,(Dense(weights[1], biases[1],
        activation::relu)),
    (Dense(weights[2],biases[2],
        activation::relu)),
    (Dense(weights[3], biases[3],
        activation::softmax))} {}


digit MlpNetwork::operator()
(const Matrix &input) const{
    Matrix result(input);
    for (int i = 0; i < MLP_SIZE; i++) {
        result = layers[i](result);

    }
    unsigned int max = result.argmax();
    float maxVal = result[max];
    digit output = {max,maxVal};
    return output;


}