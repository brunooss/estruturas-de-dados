//---------------------------------------------------------------------
// Arquivo      : matop.c
// Conteudo     : programa de avaliacao do TAD TORRE
// Autor        : Bruno Oliveira. (bruno.oliveira@dcc.ufmg.br)
// Historico    : 2021-10-18 - arquivo criado
//              : 2021-10-21 - estrutura de diretorios
//              : 2021-10-25 - opcoes de linha de comando
//              : 2021-11-14 - adequacao para versao 1.1 memlog
//---------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
#include "../include/torre.hpp"
#include "../include/pilha.hpp"
#include "memlog.h"
#include "msgassert.h"

// definicoes de operacoes a serem testadas
#define OPCRIATORRE 1
#define OPORDENATORRE 2

using namespace std;

// variaveis globais para opcoes
static int opescolhida;
string lognome = "ordena";
string outnome;
int optn, regmem;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr, "Torre de Hanói\n");
  fprintf(stderr, "\t-c \t(cria torre) \n");
  fprintf(stderr, "\t-o \t(ordena a torre) \n");
  fprintf(stderr, "\t-p <arq>\t(arquivo de registro de acesso)\n");
  fprintf(stderr, "\t-l \t(registrar acessos a memoria)\n");
  fprintf(stderr, "\t-n <int>\t(quantidade n de anéis)\n");
}

// void parse_args(int argc, char **argv)
// // Descricao: le as opcoes da linha de comando e inicializa variaveis
// // Entrada: argc e argv
// // Saida: optescolhida, optx, opty, regmem, lognome
// {
//   // variaveis externas do getopt
//   extern char *optarg;
//   extern int optind;

//   // variavel auxiliar
//   int c;

//   // inicializacao variaveis globais para opcoes
//   opescolhida = -1;
//   optn = -1;
//   regmem = 0;
//   lognome = "";
//   outnome = "";

//   // getopt - letra indica a opcao, : junto a letra indica parametro
//   // no caso de escolher mais de uma operacao, vale a ultima
//   while ((c = getopt(argc, argv, "cop:n:hl")) != EOF)

//     switch (c)
//     {
//     case 'c':
//       avisoAssert(opescolhida == -1, "Mais de uma operacao escolhida");
//       opescolhida = OPCRIATORRE;
//       outnome = std::string(optarg);
//       break;
//     case 'o':
//       avisoAssert(opescolhida == -1, "Mais de uma operacao escolhida");
//       opescolhida = OPORDENATORRE;
//       break;
//     case 'p':
//       lognome = std::string(optarg);
//       break;
//     case 'n':
//       optn = atoi(optarg);
//       break;
//     case 'l':
//       regmem = 1;
//       break;
//     case 'h':
//     default:
//       uso();
//       exit(1);
//     }
//   // verificacao da consistencia das opcoes
//   erroAssert(opescolhida > 0, "matop - necessario escolher operacao");
//   erroAssert(lognome.size() > 0,
//              "matop - nome de arquivo de registro de acesso tem que ser definido");
//   erroAssert(optn > 0, "matop - dimensao X da matriz tem que ser positiva");
//   if (opescolhida == OPCRIATORRE)
//   {
//     erroAssert(outnome.size() > 0, "matop - nome de arquivo de saida tem que ser definido");
//   }
// }

int main()
// Descricao: programa principal para execucao de operacoes de matrizes
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{

  Torre *origem;
  Torre *destino;
  Torre *auxiliar;

  FILE *outfile;

  // avaliar linha de comando
  // parse_args(argc, argv);

  // iniciar registro de acesso
  iniciaMemLog("ordena" /* &lognome[0] */);

  // ativar ou nao o registro de acesso
  if (regmem)
  {
    ativaMemLog();
  }
  else
  {
    desativaMemLog();
  }

  // // cria matrizes a e b aleatorias, que sao multiplicadas para matriz c
  // // matriz c é impressa e todas as matrizes sao destruidas
  // defineFaseMemLog(0);

  // origem = new Torre(0);
  // origem->inicializaTorreAleatoria(16);

  // auxiliar = new Torre(1);
  // destino = new Torre(2);

  // defineFaseMemLog(1);

  // origem->acessaTorre();
  // auxiliar->acessaTorre();
  // destino->acessaTorre();

  // origem->resolverTorreDeHanoi(16, *origem, *destino, *auxiliar);

  // defineFaseMemLog(2);

  // origem->acessaTorre();
  // if (regmem)
  //   origem->imprimeTorre();

  // origem->removeTorre();
  // auxiliar->removeTorre();
  // destino->removeTorre();

  // cria matrizes a e b aleatorias, que sao multiplicadas para matriz c
  //                                     matriz c é impressa e todas as matrizes sao destruidas
  defineFaseMemLog(0);

  origem = new Torre(0);
  origem->inicializaTorreAleatoria(16);

  auxiliar = new Torre(1);
  destino = new Torre(2);

  defineFaseMemLog(1);

  origem->acessaTorre();
  auxiliar->acessaTorre();
  destino->acessaTorre();

  origem->resolverTorreDeHanoi(16, *origem, *destino, *auxiliar);

  defineFaseMemLog(2);

  origem->acessaTorre();
  if (regmem)
    origem->imprimeTorre();

  // origem->removeTorre();
  // auxiliar->removeTorre();
  // destino->removeTorre();

  // conclui registro de acesso
  return finalizaMemLog();
}
