#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#include <string>

class Expressao
{
public:
    Expressao(const std::string &expression);
    std::string infixToPostfix();
    int evaluatePostfixExpression(const std::string &expression);
    // int avaliar();

private:
    std::string infixExpression;

    bool isOperator(char c);
    int getPrecedence(char op);
    bool hasHigherPrecedence(char op1, char op2);
};

#endif // EXPRESSAO_H
