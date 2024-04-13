//
// Created by ecjun on 27/03/2024.
//

#include "fibonacci.hpp"

int fibonacciRecursivo(int n) {
    // Caso base
    if (n == 0 || n == 1) {
        return n;
    }

    // Caso recursivo
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int fibonnaciIterativo(int n) {

    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    return c;
}