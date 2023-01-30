
/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Ene 30 2023
 * @file numero_guay.cc
 * @brief Un número natural se dice que es guay si la suma de los dígitos que
 *        están en posiciones impares (empezando a contar por la derecha) es un
 *        número par. Por ejemplo, 2 y 679031 son números guay, pero 357199 y
 *        607 no lo son.
 * @see https://www.github.com/Jaimalex
 */

#include <cstring>
#include <iostream>

int main() {
  std::string cadena;
  std::cin >> cadena;
  int impar{1};
  int suma{0};
  for (int i = cadena.length() - 1; i >= 0; --i) {
    int numero = cadena[i] - '0'; // cadena[i] = char, int = ASCII del char; 0 = char, int = ASCII de 0 = 48
    if (impar % 2 != 0) {
      suma += numero;
    }
    ++impar;
  }
  if (suma % 2 == 0) {
    std::cout << "Es un número guay. "
              << "\n";
  } else {
    std::cout << "No es un número guay. "
              << "\n";
  }
  return 0;
}