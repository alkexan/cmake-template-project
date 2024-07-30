#include "Singleton.hpp"
#include <iostream>


int main() {
  Singleton *singleton = Singleton::GetInstance("BAR");
  std::cout << singleton->value() << "\n";

  return 0;
}