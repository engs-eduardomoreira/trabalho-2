
#include <iostream>
#include <vector>
using namespace std;

// Recebe o array e os contadores por referência.
void insertionSort(vector<int>& v, long& comparacoes, long& trocas) {
    // Guarda o tamanho do array em n.
    int n = v.size();
    // Cada i é o próximo elemento a ser inserido na parte já ordenada (à esquerda).
    for (int i = 1; i < n; i++) {
        // Começa na posição do elemento a inserir.
        int j = i;
        // Enquanto houver elemento à esquerda para comparar...
        while (j > 0) {
            // Conta uma comparação entre v[j - 1] e v[j].
            comparacoes++;
            // Se o da esquerda é maior, o elemento ainda não está na posição correta.
            if (v[j - 1] > v[j]) {
                // Troca com o vizinho da esquerda.
                swap(v[j - 1], v[j]);
                // Conta uma troca.
                trocas++;
                // Move o índice uma posição para a esquerda.
                j--;
            // Caso contrário...
            } else {
                // ...o elemento já está na posição correta; encerra o while.
                break;
            }
        }
    }
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
    // Chama o Insertion Sort.
    insertionSort(v, comparacoes, trocas);
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
