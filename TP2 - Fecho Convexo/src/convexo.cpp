#include "convexo.hpp"
#include "lista.cpp"
#include "ponto.hpp"
#include "pilha.cpp"

#include <stdexcept>

FechoConvexo::FechoConvexo(Lista<Ponto>& pontos) {
    this->pontos = pontos;
}

FechoConvexo::~FechoConvexo() {

}

bool FechoConvexo::pontoNoSegmento(const Ponto& p, const Ponto& q, const Ponto& r) const {
    if (q.getX() <= std::max(p.getX(), r.getX()) && q.getX() >= std::min(p.getX(), r.getX()) &&
        q.getY() <= std::max(p.getY(), r.getY()) && q.getY() >= std::min(p.getY(), r.getY())) {
        return true;
    }
    return false;
}

int FechoConvexo::orientacao(Ponto p, Ponto q, Ponto r)
{
    int orientacao = (q.getY() - p.getY()) * (r.getX() - q.getX()) - (q.getX() - p.getX()) * (r.getY() - q.getY());
  
    if (orientacao == 0) return 0;
    return (orientacao > 0)? 1: -1; // 1 = sentido horário, -1 = sentido anti-horário
}

Lista<Ponto> FechoConvexo::calcularFechoConvexoJarvis() {
    int tamanho = this->pontos.getTamanho();

    if (tamanho < 3) throw std::length_error("O conjunto inicial requer ao menos três pontos.");

    Lista<Ponto> fecho;

        // Encontre o ponto mais à esquerda
    int posicaoPontoEsquerda = 0;
    for (int i = 1; i < pontos.getTamanho(); i++) {
        if (pontos[i].getX() < pontos[posicaoPontoEsquerda].getX()) {
            posicaoPontoEsquerda = i;
        }
    }

    int posicaoPontoAtual = posicaoPontoEsquerda;
    int pontoProximo;
    do {
        fecho.adicionar(pontos[posicaoPontoAtual]);
        pontoProximo = (posicaoPontoAtual + 1) % pontos.getTamanho();

        for (int i = 0; i < pontos.getTamanho(); i++) {
            if (orientacao(pontos[posicaoPontoAtual], pontos[i], pontos[pontoProximo]) == -1) {
                pontoProximo = i;
            }
        }

        posicaoPontoAtual = pontoProximo;
    } while (posicaoPontoAtual != posicaoPontoEsquerda);

    if (fecho.getTamanho() < 3) throw std::length_error("O fecho convexo não pôde ser determinado por ter menos de três pontos.");

    return fecho;
}

int FechoConvexo::posicaoMenorY() {
    int posicaoMinimo = 0;
    for (int i = 1; i < pontos.getTamanho(); i++) {
        if (pontos[i].getY() < pontos[posicaoMinimo].getY() || (pontos[i].getY() == pontos[posicaoMinimo].getY() && pontos[i].getX() < pontos[posicaoMinimo].getX())) {
            posicaoMinimo = i;
        }
    }
    return posicaoMinimo;
}

// Implementação do algoritmo mergesort
void FechoConvexo::mergesort(Ponto pontoReferencia, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergesort(pontoReferencia, esquerda, meio);
        mergesort(pontoReferencia, meio + 1, direita);

        merge(pontoReferencia, esquerda, meio, direita);
    }
}

