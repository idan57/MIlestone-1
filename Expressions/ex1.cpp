//
// Created by liad on 07/11/2019.
//

#include "ex1.h"
#include <bits/stdc++.h>
#include <string>



Plus::Plus(Expression *e1, Expression *e2) : BinaryOperator(e1, e2) {}
double Plus::calculate() {
    return this->left->calculate() + this->right->calculate();
}
Plus::~Plus() {}



Minus::Minus(Expression *e1, Expression *e2) : BinaryOperator(e1, e2) {}
double Minus::calculate() {
    return this->left->calculate() - this->right->calculate();
}
Minus::~Minus() {}



Mul::Mul(Expression *e1, Expression *e2) : BinaryOperator(e1, e2) {}
double Mul::calculate() {
    return this->left->calculate() * this->right->calculate();
}
Mul::~Mul() {}



Div::Div(Expression *e1, Expression *e2) : BinaryOperator(e1, e2) {}
double Div::calculate() {
    if (this->right->calculate() != 0) {
        return this->left->calculate() / this->right->calculate();
    }
    else {
        throw "division by zero!";
    }

}
Div::~Div() {}

UPlus::UPlus(Expression *ex) : UnaryOperator(ex) {}
double UPlus::calculate() {
    return this->e->calculate();
}
UPlus::~UPlus() {}


UMinus::UMinus(Expression *ex) : UnaryOperator(ex) {}
double UMinus::calculate() {
    return -this->e->calculate();
}
UMinus::~UMinus() {}


Value::Value(double val1) : val(val1) {}
double Value::calculate() {
    return this->val;
}

Value::~Value() {}


Variable::Variable(string name1, double value1) {
    this->name = name1;
    this->value = value1;
}

double Variable::calculate() {
    return this->value;
}

Variable& Variable::operator++() {
    ++this->value;
    return *this;
}
Variable& Variable::operator--() {
    --this->value;
    return *this;
}
Variable& Variable::operator+=(double a) {
    this->value+=a;
    return *this;
}
Variable& Variable::operator-=(double a) {
    this->value-=a;
    return *this;
}

Variable& Variable:: operator++(int) {
    this->value++;
    return *this;
}
Variable& Variable:: operator--(int) {
    this->value--;
    return *this;
}

