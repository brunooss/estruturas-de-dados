#include "../include/expressao.hpp"
#include "../include/pilha.hpp"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    freopen("entrada.txt", "r", stdin);

    std::string comando;
    std::string tipoExp;
    std::string exp;

    Expressao *expressao = nullptr;

    std::string linha;
    while (!cin.eof())
    {
        std::cin >> comando;

        if (comando == "LER")
        {
            std::cin >> tipoExp;
            std::getline(std::cin >> std::ws, exp);

            if (expressao != nullptr)
            {
                expressao = nullptr;
            }

            if (tipoExp == "INFIXA")
            {
                Expressao infixa("INFIXA", exp);

                if (infixa.infixaValida())
                {
                    cout << "EXPRESSAO OK:  " << tipoExp << std::endl;
                    expressao = &infixa;
                }
                else
                {
                    cout << "ERRO: " << tipoExp << " NAO VALIDA" << std::endl;
                }
            }
            else if (tipoExp == "POSFIXA")
            {
                Expressao posfixa("POSFIXA", exp);

                if (posfixa.posfixaValida())
                {
                    cout << "EXPRESSAO OK:  " << tipoExp << std::endl;
                    expressao = &posfixa;
                }
                else
                {
                    cout << "ERRO: " << tipoExp << " NAO VALIDA" << std::endl;
                }
            }
            else
            {
                std::cout << "Tipo de expressão inválido!" << std::endl;
                delete expressao;
                break;
            }
        }
        else if (comando == "INFIXA")
        {
            if (expressao == nullptr || expressao->paraInfixa() == "erro")
            {
                cout << "ERRO: EXP NAO EXISTE" << std::endl;
            }
            else
            {
                cout << "INFIXA: " << expressao->paraInfixa() << std::endl;
            }
        }
        else if (comando == "POSFIXA")
        {
            if (expressao == nullptr || expressao->paraPosfixa() == "erro")
            {
                cout << "ERRO: EXP NAO EXISTE" << std::endl;
            }
            else
            {
                cout << "POSFIXA: " << expressao->paraPosfixa() << std::endl;
            }
        }
        else if (comando == "RESOLVE")
        {
            try
            {
                cout << "VAL: " << std::fixed << std::showpoint << std::setprecision(6) << expressao->resolve() << std::endl;
            }
            catch (std::exception &e)
            {
                cout << "ERRO: EXP NAO EXISTE" << std::endl;
            }
        }
        else
        {
            std::cout << "Comando inválido!" << std::endl;
            delete expressao;
            break;
        }
    }

    return 0;
}