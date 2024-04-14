//
// Created by ecjun on 27/03/2024.
//

#include "ordenacao.hpp"
#include <vector>

using namespace std;

// Função para trocar elementos no vetor
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor
int partition(vector<int>& arr, int low, int high) {
    // Selecionando o pivô
    int pivot = arr[high];

    // Posicionando o pivô no lugar correto
    int i = (low - 1);

    // Percorrendo o vetor
    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] <= pivot) {
            // Incrementando o índice do menor elemento
            i++;

            // Trocando o elemento menor com o elemento atual
            swap(&arr[i], &arr[j]);
        }
    }

    // Trocando o pivô com o elemento na posição i
    swap(&arr[i + 1], &arr[high]);

    // Retornando o índice da partição
    return (i + 1);
}

// Função para ordenar o vetor usando quicksort recursivo
void quickSortRecursivoPura(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Encontrando a partição
        int pi = partition(arr, low, high);

        // Ordenando a sublista antes da partição
        quicksort(arr, low, pi - 1);

        // Ordenando a sublista depois da partição
        quicksort(arr, pi + 1, high);
    }
}


// Função para ordenar o vetor usando quicksort interativo
void quickSortIterativoPura(vector<int>& arr, int low, int high) {
    // Pilha para armazenar os índices de início e fim das sublistas
    stack<pair<int, int>> st;

    // Empilhando a sublista completa
    st.push({low, high});

    // Loop enquanto a pilha não estiver vazia
    while (!st.empty()) {
        // Desempilhando os índices de início e fim da sublista atual
        int low = st.top().first;
        int high = st.top().second;
        st.pop();

        // Se a sublista tiver mais de um elemento
        if (low < high) {
            // Encontrando a partição
            int pi = partition(arr, low, high);

            // Empilhando a sublista à direita do pivô
            st.push({pi + 1, high});

            // Empilhando a sublista à esquerda do pivô
            st.push({low, pi - 1});
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Percorrendo o vetor
    for (int i = 1; i < n; i++) {
        // Elemento atual (chave)
        int key = arr[i];

        // Comparando a chave com os elementos anteriores ordenados
        int j = i - 1;

        // Movendo elementos maiores que a chave uma posição para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Inserindo a chave na posição correta
        arr[j + 1] = key;
    }
}


void quickSortRecursivoPuraInsercao(vector<int>& arr, int low, int high) {

    if (high - low + 1 <= 30) {
        insertionSort(arr);
    }
    else {
        // Encontrando a partição
        int pi = partition(arr, low, high);

        // Ordenando a sublista antes da partição
        quicksort(arr, low, pi - 1);

        // Ordenando a sublista depois da partição
        quicksort(arr, pi + 1, high);
    }
}


// Função para ordenar o vetor usando quicksort interativo
void quickSortIterativoPuraInsercao(vector<int>& arr, int low, int high) {
    // Pilha para armazenar os índices de início e fim das sublistas
    stack<pair<int, int>> st;

    // Empilhando a sublista completa
    st.push({low, high});

    // Loop enquanto a pilha não estiver vazia
    while (!st.empty()) {
        // Desempilhando os índices de início e fim da sublista atual
        int low = st.top().first;
        int high = st.top().second;
        st.pop();

        if (high - low + 1 <= 30) {

            // Usar Insertion Sort pra ordenar particçõess menores
            insertionSort(arr);

        }
        // Se a sublista tiver mais de um elemento
        else {
            // Encontrando a partição
            int pi = partition(arr, low, high);

            // Empilhando a sublista à direita do pivô
            st.push({pi + 1, high});

            // Empilhando a sublista à esquerda do pivô
            st.push({low, pi - 1});
        }
    }
}