Expression* Interpreter::interpret(string s) {


    // check if the input is valid

    int countOpen = 0;
    int countClose = 0;
    for (unsigned int k = 0; k < s.length(); k++) {
        if (!(s[k] == ')' || s[k] == '(' ||  isdigit(s[k]) || s[k] == '.' || s[k] == '_'
              || (s[k] >= 'a' && s[k] <= 'z') || (s[k] >= 'A' && s[k] <= 'Z') || s[k] == '+'
              || s[k] == '-' || s[k] == '*' || s[k] == '/')) {
            throw "bad input";
        }


        if (s[k] == '(') {
            countOpen++;
        }
        if (s[k] == ')') {
            countClose++;
        }
        if (countClose > countOpen) {
            throw "bad input";
        }
        if ((s[k] == '+' && s[k+1] == '+') || (s[k] == '-' && s[k+1] == '-') || (s[k] == '*' && s[k+1] == '*')
            || (s[k] == '/' && s[k+1] == '/') || (s[k] == '+' && s[k+1] == '-') || (s[k] == '+' && s[k+1] == '*')
            || (s[k] == '+' && s[k+1] == '/') || (s[k] == '-' && s[k+1] == '+') || (s[k] == '-' && s[k+1] == '*')
            || (s[k] == '-' && s[k+1] == '/') || (s[k] == '*' && s[k+1] == '+') || (s[k] == '*' && s[k+1] == '-')
            || (s[k] == '*' && s[k+1] == '/') || (s[k] == '/' && s[k+1] == '+') || (s[k] == '/' && s[k+1] == '-')
            || (s[k] == '/' && s[k+1] == '*')) {
            throw "bad input";
        }
    }

    if (!(countOpen == countClose)) {
        throw "bad input";
    }




    stack<double> values;
    stack<char> operators;
    stack<Expression*> exp;
    string st = "";
    Expression *e;

    if (s[0] == '+' ) {
        s[0] = '&';
    }
    if (s[0] == '-') {
        s[0] = '%';
    }

    for (unsigned int i = 2; i < s.length(); i++) {

        if (s[i] == '+' && s[i+1] == '(' && s[i-1] == '(') {
            s[i] = '&';
        }
        if (s[i] == '-' && s[i+1] == '(' && s[i-1] == '(') {
            s[i] = '%';
        }
    }


    for (unsigned int i = 0; i < s.length(); i++) {


        if (isdigit(s[i]))  {
            while ((i < s.length() && isdigit(s[i])) || (i < s.length() && s[i] == '.')) {
                st = st + s[i];
                i++;
            }
            i--;
            //values.push(stod(st));
            exp.push(new Value(stod(st)));
            st = "";
        }

        else if ((((s[i] == '-' || s[i] == '+') && (isdigit(s[i+1]) || (s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z'))) && i > 0 && s[i-1] == '(')
                 || (i == 0 && s[i] == '-' && (isdigit(s[i+1]) || (s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z')))) {
            char c = s[i];
            if (isdigit(s[i + 1])) {
                while (s[i + 1] == '.' || isdigit(s[i + 1])) {
                    st = st + s[i + 1];
                    i++;
                }
                //i--;
                if (c == '-') {
                    exp.push(new Value(-stod(st)));
                }
                else {
                    exp.push(new Value(stod(st)));
                }
                st = "";

            }
            else {
                string st1 = "";
                while (s[i+1] ==  '_' || isdigit(s[i+1]) || (s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z')) {
                    st1 = st1 + s[i+1];
                    i++;
                }
                map<string, double>::iterator p;
                p = map1.find(st1);
                if(p != map1.end()) {
                    if (c == '-') {
                        exp.push(new Value(-p->second));
                    }
                    else {
                        exp.push(new Value(p->second));
                    }
                    st1 = "";
                }
                else {
                    throw "Key not in map. invalid input";
                }


            }
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '_')) {
            map<string, double>::iterator p;
            string str = "";
            // if (s[i+1] != '_' && !isdigit(s[i+1])) {
            str+=s[i];
            while (s[i+1] ==  '_' || isdigit(s[i+1]) || (s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z')) {
                str = str + s[i+1];
                i++;
            }
            p = map1.find(str);
            if(p != map1.end()) {
                exp.push(new Value(p->second));
            }
            else {
                throw "Key not in map. invalid input";
            }

        }
        else if (s[i] == '(') {
            operators.push(s[i]);
        }
        else if (s[i] == ')') {

            while (!operators.empty() && operators.top() != '(' ) {
                char op = operators.top();
                operators.pop();
                // need to check if the next op is ( so its unary!! need take care..

                if (op == '%' || op == '&') {
                    Expression *e1 = exp.top();
                    exp.pop();
                    e = unaryOp(e1, op);
                    exp.push(e);
                } else {

                    Expression *e2 = exp.top();
                    exp.pop();
                    Expression *e1 = exp.top();
                    exp.pop();
                    e = binaryOp(e1, e2, op);
                    exp.push(e);
                }
            }

            if (!operators.empty()) {
                operators.pop();
            }

        }


        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '&' || s[i] == '%')  {

            while (!operators.empty() && precedence(operators.top()) >= precedence(s[i])) {
                char op = operators.top();
                operators.pop();


                if (op == '&' || op == '%') {
                    Expression *e1 = exp.top();
                    exp.pop();
                    e = unaryOp(e1, op);
                    exp.push(e);
                }

                else {
                    Expression *e2 = exp.top();
                    exp.pop();
                    Expression *e1 = exp.top();
                    exp.pop();
                    e = binaryOp(e1, e2, op);
                    exp.push(e);
                }

            }
            operators.push(s[i]);

        }
    }
    while (!operators.empty()) {

        char op = operators.top();
        operators.pop();


        if (op == '&' || op == '%') {
            Expression* e1 = exp.top();
            exp.pop();
            e = unaryOp(e1, op);
            exp.push(e);
        }

        else {
            Expression *e2 = exp.top();
            exp.pop();
            Expression *e1 = exp.top();
            exp.pop();
            e = binaryOp(e1, e2, op);
            exp.push(e);
        }

    }
    return exp.top();



}
string Interpreter::arrange(string s) {

    for (unsigned int i = 0; i < s.length(); i++) {

        if (s[i] == '+' && s[i+1] == '(') {
            s[i] = '&';
        }
        if (s[i] == '-' && s[i+1] == '(') {
            s[i] = '%';
        }
    }
    return s;
}

Expression* Interpreter::binaryOp(Expression* e1, Expression* e2, char o) {

    switch(o) {

        case '+': return new Plus(e1,e2);
        case '-': return new Minus(e1,e2);
        case '*': return new Mul(e1,e2);
        case '/': return new Div(e1,e2);
        default : return 0;
    }

}

Expression* Interpreter::unaryOp(Expression* e1, char o) {
    switch(o) {

        case '&': return new UPlus(e1);
        case '%': return new UMinus(e1);
        default : return 0;

    }

}

int Interpreter::precedence(char o) {

    if (o == '+' || o == '-') {
        return 1;
    }
    if (o == '*' || o == '/') {
        return 2;
    }
    if (o == '&' || o == '%') {
        return 3;
    }
    return 0;
}

void Interpreter::setVariables(string s) {

    vector<string> result;
    string token;
    string delimiter = ";";
    size_t pos = 0;
    string inputVar;
    string inputNum;
    int equal = 0;
    if (s[s.length()-1] != ';') {
        s += ';';
    }

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    // Declaring iterator to a vector
    vector<string>::iterator ptr;
    for (ptr = result.begin(); ptr < result.end(); ptr++) {

        string temp = *ptr;
        //cout <<temp ;
        if (temp.length() < 3 || !((temp[0] >= 'a' && temp[0] <= 'z') || (temp[0] >= 'A' && temp[0] <= 'Z') || (temp[0] == '_')))
        {

            throw "bad input";
        }
        for (unsigned int p = 0; p < temp.length(); p++) {
            if (temp[p] == '=') {
                equal++;
            }
        }
        if (equal != 1) {
            throw "bad input";
        }
        equal = 0;
        string tokenVar = temp.substr(0, temp.find("="));
        string tokenNum = temp.substr(tokenVar.length() + 1, temp.length());
        if (tokenVar.length() == 1) {
            /*string*/ inputVar = tokenVar;
        }
        else {



            for (unsigned int k = 0; k < tokenVar.length(); k++) {

                if (isdigit(tokenVar[k]) || (tokenVar[k] >= 'a' && tokenVar[k] <= 'z') || (tokenVar[k] >= 'A' && tokenVar[k] <= 'Z')
                    || tokenVar[k] == '_') {
                    //ok
                }
                else {
                    throw "bad input";
                }
            }

        }
        if (tokenNum.length() == 1) {
            if (isdigit(tokenNum[0])) {
                /*string*/ inputNum = tokenNum;
            }
            else {
                throw "bad input";
            }
        }
        if (tokenNum.length() > 1 && (isdigit(tokenNum[0]) || tokenNum[0] == '-' || tokenNum[0] == '+')) {
            int counter = 0;
            for (unsigned int j = 1; j < tokenNum.length(); j++) {
                if (counter == 2) {
                    throw "bad input";
                }
                if (!(tokenNum[j] == '.' || isdigit(tokenNum[j]))) {
                    throw "bad input";
                }
                if (tokenNum[j] == '.') {
                    counter++;
                }

            }
            /*string*/ inputNum = tokenNum;
        }

        map1[tokenVar] = stod(tokenNum);

    }

}
