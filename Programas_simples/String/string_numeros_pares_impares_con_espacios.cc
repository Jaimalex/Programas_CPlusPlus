#include <iostream>
// #include <string>

int main() {
  std::string cadena;
  getline(std::cin, cadena);
  int suma_de_pares{0};
  int suma_de_impares{0};
  for (int i = 0; i < cadena.length(); ++i) {
    if (isdigit(cadena[i])) {
      char mi_char = cadena[i];
      int mi_numero = static_cast<int>(mi_char);
      if (mi_numero % 2 == 0) {
        suma_de_pares++;
      } else {
        suma_de_impares++;
      }
    }
  }
  std::cout << "Suma de pares: " << suma_de_pares;
  std::cout << " Suma de impares: " << suma_de_impares << " ";
}
