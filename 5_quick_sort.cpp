
#include <iostream>
#include <vector>

using namespace std;

// Particiona v[baixo..alto] em torno de um pivô e devolve a posição final dele.
int particionar(vector<int>& v, int baixo, int alto, long& comparacoes, long& trocas) {
    // Escolhe o último elemento como pivô.
    int pivo = v[alto];
    // i marca o fim da região dos elementos menores ou iguais ao pivô.
    int i = baixo - 1;
    // j percorre todos os elementos, exceto o pivô.
    for (int j = baixo; j < alto; j++) {
        // Conta uma comparação entre v[j] e o pivô.
        comparacoes++;
        // Se v[j] pertence à região dos menores ou iguais...
        if (v[j] <= pivo) {
            // ...aumenta essa região em uma posição.
            i++;
            // Só troca se as posições forem diferentes.
            if (i != j) {
                // Leva v[j] para dentro da região dos menores.
                swap(v[i], v[j]);
                // Conta uma troca.
                trocas++;
            
            }
       
        }

    }
    // Se o pivô ainda não está na posição final...
    if (i + 1 != alto) {
        // ...coloca o pivô logo após a região dos menores.
        swap(v[i + 1], v[alto]);
        // Conta uma troca.
        trocas++;
   
    }
    // Devolve a posição final do pivô.
    return i + 1;

}

// Ordena o trecho v[baixo..alto].
void quickSort(vector<int>& v, int baixo, int alto, long& comparacoes, long& trocas) {
    // Só continua se o trecho tiver 2 ou mais elementos.
    if (baixo < alto) {
        // Particiona e obtém a posição p do pivô.
        int p = particionar(v, baixo, alto, comparacoes, trocas);
        // Ordena recursivamente os elementos à esquerda do pivô.
        quickSort(v, baixo, p - 1, comparacoes, trocas);
        // Ordena recursivamente os elementos à direita do pivô.
        quickSort(v, p + 1, alto, comparacoes, trocas);
   
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
    // Chama o Quick Sort para o array inteiro.
    quickSort(v, 0, (int)v.size() - 1, comparacoes, trocas);
    // Imprime o rótulo da saída.
    cout << "Saida: ";
    // Percorre cada elemento do array já ordenado.
    for (int x : v) {
        // Imprime o elemento seguido de espaço.
        cout << x << " ";
  
    }
    // Quebra de linha.
    cout << endl;
    // Imprime o total de comparações.
    cout << "Comparacoes: " << comparacoes << endl;
    // Imprime o total de trocas.
    cout << "Trocas: " << trocas << endl;
    // Encerra o programa 
    return 0;

}
