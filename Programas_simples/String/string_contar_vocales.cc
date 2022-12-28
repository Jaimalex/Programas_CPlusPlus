/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Nov 22 2022
 * @file string_contar_vocales.cc
 * @brief Escribir una función CountVowels(const std::string& text) que devuelva el número
 *        de vocales que se encuentran en la cadena de texto que se le pasa como parámetro.
 * @see https://www.github.com/Jaimalex
 */

#include <iostream>
// #include <string>

int CountVowels(const std::string& text) { 

  int suma_vocales{0};
  for (auto i : text) { // for (int i = 0; i < text.length(); ++i)
    switch (i) { // switch (text[i])
      case 'a':
        ++suma_vocales;
        break;
      case 'A':
        ++suma_vocales;
        break;
      case 'e':
        ++suma_vocales;
        break;
      case 'E':
        ++suma_vocales;
        break;
      case 'i':
        ++suma_vocales;
        break;
      case 'I':
        ++suma_vocales;
        break;
      case 'o':
        ++suma_vocales;
        break;
      case 'O':
        ++suma_vocales;
        break;
      case 'u':
        ++suma_vocales;
        break;
      case 'U':
        ++suma_vocales;
        break;
    }
  }
  return suma_vocales;
}

int main() {

  std::string cadena;
  getline(std::cin, cadena);
  std::cout << "Número de vocales encontradas en la cadena de texto: " << CountVowels(cadena) << std::endl;
  return 0;
}
