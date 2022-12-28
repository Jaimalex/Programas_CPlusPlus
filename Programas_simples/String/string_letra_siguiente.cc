/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Nov 22 2022
 * @file string_letra_siguiente.cc
 * @brief Cambiar cada una de las letras presentes en una cadena de texto por la letra siguiente del alfabeto.
 * @see https://www.github.com/Jaimalex
 */

#include <iostream>
// #include <string>

int main() {
    
  std::string cadena;
  getline(std::cin, cadena);
  for (int i = 0; i < cadena.length(); ++i) {
    if (isalpha(cadena[i])) {
      if (cadena[i] == 'z') {
        cadena[i] = 'a';
      } else if (cadena[i] == 'Z') {
        cadena[i] = 'A';
      } else {
        ++cadena[i];  // IEEE 754. a = 97, ++a = 98 = b;
      }
    }
  }
  std::cout << cadena << std::endl;
  return 0;
}