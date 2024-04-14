//
// Created by ecjun on 27/03/2024.
//
#include <random>

void gerarDataSet() {

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 10000; ++j) {
            std::random_device seed;
            std::mt19937 gen{seed()}; // Seed do gerador
            std::uniform_int_distribution<> dist{0, 65000}; // Limite dos números
            int x = dist(gen); // Gerador
            dataSet[i].num[j] = x;
        }
    }
}