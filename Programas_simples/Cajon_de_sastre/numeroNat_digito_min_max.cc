/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Nov 22 2022
 * @file numeroNat_digito_min_max.cc
 * @brief Dado un número natural, devolver los dígitos del número con valor máximo y mínimo. Así,
 *        para el número 9871 los dígitos de menor y mayor valor son 1 y 9 respectivamente.
 * @see https://www.github.com/Jaimalex
 */

#include <iostream>

int main() {
    
  int numero{0};
  int digito{0};
  int digito_mayor{0};
  int digito_menor{9};
  std::cin >> numero;
  if (numero > 0) {
    while (numero > 0) {
      digito = numero % 10;
      if (digito > digito_mayor) {
        digito_mayor = digito;
      }
      if (digito < digito_menor) {
        digito_menor = digito;
      }
      numero /= 10;
    }
    std::cout << "Dígito menor de su número natural: " << digito_menor << std::endl;
    std::cout << "Dígito mayor de su número natural: " << digito_mayor << std::endl;
  } else {
    std::cerr << "ERROR. Número introducido incorrecto. Por favor, introduzca un número natural. " << std::endl;
    return -1;
  }
  return 0;
}