#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#include <string>

class Expressao
{
public:
    Expressao(const std::string type, std::string &expression);
    std::string paraPosfixa();
    std::string paraInfixa();
    long double resolve();

    bool infixaValida();
    bool posfixaValida();

private:
    std::string *infixExpression;
    std::string *postfixExpression;

    bool isOperator(char c);
    int precedencia(char op);
    bool maiorPrecedencia(char op1, char op2);
};

#endif // EXPRESSAO_H
