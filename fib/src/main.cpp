//
// Created by ecjun on 27/03/2024.
//


#include <iostream>
#include <chrono>

using namespace std;
using std::chrono::steady_clock;

// Implementação Fib Recursivo
unsigned long long int fibonacciRecursivo(int n, steady_clock::time_point limite) {

    //Verifica se o tempo atual já ultrapassou o limite
    if(steady_clock::now() >= limite) {
        return 0;
    }

    // Caso base
    if (n == 0 || n == 1) {
        return n;
    }

    // Caso recursivo
    return fibonacciRecursivo(n - 1, limite) + fibonacciRecursivo(n - 2, limite);
}

//Função de controle do FibRecursivo
int callFibonacciRecursivo(int segundos){

    //Contador de Fibs
    int cont_fib = 0;

    steady_clock::time_point limite = steady_clock::now() + chrono::seconds(segundos);

    while(true){
        //Verifica se o tempo atual já ultrapassou o limite
        if(steady_clock::now() >= limite) break;

        //Chama fibRecursivo(i)
        fibonacciRecursivo(cont_fib, limite);

        //Aumenta o contador
        cont_fib++;
    }
    //Retorna a posição do maior fib calculado
    return cont_fib;

}

void fibonacciIterativo(unsigned long long int n, steady_clock::time_point limite) {

    if(n <= 1) return;

    //Num antipenúltimo. F(N-2)
    unsigned long long int a = 1;
    //Num penúltimo F(N-1)
    unsigned long long int b = 1;
    //Num atual F(N)
    unsigned long long int c = 0;
    //Contador de Fibs. Já começa com 1 pois, na primeira interação já será calculado fib(2) = fib(1) + fib(0)
    unsigned long long int i = 1;

     //Verifica se o tempo atual já ultrapassou o limite

     while(i <= n) {

         //Verifica se o tempo atual já ultrapassou o limite
         if(steady_clock::now() >= limite) break;

         c = a + b;
         a = b;
         b = c;

         i++;
     }

}

unsigned long long int callFibonacciIterativo(int segundos){

    //Contador de Fibs
    unsigned long long int cont_fib = 0;

    steady_clock::time_point limite = steady_clock::now() + chrono::seconds(segundos);

    while (true) {

        //Verifica se o tempo atual já ultrapassou o limite
        if(steady_clock::now() >= limite) break;

        //Chama fibIterativo(i)
        fibonacciIterativo(cont_fib, limite);

        //Aumenta o contador
        cont_fib++;
    }

    //Retorna a posição do maior fib calculado
    return cont_fib;

}



int main () {

    cout << "Fibonnaci Iterativo" << endl << "-------------------------------------------------------" << endl;
    cout << "Fib(15 segundos): " << callFibonacciIterativo(15) << endl;
    cout << "Fib(30 segundos): " << callFibonacciIterativo(30) << endl;
    cout << "Fib(45 segundos): " << callFibonacciIterativo(45) << endl;
    cout << "Fib(60 segundos): " << callFibonacciIterativo(60) << endl;
    cout << "Fib(75 segundos): " << callFibonacciIterativo(75) << endl;
    cout << "Fib(90 segundos): " << callFibonacciIterativo(90) << endl;
    cout << "Fib(105 segundos): " << callFibonacciIterativo(105) << endl;
    cout << "Fib(120 segundos): " << callFibonacciIterativo(120) << endl;
    cout << "-------------------------------------------------------" << endl;

    cout << "Fibonnaci Recursivo" << endl << "-------------------------------------------------------" << endl;
    cout << "Fib(15 segundos): " << callFibonacciRecursivo(15) << endl;
    cout << "Fib(30 segundos): " << callFibonacciRecursivo(30) << endl;
    cout << "Fib(45 segundos): " << callFibonacciRecursivo(45) << endl;
    cout << "Fib(60 segundos): " << callFibonacciRecursivo(60) << endl;
    cout << "Fib(75 segundos): " << callFibonacciRecursivo(75) << endl;
    cout << "Fib(90 segundos): " << callFibonacciRecursivo(90) << endl;
    cout << "Fib(105 segundos): " << callFibonacciRecursivo(105) << endl;
    cout << "Fib(120 segundos): " << callFibonacciRecursivo(120) << endl;
    cout << "-------------------------------------------------------" << endl;


    return 0;
}