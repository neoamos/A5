#include <iostream>
#include "tombstones.h"

int main() {
  Pointer<int> bar(new int(5));
  std::cout << **(bar.obj) << std::endl;
  //int a = *bar;
  std::cout << **(bar.obj) << std::endl;
  std::cout << **(bar.obj) << std::endl;
  // Pointer<int> foo(bar);
  // *foo = 6;
  // std::cout << (bar == 6);
  return 0;
}
