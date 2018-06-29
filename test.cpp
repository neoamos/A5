#include <iostream>
#include <iostream>
#include "tombstones.h"

int main() {

  Pointer<int> foo4(new int(10));
  Pointer<int> foo5((int*) NULL);
Pointer<int> foo6(foo5);
  foo5 = NULL;
  int* a = (int*) NULL;
  

  std::cout << (foo5 == foo6) << std::endl;
  
  free(foo4);

  //int a = *bar;
  // std::cout << **(bar.obj) << std::endl;
  // std::cout << **(bar.obj) << std::endl;
  // Pointer<int> foo(bar);
  // *foo = 6;
  // std::cout << (bar == 6);
  return 0;
}
