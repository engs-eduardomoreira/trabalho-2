
#include <iostream>
#include <vector>
using namespace std;

// Recebe o array e os contadores por referência, para alterá-los.
void bubbleSort(vector<int>& v, long& comparacoes, long& trocas) {
    // Guarda o tamanho do array em n.
    int n = v.size();
    // Laço externo: cada passada coloca o maior elemento restante no fim.
    for (int i = 0; i < n - 1; i++) {
        // Laço interno: compara pares vizinhos; o final encolhe pois os últimos já estão ordenados.
        for (int j = 0; j < n - i - 1; j++) {
            // Conta uma comparação entre v[j] e v[j + 1].
            comparacoes++;
            // Se o par está fora de ordem...
            if (v[j] > v[j + 1]) {
                // ...troca os dois elementos de posição.
                swap(v[j], v[j + 1]);
                // Conta uma troca.
                trocas++;

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
    // Fim do laço de impressão.
    }
    cout << endl;
    // Chama o Bubble Sort.
    bubbleSort(v, comparacoes, trocas);
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