void FechoConvexo::merge(Ponto pontoReferencia, int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    Lista<Ponto> esq;
    Lista<Ponto> dir;

    for (i = 0; i < n1; i++) {
        esq.adicionar(pontos[esquerda + i]);
    }
    for (j = 0; j < n2; j++) {
        dir.adicionar(pontos[meio + 1 + j]);
    }

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2) {
        int orientacaoPontos = orientacao(pontoReferencia, esq[i], dir[j]);

        if (orientacaoPontos == -1 || (orientacaoPontos == 0 && pontoReferencia.calcularDistancia(esq[i]) < pontoReferencia.calcularDistancia(dir[j]))) {
            pontos[k] = esq[i];
            i++;
        } else {
            pontos[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        pontos[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        pontos[k] = dir[j];
        j++;
        k++;
    }
}

// Implementação do algoritmo insertionsort
void FechoConvexo::insertionsort(Ponto pontoReferencia) {
    int i, j;
    for (i = 1; i < pontos.getTamanho(); i++) {
        Ponto chave = pontos[i];
        j = i - 1;

        bool deveTrocar = orientacao(pontoReferencia, pontos[j], chave) == 0 ?
            !(pontoReferencia.calcularDistancia(pontos[j]) < pontoReferencia.calcularDistancia(chave)) : !(orientacao(pontoReferencia, pontos[j], chave) == -1);

        while (j >= 0 && deveTrocar) {
            pontos[j + 1] = pontos[j];
            j--;

            if (j >= 0) {
                deveTrocar = orientacao(pontoReferencia, pontos[j], chave) == 0 ?
                    !(pontoReferencia.calcularDistancia(pontos[j]) < pontoReferencia.calcularDistancia(chave)) : !(orientacao(pontoReferencia, pontos[j], chave) == -1);
            }
        }
        pontos[j + 1] = chave;
    }
}

void FechoConvexo::bucketsort(Ponto pontoReferencia) {
    int tamanho = pontos.getTamanho();

    // Criar os buckets vazios
    Lista<Lista<Ponto>> buckets;

    for (int i = 0; i < tamanho; i++) {
        Lista<Ponto> temp;

        buckets[i] = temp;
    }

    // Colocar os pontos nos buckets correspondentes
    for (int i = 0; i < tamanho; i++) {
        int distancia = pontoReferencia.calcularDistancia(pontos[i]);
        int indice = (distancia * tamanho) / (getMaximo(pontoReferencia) + 1);
        buckets[indice].adicionar(pontos[i]);
    }

    // Ordenar cada bucket individualmente usando Insertion Sort
    for (int i = 0; i < tamanho; i++) {
        Lista<Ponto> bucket = buckets[i];

        int tamanho = bucket.getTamanho();
        for (int i = 1; i < tamanho; i++) {
            Ponto chave = bucket[i];
            int j = i - 1;

            bool deveTrocar = orientacao(pontoReferencia, bucket[j], chave) == 0 ?
                !(pontoReferencia.calcularDistancia(bucket[j]) < pontoReferencia.calcularDistancia(chave)) : !(orientacao(pontoReferencia, bucket[j], chave) == -1);

            while (j >= 0 && deveTrocar) {
                bucket[j + 1] = bucket[j];
                j--;

                if (j >= 0) {
                    deveTrocar = orientacao(pontoReferencia, bucket[j], chave) == 0 ?
                        !(pontoReferencia.calcularDistancia(bucket[j]) < pontoReferencia.calcularDistancia(chave)) : !(orientacao(pontoReferencia, bucket[j], chave) == -1);
                }
            }
            bucket[j + 1] = chave;
        }
    }

    // Juntar os pontos ordenados dos buckets em um único vetor
    int indice = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < buckets[i].getTamanho(); j++) {
            pontos[indice] = buckets[i][j];
            indice++;
        }
    }
}

int FechoConvexo::getMaximo(Ponto pontoReferencia) {
    int maximo = pontoReferencia.calcularDistancia(pontos[0]);
    for (int i = 1; i < pontos.getTamanho(); i++) {
        int distancia = pontoReferencia.calcularDistancia(pontos[i]);
        if (distancia > maximo) {
            maximo = distancia;
        }
    }
    return maximo;
}

