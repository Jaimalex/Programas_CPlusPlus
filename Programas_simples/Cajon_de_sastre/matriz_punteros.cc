#include <iostream>

int main() {

  int matriz[3][2] = {{1,1}, {2,2}, {3,3}};
  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 2; ++j) {
      std::cout << *(matriz[i] + j);
    }
    std::cout << '\n';
  }
  return 0;
}