//
// Created by ecjun on 11/04/2024.
//

#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>



using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::steady_clock;
using namespace std::chrono_literals;



// Função para trocar elementos no vetor
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


//Função de Inserção quer será utilizada em vetores de tamnho <= 30
void insertionSort(vector<int>& arr, int low, int high) {

    // Percorrendo o vetor
    for (int i = low+1; i <= high; i++) {
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


void QuicksortRecursivoOrdenacaoInsercao(vector<int>& arr, int low, int high) {


    if(low < high) {
        if (high - low <= 30) {
            //cout << "entrou " << arr.size() << "conta " << high << " " << low << endl;
            insertionSort(arr, low, high);
        } else {
            // Encontrando a partição
            int pi = partition(arr, low, high);

            // Ordenando a sublista antes da partição
            QuicksortRecursivoOrdenacaoInsercao(arr, low, pi - 1);

            // Ordenando a sublista depois da partição
            QuicksortRecursivoOrdenacaoInsercao(arr, pi + 1, high);
        }
    }

}


vector<int> QuicksortRecursivoOrdenacaoInsercao(const vector<int> arr) {

    vector<int> vec_tmp = arr;
    QuicksortRecursivoOrdenacaoInsercao(vec_tmp, 0, vec_tmp.size() - 1);
    return vec_tmp;

}

// Função para ordenar o vetor usando quicksort interativo
void QuicksortNaoRecursivoOrdenacaoInsercao(vector<int>& arr, int low, int high) {
    // Pilha para armazenar os índices de início e fim das sublistas
    stack<pair<int, int>> st;

    // Empilhando a sublista completa
    st.push({low, high});

    // Loop enquanto a pilha não estiver vazia
    while (!st.empty()) {
        // Desempilhando os índices de início e fim da sublista atual
        low = st.top().first;
        high = st.top().second;
        st.pop();

        if (high - low + 1 <= 30) {

            // Usar Insertion Sort pra ordenar particçõess menores
            insertionSort(arr, low, high);

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


vector<int> QuicksortNaoRecursivoOrdenacaoInsercao(const vector<int> arr) {

    vector<int> vec_tmp = arr;
    QuicksortNaoRecursivoOrdenacaoInsercao(vec_tmp, 0, vec_tmp.size() - 1);
    return vec_tmp;

}




// Função recursiva para realizar o quicksort
void QuicksortRecursivoPuro(vector<int>& arr, int low, int high) {
    // Se o índice inicial for menor que o final
    if (low < high) {
        // Particionando o vetor
        int pi = partition(arr, low, high);

        // Ordenando recursivamente a sublista à esquerda do pivô
        QuicksortRecursivoPuro(arr, low, pi - 1);

        // Ordenando recursivamente a sublista à direita do pivô
        QuicksortRecursivoPuro(arr, pi + 1, high);
    }
}

// Função para ordenar o vetor usando quicksort recursivo puro
vector<int> QuicksortRecursivoPuro(const vector<int> arr) {
    vector<int> vec_tmp = arr;
    QuicksortRecursivoPuro(vec_tmp, 0, vec_tmp.size() - 1);
    return vec_tmp;
}




// Função para ordenar o vetor usando quicksort não recursivo puro
void QuicksortNaoRecursivoPuro(vector<int>& arr, int low, int high) {
        // Pilha para armazenar os índices de início e fim das sublistas
        stack<pair<int, int>> st;

        // Empilhando a sublista completa
        st.push({low, high});

        // Loop enquanto a pilha não estiver vazia
        while (!st.empty()) {
            // Desempilhando os índices de início e fim da sublista atual
            low  = st.top().first;
            high  = st.top().second;
            st.pop();

            // Encontrando a partição
            int pi = partition(arr, low, high);

            // Empilhando a sublista à direita do pivô
            if (pi - 1 > low) {
                st.push({low, pi - 1});
            }

            // Empilhando a sublista à esquerda do pivô
            if (pi + 1 < high) {
                st.push({pi + 1, high});
            }
    }
}


vector<int> QuicksortNaoRecursivoPuro(const vector<int> arr) {
    vector<int> vec_tmp = arr;
    QuicksortNaoRecursivoPuro(vec_tmp, 0, vec_tmp.size() - 1);
    return vec_tmp;
}

//Imprime Vetor
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printEstatiscaDados(vector<double> v, string str) {

    double sum = std::accumulate(std::begin(v), std::end(v), 0.0);
    double m =  sum / v.size();

    double accum = 0.0;
    std::for_each (std::begin(v), std::end(v), [&](const double d) {
        accum += (d - m) * (d - m);
    });

    double stdev = sqrt(accum / (v.size()));

    cout << "Dados da função " << str << " Média (ms): " << m << " Desvio Padrão (ms): " << stdev << endl;

};

int main() {

//    Declarando o vetor
//    vector<int> arr = {8, 7, 2, 1, 0, 9, 62, 82, 72, 22, 12, 02, 92, 63,83, 73, 23, 13, 03, 93, 64,84, 74, 24, 14, 04, 194, 164, 103, 193, 164,184, 174, 124, 114, 104, 114, 164};
//
//    vector<int> arrQuicksortNaoRecursivoOrdenacaoInsercao = QuicksortNaoRecursivoOrdenacaoInsercao(arr);
//    printArray(arrQuicksortNaoRecursivoOrdenacaoInsercao);
//
//    vector<int> arrQuicksortNaoRecursivoPuro = QuicksortNaoRecursivoPuro(arr);
//    printArray(arrQuicksortNaoRecursivoPuro);
//    return 0;
//
//    // Ordenando o vetor e armazenando o resultado em uma nova variável
//    vector<int> arrQuicksortRecursivoPuro = QuicksortRecursivoPuro(arr);
//    printArray(arrQuicksortRecursivoPuro);
//
//
//    vector<int> arrQuicksortRecursivoOrdenacaoInsercao = QuicksortRecursivoOrdenacaoInsercao(arr);
//    printArray(arrQuicksortRecursivoOrdenacaoInsercao);
//
//    //vector<int> arrQuicksortNaoRecursivoOrdenacaoInsercao = QuicksortNaoRecursivoOrdenacaoInsercao(arr);
//    //printArray(arrQuicksortNaoRecursivoOrdenacaoInsercao);
//    cout << "size" << arr.size();
//
//    return 0;
//    //vector<int> arrQuicksortNaoRecursivoPuro = QuicksortNaoRecursivoPuro(arr);
//   // printArray(arrQuicksortNaoRecursivoPuro);

    vector<int> dataSet[50];

    //vector<int> tmp;
    //int dataSet[50][10000];
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 200000; ++j) {
            std::random_device seed;
            std::mt19937 gen{seed()}; // Seed do gerador
            std::uniform_int_distribution<> dist{0, 65000}; // Limite dos números
            int x = dist(gen); // Gerador
            dataSet[i].push_back(x);
        }
        //dataSet.push_back(tmp);
    }

    vector<double> results_recursivo_puro;
    vector<double> results_recursivo_ins;
    vector<double> results_iterativo_puro;
    vector<double> results_iterativo_ins;

    for (int i = 0; i < 50; ++i) {

        cout << "Interação " << i << endl;

        auto t1_recursivo_puro = high_resolution_clock::now();
        vector<int> arrRetorno = QuicksortRecursivoPuro(dataSet[i]);
        auto t2_recursivo_puro = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2_recursivo_puro - t1_recursivo_puro;
        results_recursivo_puro.push_back(ms_double.count());


        auto t1_results_recursivo_ins = high_resolution_clock::now();
        vector<int> arrRetorno2 = QuicksortRecursivoOrdenacaoInsercao(dataSet[i]);
        auto t2_results_recursivo_ins = high_resolution_clock::now();
        duration<double, std::milli> ms_double2 = t2_results_recursivo_ins - t1_results_recursivo_ins;
        results_recursivo_ins.push_back(ms_double2.count());


        auto t1_results_iterativo_puro = high_resolution_clock::now();
        vector<int> arrRetorno3 = QuicksortNaoRecursivoPuro(dataSet[i]);
        auto t2_results_iterativo_puro = high_resolution_clock::now();
        duration<double, std::milli> ms_double3 = t2_results_iterativo_puro - t1_results_iterativo_puro;
        results_iterativo_puro.push_back(ms_double3.count());


        auto t1_results_iterativo_ins = high_resolution_clock::now();
        vector<int> arrRetorno4 = QuicksortNaoRecursivoOrdenacaoInsercao(dataSet[i]);
        auto t2_results_iterativo_ins = high_resolution_clock::now();
        duration<double, std::milli> ms_double4 = t2_results_iterativo_ins - t1_results_iterativo_ins;
        results_iterativo_ins.push_back(ms_double4.count());

    }

    printEstatiscaDados(results_recursivo_puro, "QuicksortRecursivoPuro");
    printEstatiscaDados(results_recursivo_ins, "QuicksortRecursivoOrdenacaoInsercao");
    printEstatiscaDados(results_iterativo_puro, "QuicksortNaoRecursivoPuro");
    printEstatiscaDados(results_iterativo_ins, "QuicksortNaoRecursivoOrdenacaoInsercao");



    return 0;

    //printArray(dataSet[0]);


    //vector<duration<double, std::milli>> resul;


//    for (int i = 0; i < 50; ++i) {
//
//        cout << i << "tamanhho " << dataSet[i].size() << endl;
//
//    }
//    cout << "------------------";

    for (int i = 0; i < 50; ++i) {


        //auto t1 = steady_clock::now();

        vector<int> arrRetorno = QuicksortNaoRecursivoOrdenacaoInsercao(dataSet[i]);
        if(i == 0) printArray(arrRetorno);


        //auto t2 = steady_clock::now();

        //duration<double, std::milli> ms_double = t2 - t1;

        //resul.push_back(ms_double);
    }

    return 0;
    for (int i = 0; i < 10; ++i) {

        //cout << resul[i].count() << "," << endl;
    }

    return 0;
    //printArray(arrQuicksortNaoRecursivoOrdenacaoInsercao);
    cout << "________________________________________________________________________" << endl;

    return 0;

    vector<int> arrQuicksortNaoRecursivoPuro = QuicksortNaoRecursivoPuro(dataSet[0]);
    printArray(arrQuicksortNaoRecursivoPuro);
    cout << "________________________________________________________________________" << endl;

    vector<int> arrQuicksortRecursivoPuro = QuicksortRecursivoPuro(dataSet[0]);
    printArray(arrQuicksortRecursivoPuro);
    cout << "________________________________________________________________________" << endl;


    vector<int> arrQuicksortRecursivoOrdenacaoInsercao = QuicksortRecursivoOrdenacaoInsercao(dataSet[0]);
    printArray(arrQuicksortRecursivoOrdenacaoInsercao);
    cout << "________________________________________________________________________" << endl;


//    auto t1 = high_resolution_clock::now();
//    long_operation();
//    auto t2 = high_resolution_clock::now();
//
//    /* Getting number of milliseconds as an integer. */
//    auto ms_int = duration_cast<milliseconds>(t2 - t1);
//
//    /* Getting number of milliseconds as a double. */
//    duration<double, std::milli> ms_double = t2 - t1;
//
//    std::cout << ms_int.count() << "ms\n";
//    std::cout << ms_double.count() << "ms\n";


    cout << "size" << dataSet[0].size();




    return 0;
}
