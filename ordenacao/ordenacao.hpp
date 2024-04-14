//
// Created by ecjun on 27/03/2024.
//

#ifndef TP0_ALG_ORDENACAO_HPP
#define TP0_ALG_ORDENACAO_HPP

vector<int> QuicksortRecursivoPuro(const vector<int> arr);
vector<int> QuicksortRecursivoOrdenacaoInsercao(const vector<int> arr);
vector<int> QuicksortNaoRecursivoPuro(const vector<int> arr);
vector<int> QuicksortNaoRecursivoOrdenacaoInsercao(const vector<int> arr);

void swap(int *a, int *b);

void quickSortRecursivoPuro(vector<int>& arr, int low, int high);

void quickSortRecursivoInsercao(vector<int>& arr, int low, int high);

void quickSortIterativoPuro(vector<int>& arr, int low, int high);

void quickSortIterativoInsercao(vector<int>& arr, int low, int high);

int partition(vector<int>& arr, int low, int high);

void insertionSort(vector<int>& arr);


#endif //TP0_ALG_ORDENACAO_HPP
