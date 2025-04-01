// Dense.h
#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

// Insert Dense class here...
class Dense {
private:
    Matrix weights;
    Matrix bias;
    activation::ActivationFunction activation;
public:
    Dense(Matrix weights, Matrix bias, activation::ActivationFunction activation);


    Matrix get_weights() const;
    Matrix get_bias() const;
    activation::ActivationFunction get_activation() const;

    Matrix operator()(const Matrix &m) const;


};









#endif //DENSE_H