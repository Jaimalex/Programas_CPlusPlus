#include <iostream>
#include <vector>

int main() {
  std::vector<char> vector;
  char stop{0};
  std::cout << " ' x ' para terminar de añadir elementos al vector. " << std::endl;
  while(stop != 'x'){
    std::cin >> stop;
    if (stop != 'x') {
      vector.push_back(stop);
    }
  }
  for (const auto& auxiliar : vector) {  // referencia - ganamos rendimiento al no hacer copia de la variable auxiliar.
    std::cout << auxiliar << " ";        // constante - el valor de auxiliar no se verá modificado ?
  }
}