#include "../include/expressao.hpp"
#include <stack>
#include <sstream>
#include <unordered_map>

Expressao::Expressao(const std::string &expression) : infixExpression(expression) {}

bool Expressao::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Expressao::getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

bool Expressao::hasHigherPrecedence(char op1, char op2)
{
    int precedence1 = getPrecedence(op1);
    int precedence2 = getPrecedence(op2);
    return precedence1 >= precedence2;
}

std::string Expressao::infixToPostfix()
{
    std::stack<char> operators;
    std::ostringstream oss;
    std::istringstream iss(infixExpression);
    char c;

    while (iss >> c)
    {
        if (isdigit(c))
        {
            oss << c;
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                oss << operators.top();
                operators.pop();
            }

            if (!operators.empty() && operators.top() == '(')
                operators.pop();
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && operators.top() != '(' && hasHigherPrecedence(operators.top(), c))
            {
                oss << operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty())
    {
        oss << operators.top();
        operators.pop();
    }

    return oss.str();
}

int Expressao::evaluatePostfixExpression(const std::string &expression)
{
    std::stack<int> stack;

    for (char c : expression)
    {
        if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (c == '+')
            {
                stack.push(operand1 + operand2);
            }
            else if (c == '-')
            {
                stack.push(operand1 - operand2);
            }
            else if (c == '*')
            {
                stack.push(operand1 * operand2);
            }
            else if (c == '/')
            {
                stack.push(operand1 / operand2);
            }
        }
    }

    return stack.top();
}
