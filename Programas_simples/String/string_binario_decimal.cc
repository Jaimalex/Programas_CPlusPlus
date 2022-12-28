/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Nov 22 2022
 * @file string_binario_decimal.cc
 * @brief Programa que toma como parámetro por línea de comandos un número binario e imprime en pantalla la representación decimal de ese número.
 * @see https://www.github.com/Jaimalex
 */

#include <iostream>
// #include <string>
#include <cmath>

int BinarioDecimal(const std::string& numero_binario) {
    
    int numero_decimal{0};
    int potencia{0};
    for (int i = numero_binario.length() - 1; i >= 0; --i ) { // numero_binario.length() = NULL, cadena.length() = NULL
        if(numero_binario[i] == '1') {
            numero_decimal += 1 * pow(2,potencia);
        }
        ++potencia;
    } 
    return numero_decimal;
}

int main(int argc, char* argv[]) { // char* argv[] = char argv [][]; char* argv = char argv[]

    char* numero_binario = argv[1]; // char* numero_binario = char numero_binario[]
    // INFO EXTRA - int numero_binario = std::stoi(argv[1]); // stoi() convierte una cadena de caracteres a un número
    std::cout << numero_binario << " en decimal es igual a: " << BinarioDecimal(numero_binario);
    return 0;
}