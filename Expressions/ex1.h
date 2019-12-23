//
// Created by liad on 16/12/2019.
//

#ifndef MILESTONE1_EX1_H
#define MILESTONE1_EX1_H

#include <iostream>
#include <string>
#include "Expression.h"
#include <bits/stdc++.h>
#include <string>

class BinaryOperator : public Expression{
protected:
    Expression* right;
    Expression* left;
public:
    BinaryOperator(Expression* e1, Expression* e2) {
        this->left = e1;
        this->right = e2;
    }

    virtual double calculate() = 0;
    virtual  ~ BinaryOperator(){
        delete left;
        delete right;
    }
};


class Plus : public BinaryOperator{
public:
    Plus(Expression *left, Expression *right);
    double calculate();
    virtual ~Plus();


};

class Minus : public BinaryOperator{
public:
    Minus(Expression *left, Expression *right);
    double calculate();
    virtual ~Minus();

};

class Mul : public BinaryOperator{
public:
    Mul(Expression *left, Expression *right);
    double calculate();
    virtual ~Mul();

};


class Div : public BinaryOperator{
public:
    Div(Expression *left, Expression *right);
    double calculate();
    virtual ~Div();

};

class UnaryOperator : public Expression{
protected:
    Expression* e;
public:
    UnaryOperator(Expression* ex) {
        this->e = ex;
    }
    virtual double calculate() = 0;
};

class UPlus : public UnaryOperator{
public:
    UPlus(Expression *ex);
    double calculate();
    virtual ~UPlus();
};

class UMinus : public UnaryOperator{
public:
    UMinus(Expression *ex);
    double calculate();
    virtual ~UMinus();
};

class Value : public Expression{
private:
    double val;
public:
    Value(double value);
    double calculate();
    virtual ~Value();
};

class Variable : public Expression{
private:
    string name;
    double value;
public:
    Variable(string name,  double value);
    double calculate();
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double);
    Variable& operator-=(double);
    Variable& operator++(int);
    Variable& operator--(int);

};

class Interpreter {

    map<string, double> map1;

public:
    Expression* interpret(string s);
    void setVariables (string s);
    Expression* binaryOp (Expression* e1, Expression* e2, char o);
    Expression* unaryOp (Expression* e1, char o);
    int precedence (char o);
    string arrange (string s);
};


#endif //MILESTONE1_EX1_H
