/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Nov 22 2022
 * @file string_anterior_posterior_decimal_ASCII.cc
 * @brief Desarrolle un programa que tome por línea de comandos una cadena de texto y la
 *        almacene en una std::string con identificador “input_string”. A continuación el
 *        programa ha de imprimir en pantalla otras dos cadenas “one_more” y “one_less”
 *        que serán cadenas obtenidas a partir de la primera sustituyendo cada carácter de
 *        la cadena original por el siguiente carácter de la tabla ASCII y por el
 *        anterior, respectivamente. El programa deberá imprimir también cada uno de los
 *        caracteres de “input_string” separados por un guión del código ASCII (decimal)
 *        correspondiente al carácter.
 * @see https://www.github.com/Jaimalex
 */

/* INFORMACIÓN RELEVANTE
Igualamos one_more a input_string porque necesitamos reservar los espacios para los caracteres de la cadena, ----> 
----> probar std::string one_more = "ab", cambiará sólo dos letras ---->
----> std::string input_string = "casa"((argv[1])) , std::string one_more = "ab" ---->
----> Si igualamos one_more[i] = input_string[i] one_more no tendrá esa posición porque es más pequeña y tiene menos caracteres ---->
----> La cadena one_more se quedará con dos caracteres, siendo éstos los dos primeros del input_string (ca) (+ 1) -> (db), como calculamos en el programa, ---->
----> pasando los caracteres de input_string al siguiente carácter siguiendo la tabla ASCII ---->
----> Es indeferente lo que ponga en one_more porque igualamos abajo sus posiciones a las de input_string. Metemos lo que haya en input_string (+ 1) en one_more
*/

#include <iostream>
// #include <string>

int main(int argc, char* argv[]) {

  std::string input_string = argv[1];
  std::string one_more = input_string; 
  std::string one_less = input_string; 
  for (int i = 0; i < input_string.length(); ++i) {
    one_more[i] = input_string[i] + 1;
    one_less[i] = input_string[i] - 1;
  }
  std::cout << "Cadena one_more: " << one_more << std::endl;
  std::cout << "Cadena one_less: " << one_less << std::endl;
  for (int j = 0; j < input_string.length(); ++j) {
    int decimal = static_cast<int>(input_string[j]);
    std::cout << input_string[j] << " - " << decimal << " ";
  }
  return 0;
}