#include <iostream>

struct A {
  bool a;
  double b;
  int c;
};

int main(int, char **) {
  std::cout << "Hello, from algo4th!\n";
  std::cout << sizeof(A) << std::endl;
}
