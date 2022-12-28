#include <iostream>

class Vm {

  double cadena_[10];
  double matriz_[10][10]{};

  public:

  double& operator[](int indice);
  double& operator()(int m, int n);

};

double& Vm::operator[](int indice) {

  return{cadena_[indice]};
}

double& Vm::operator()(int m, int n) {

  return{matriz_[m][n]};
}

int main() {

  Vm vm;
  vm[5] = 3;
  std::cout << vm[5] << std::endl;
  vm(1, 1) = 3;
  std::cout << vm(1, 1) << std::endl;
  return 0;
}