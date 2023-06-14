
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <regex>

#include "ponto.hpp"
#include "lista.hpp"
#include "pilha.hpp"
#include "convexo.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    
    try {
        if (argc < 2) {
            cout << "Uso: fecho arquivoentrada" << endl;
            return 1;
        }

        
        string comando = argv[1];

        string nomeArquivo = argv[2];

        // Leitura do arquivo de entrada
        ifstream arquivo(nomeArquivo);

        if (comando != "fecho") {
            throw new invalid_argument("O valor esperado era 'fecho', mas foi inserido '" + comando + "'");
        }

        if (nomeArquivo == "") {
            throw new invalid_argument("O caminho especificado para o arquivo não pode estar vazio.");
        }

        if (!arquivo.is_open()) {
            throw new runtime_error("Ocorreu um erro ao abrir o arquivo.");
        }

        Lista<Ponto> pontos;
        string strX, strY;
        while (arquivo >> strX >> strY) {
            try {

                // Verificar se strX possui um ponto decimal ou letras
                if (std::regex_search(strX, std::regex("\\.([0-9]+)?|[a-zA-Z]+"))) {
                    throw std::runtime_error("O valor de X não é um número inteiro válido.");
                }

                // Verificar se strY possui um ponto decimal ou letras
                if (std::regex_search(strY, std::regex("\\.([0-9]+)?|[a-zA-Z]+"))) {
                    throw std::runtime_error("O valor de Y não é um número inteiro válido.");
                }

                int x = stoi(strX), y = stoi(strY);

                Ponto ponto(x, y);
                pontos.adicionar(ponto);
            } catch (std::runtime_error& e) {
                cout << "Ocorreu um erro durante a leitura do ponto (" << strX << ", " << strY << ")" << endl << endl;
                cout << "Motivo da exceção: " << e.what() << endl << endl;
                cout << "Este ponto será ignorado pela execução do algoritmo." << endl;
            }
        }

        arquivo.close();

        struct timeval start, end;

        FechoConvexo fechoConvexo(pontos);

        gettimeofday(&start, NULL);
        Lista<Ponto> fechoJarvis = fechoConvexo.calcularFechoConvexoJarvis();
        gettimeofday(&end, NULL);

        double jarvisDuration = (end.tv_sec - start.tv_sec) * 1e6;
        jarvisDuration = (jarvisDuration + (end.tv_usec -
                              start.tv_usec)) * 1e-6;


        std::cout << "FECHO CONVEXO:" << endl;
        for (int i = 0; i < fechoJarvis.getTamanho(); i++) {
            std::cout << "" << fechoJarvis[i].getX() << " " << fechoJarvis[i].getY() << "" << endl;
        }
        std::cout << std::endl;

        
        gettimeofday(&start, NULL);
        Lista<Ponto> fechoGrahamMergeSort = fechoConvexo.calcularFechoConvexoGraham("mergesort");
        gettimeofday(&end, NULL);

        double grahamMergeDuration = (end.tv_sec - start.tv_sec) * 1e6;
        grahamMergeDuration = (grahamMergeDuration + (end.tv_usec - start.tv_usec)) * 1e-6;

        gettimeofday(&start, NULL);
        Lista<Ponto> fechoGrahamInsertionSort = fechoConvexo.calcularFechoConvexoGraham("insertionsort");
        gettimeofday(&end, NULL);

        double grahamInsertionDuration = (end.tv_sec - start.tv_sec) * 1e6;
        grahamInsertionDuration = (grahamInsertionDuration + (end.tv_usec - start.tv_usec)) * 1e-6;

        gettimeofday(&start, NULL);
        Lista<Ponto> fechoGrahamBubbleSort = fechoConvexo.calcularFechoConvexoGraham("bubblesort");
        gettimeofday(&end, NULL);

        double grahamLinearDuration = (end.tv_sec - start.tv_sec) * 1e6;
        grahamLinearDuration = (grahamLinearDuration + (end.tv_usec - start.tv_usec)) * 1e-6;
        
        std::cout << "GRAHAM+MERGESORT:     " << fixed << setprecision(3) << grahamMergeDuration     << "s" << endl;
        std::cout << "GRAHAM+INSERTIONSORT: " << fixed << setprecision(3) << grahamInsertionDuration << "s" << endl;
        std::cout << "GRAHAM+LINEAR:        " << fixed << setprecision(3) << grahamLinearDuration    << "s" << endl;
        std::cout << "JARVIS:               " << fixed << setprecision(3) << jarvisDuration          << "s" << endl;

        // std::cout << "Fecho Convexo (Graham - BucketSort): ";
        // for (int i = 0; i < fechoGrahamBucketSort.getTamanho(); i++) {
        //     std::cout << "(" << fechoGrahamBucketSort[i].getX() << ", " << fechoGrahamBucketSort[i].getY() << ") ";
        // }
        // std::cout << std::endl;
        
        return 0;
    } catch (std::invalid_argument& e) {
        cout << "Os parâmetros da função estão incorretos. Execute o programa de acordo com o protótipo a seguir:" << endl;
        cout << "fecho <arquivo.txt> para se obter o fecho convexo dos pontos contidos no arquivo passado como argumento." << endl << endl;

        cout << "Motivo da exceção: " << e.what() << endl;
        return 1;
    } catch (std::runtime_error& e) {
        cout << "Ocorreu um erro durante a execução do programa." << endl << endl;

        cout << "Motivo da exceção: " << e.what() << endl;
        return 1;
    } catch (std::length_error& e) {
        cout << "A quantidade de pontos é insuficiente para a determinação do fecho convexo." << endl << endl;

        cout << "Motivo da exceção: " << e.what() << endl;
        return 1;
    } catch (std::domain_error& e) {
        cout << "A opção de ordenação selecionada não está disponível." << endl << endl;

        cout << "Motivo da exceção: " << e.what() << endl;
        return 1;
    }

}