
/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Nov 22 2022
 * @file string_mayusculas_minusculas.cc
 * @brief Cambiar las mayúsculas por minúsculas y las minúsculas por mayúsculas en una cadena de texto.
 * @see https://www.github.com/Jaimalex
 */

#include <iostream>
// #include <string>

int main(){

  std::string cadena;
  getline(std::cin, cadena); // std::cin >> cadena, teniendo en cuenta los espacios entre palabras
  for (int i = 0; i < cadena.length(); ++i) {
    if (isupper(cadena[i])) {
      cadena[i] = tolower(cadena[i]);
    } else { // if (islower(cadena[i]))
      cadena[i] = toupper(cadena[i]);
    }
  }
  std::cout << cadena << std::endl;
  return 0;
}