void FechoConvexo::countingSort(Ponto pontoReferencia, int tamanho, int exp) {
    Lista<Ponto> resultado;
    int contador[10] = { 0 };

    for (int i = 0; i < tamanho; i++) {
        int distancia = pontoReferencia.calcularDistancia(pontos[i]);
        contador[(distancia / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        contador[i] += contador[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        int distancia = pontoReferencia.calcularDistancia(pontos[i]);
        resultado[contador[(distancia / exp) % 10] - 1] = pontos[i];
        contador[(distancia / exp) % 10]--;
    }

    for (int i = 0; i < tamanho; i++) {
        pontos[i] = resultado[i];
    }
}

// Função para ordenar os pontos em ordem polar
void FechoConvexo::ordenarPolar(Ponto pontoReferencia, std::string ordenacao) {
    if (ordenacao == "mergesort") {
        mergesort(pontoReferencia, 0, pontos.getTamanho() - 1);
    } else if (ordenacao == "insertionsort") {
        insertionsort(pontoReferencia);
    } else if (ordenacao == "bucketsort") {
        bucketsort(pontoReferencia);
    } else if (ordenacao == "bubblesort") {
        int i, j;
        bool swapped;

        for (i = 0; i < pontos.getTamanho() - 1; i++) {
            swapped = false;
            for (j = 0; j < pontos.getTamanho() - i - 1; j++) {
                bool deveTrocar = orientacao(pontoReferencia, pontos[j], pontos[j + 1]) == 0 ?
                    !(pontoReferencia.calcularDistancia(pontos[j]) < pontoReferencia.calcularDistancia(pontos[j + 1])) : !(orientacao(pontoReferencia, pontos[j], pontos[j + 1]) == -1);

                if (deveTrocar) {
                    Ponto temp = pontos[j];
                    pontos[j] = pontos[j + 1];
                    pontos[j + 1] = temp;
                    swapped = true;
                }
            }

            if (swapped == false) break;
        }
    } else {
        throw std::domain_error("Este método de ordenação não é aceito.");
    }
}

Ponto FechoConvexo::anteriorAoTopo(Pilha<Ponto>& pilha) {
   Ponto temp = pilha.topo(); 
   pilha.desempilha();

   Ponto anterior = pilha.topo();
   pilha.empilha(temp);
   return anterior;
}

Lista<Ponto> FechoConvexo::calcularFechoConvexoGraham(std::string ordenacao) {

    int menorY = posicaoMenorY();
    Ponto pontoMenorY = pontos[menorY];

    pontos[menorY] = pontos[0];
    pontos[0] = pontoMenorY;

    // Encontrar o ponto com o menor y (ponto de referência)
    Ponto pontoReferencia = pontos[0];

    // Ordenar os pontos em ordem polar em relação ao ponto de referência
    ordenarPolar(pontoReferencia, ordenacao);

    // Verificar se há pontos com a mesma orientação polar
    // Remover todos os pontos, exceto o mais distante em linha reta
    int m = 1;  // Tamanho atual do fecho convexo
    for (int i = 1; i < pontos.getTamanho(); i++) {
        // Enquanto houver pontos com a mesma orientação polar, remover o mais próximo
        while (i < pontos.getTamanho() - 1 && orientacao(pontoReferencia, pontos[i], pontos[i + 1]) == 0) {
            i++;
        }
        pontos[m] = pontos[i];
        m++;
    }

    if (m < 3) throw std::length_error("O fecho convexo não pôde ser determinado por ter menos de três pontos.");

    // Criar uma pilha e empilhar os primeiros 3 pontos
    Pilha<Ponto> pilha;
    pilha.empilha(pontos[0]);
    pilha.empilha(pontos[1]);
    pilha.empilha(pontos[2]);

    // Processar os restantes dos pontos
    for (int i = 3; i < m; i++) {
        // Remover os pontos que não fazem uma curva à esquerda
        while (pilha.tamanho() > 1 && orientacao(anteriorAoTopo(pilha), pilha.topo(), pontos[i]) != -1) {
            pilha.desempilha();
        }
        pilha.empilha(pontos[i]);
    }

    // Armazenar os pontos do fecho convexo em um vetor e retorná-lo
    Lista<Ponto> fecho;
    while (!pilha.vazia()) {
        // std::cout << "(" << pilha.topo().getX() << ", " << pilha.topo().getY() << ") ";
        fecho.adicionar(pilha.topo());
        pilha.desempilha();
    }
    
    if (fecho.getTamanho() < 3) throw std::length_error("O fecho convexo não pôde ser determinado por ter menos de três pontos.");

    return fecho;
}


