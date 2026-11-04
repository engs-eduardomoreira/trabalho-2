
#include <iostream>
#include <vector>
using namespace std;

// Recebe o array e os contadores por referência.
void selectionSort(vector<int>& v, long& comparacoes, long& trocas) {
    // Guarda o tamanho do array em n.
    int n = v.size();
    // Laço externo: i é a posição que receberá o menor elemento restante.
    for (int i = 0; i < n - 1; i++) {
        // Assume que o menor elemento está na posição i.
        int menor = i;
        // Laço interno: procura o menor elemento no restante do array.
        for (int j = i + 1; j < n; j++) {
            // Conta uma comparação entre v[j] e v[menor].
            comparacoes++;
            // Se v[j] é menor que o menor atual...
            if (v[j] < v[menor]) {
                // ...atualiza o índice do menor.
                menor = j;
            }
        }
        // Só troca se o menor não estiver já na posição i.
        if (menor != i) {
            // Coloca o menor elemento na posição i.
            swap(v[i], v[menor]);
            // Conta uma troca.
            trocas++;
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
    // Quebra de linha.
    cout << endl;
    // Chama o Selection Sort.
    selectionSort(v, comparacoes, trocas);
    // Imprime o rótulo da saída.
    cout << "Saida: ";
    // Percorre cada elemento do array já ordenado.
    for (int x : v) {
        // Imprime o elemento seguido de espaço.
        cout << x << " ";
    // Fim do laço de impressão.
    }
    cout << endl;
    // Imprime o total de comparações.
    cout << "Comparacoes: " << comparacoes << endl;
    // Imprime o total de trocas.
    cout << "Trocas: " << trocas << endl;
    // Encerra o programa 
    return 0;
}
