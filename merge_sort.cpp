
#include <iostream>
#include <vector>

using namespace std;

// Intercala as duas metades ordenadas v[esq..meio] e v[meio+1..dir].
void intercalar(vector<int>& v, int esq, int meio, int dir, long& comparacoes, long& trocas) {
    // Copia a metade esquerda para o vetor auxiliar L.
    vector<int> L(v.begin() + esq, v.begin() + meio + 1);
    // Copia a metade direita para o vetor auxiliar R.
    vector<int> R(v.begin() + meio + 1, v.begin() + dir + 1);
    // i percorre L, j percorre R e k é a posição de escrita em v.
    int i = 0, j = 0, k = esq;
    // Enquanto restarem elementos nas duas metades...
    while (i < (int)L.size() && j < (int)R.size()) {
        // Conta uma comparação entre L[i] e R[j].
        comparacoes++;
        // Se o elemento de L é menor ou igual (mantém a estabilidade)...
        if (L[i] <= R[j]) {
            // ...copia L[i] para v[k] e avança i e k.
            v[k++] = L[i++];
        // Caso contrário...
        } else {
            // ...copia R[j] para v[k] e avança j e k.
            v[k++] = R[j++];
    
        }
        // Conta uma movimentação (escrita no array).
        trocas++;
  
    }
    // Se sobraram elementos em L...
    while (i < (int)L.size()) {
        // ...copia-os para v.
        v[k++] = L[i++];
        // Conta uma movimentação.
        trocas++;
    }
    // Se sobraram elementos em R...
    while (j < (int)R.size()) {
        // ...copia-os para v.
        v[k++] = R[j++];
        // Conta uma movimentação.
        trocas++;
    }

}

// Ordena o trecho v[esq..dir] por divisão e conquista.
void mergeSort(vector<int>& v, int esq, int dir, long& comparacoes, long& trocas) {
    // Caso base: trecho com 0 ou 1 elemento já está ordenado.
    if (esq >= dir) {
        // Retorna sem fazer nada.
        return;
    }
    // Calcula o índice do meio do trecho.
    int meio = esq + (dir - esq) / 2;
    // Ordena recursivamente a metade esquerda.
    mergeSort(v, esq, meio, comparacoes, trocas);
    // Ordena recursivamente a metade direita.
    mergeSort(v, meio + 1, dir, comparacoes, trocas);
    // Intercala as duas metades ordenadas.
    intercalar(v, esq, meio, dir, comparacoes, trocas);
}

// Início da função principal do programa.
int main() {
    // Cria o array de entrada do teste de mesa.
    vector<int> v = {5, 2, 9, 1, 6, 3};
    // Zera os contadores de comparações e de trocas.
    long comparacoes = 0, trocas = 0;
    // Imprime o rótulo da entrada.
    cout << "Entrada: ";
    // Percorre cada elemento do array de entrada.
    for (int x : v) {
        // Imprime o elemento seguido de espaço.
        cout << x << " ";
    }
    cout << endl;
    // Chama o Merge Sort para o array inteiro.
    mergeSort(v, 0, (int)v.size() - 1, comparacoes, trocas);
    // Imprime o rótulo da saída.
    cout << "Saida: ";
    // Percorre cada elemento do array já ordenado.
    for (int x : v) {
        // Imprime o elemento seguido de espaço.
        cout << x << " ";
    }
    cout << endl;
    // Imprime o total de comparações.
    cout << "Comparacoes: " << comparacoes << endl;
    // Imprime o total de trocas.
    cout << "Trocas: " << trocas << endl;
    // Encerra o programa 
    return 0;
}
