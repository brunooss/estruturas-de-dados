#include "../include/expressao.hpp"
#include <iostream>
using namespace std;

int main()
{

    std::string infixExpression = "2 + 3 + (4 * 5)";
    Expressao expressao(infixExpression);

    std::string posfixa = expressao.infixToPostfix();
    cout << "Resultado: " << expressao.evaluatePostfixExpression(posfixa) << endl;

    return 0;
}