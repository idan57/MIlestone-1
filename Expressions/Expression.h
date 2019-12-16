//
// Created by liad on 16/12/2019.
//

#ifndef MILESTONE1_EXPRESSION_H
#define MILESTONE1_EXPRESSION_H

using namespace std;

/**
 * Expression Interface
 */
class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression() {}
};


#endif //MILESTONE1_EXPRESSION_H
