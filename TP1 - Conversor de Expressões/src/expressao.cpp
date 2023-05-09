#include "../include/expressao.hpp"

#include "pilha.cpp"

#include <sstream>
#include <iostream>

Expressao::Expressao(const std::string type, std::string &expression)
{
    if (type == "INFIXA")
    {
        infixExpression = &expression;
        postfixExpression = nullptr;
    }
    else if (type == "POSFIXA")
    {
        postfixExpression = &expression;
        infixExpression = nullptr;
    }
    else
    {
        postfixExpression = nullptr;
        infixExpression = nullptr;
    }
}

bool Expressao::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Expressao::precedencia(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

bool Expressao::maiorPrecedencia(char op1, char op2)
{
    int precedence1 = precedencia(op1);
    int precedence2 = precedencia(op2);
    return precedence1 >= precedence2;
}

bool Expressao::infixaValida()
{
    Pilha<char> parentheses;

    for (char c : *infixExpression)
    {
        if (c == '(')
        {
            parentheses.empilha(c);
        }
        else if (c == ')')
        {
            if (parentheses.vazia() || parentheses.topo() != '(')
            {
                return false;
            }
            parentheses.desempilha();
        }
    }

    return parentheses.vazia();
}

bool Expressao::posfixaValida()
{
    Pilha<int> operands;

    std::istringstream iss(*postfixExpression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            operands.empilha(std::stoi(token));
        }
        else
        {
            if (operands.tamanho() < 2)
            {
                return false;
            }
            operands.desempilha();
        }
    }

    return operands.tamanho() == 1;
}

std::string Expressao::paraPosfixa()
{
    if (postfixExpression != nullptr)
        return *postfixExpression;

    if (infixExpression == nullptr)
    {
        return "erro";
    }

    Pilha<char> operators;
    std::ostringstream oss;
    std::istringstream iss(*infixExpression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || token[0] == '.')
        {
            oss << token << " ";
        }
        else if (token == "(")
        {
            operators.empilha('(');
        }
        else if (token == ")")
        {
            while (!operators.vazia() && operators.topo() != '(')
            {
                oss << operators.topo() << " ";
                operators.desempilha();
            }

            if (!operators.vazia() && operators.topo() == '(')
                operators.desempilha();
        }
        else if (isOperator(token[0]))
        {
            while (!operators.vazia() && operators.topo() != '(' && maiorPrecedencia(operators.topo(), token[0]))
            {
                oss << operators.topo() << " ";
                operators.desempilha();
            }
            operators.empilha(token[0]);
        }
    }

    while (!operators.vazia())
    {
        oss << operators.topo() << " ";
        operators.desempilha();
    }

    std::string postfixExpression = oss.str();
    // Remove espaços extras antes e depois dos operadores
    size_t startPos = postfixExpression.find_first_not_of(' ');
    size_t endPos = postfixExpression.find_last_not_of(' ');
    postfixExpression = postfixExpression.substr(startPos, endPos - startPos + 1);

    return postfixExpression;
}

std::string Expressao::paraInfixa()
{
    if (infixExpression != nullptr)
        return *infixExpression;

    if (postfixExpression == nullptr)
    {
        return "erro";
    }

    Pilha<std::string> pilha;

    std::istringstream iss(*postfixExpression);
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token[0]))
        {
            std::string operand2 = pilha.topo();
            pilha.desempilha();
            std::string operand1 = pilha.topo();
            pilha.desempilha();

            std::ostringstream oss;
            oss << "(" << operand1 << " " << token << " " << operand2 << ")";
            pilha.empilha(oss.str());
        }
        else
        {
            pilha.empilha(token);
        }
    }

    if (pilha.vazia())
    {
        return "";
    }

    return pilha.topo();
}

long double Expressao::resolve()
{
    std::string expression;

    if (postfixExpression == nullptr && infixExpression == nullptr)
    {
        throw new std::exception;
    }
    else if (postfixExpression != nullptr)
    {
        expression = *postfixExpression;
    }
    else if (infixExpression != nullptr)
    {
        expression = this->paraPosfixa();
    }

    Pilha<long double> pilha;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || token[0] == '.')
        {
            long double value = std::stod(token);
            pilha.empilha(value);
        }
        else if (isOperator(token[0]))
        {
            long double operand2 = pilha.topo();
            pilha.desempilha();
            long double operand1 = pilha.topo();
            pilha.desempilha();

            if (token[0] == '+')
            {
                pilha.empilha(operand1 + operand2);
            }
            else if (token[0] == '-')
            {
                pilha.empilha(operand1 - operand2);
            }
            else if (token[0] == '*')
            {
                pilha.empilha(operand1 * operand2);
            }
            else if (token[0] == '/')
            {
                pilha.empilha(operand1 / operand2);
            }
        }
    }

    return pilha.topo();
}