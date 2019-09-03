// shared_ptr::reset example
#include <iostream>
#include <memory>
void simple_test();
int main() {
  simple_test();
  return 0;
}

void simple_test()
{
  std::shared_ptr<int> sp; // empty
  sp.reset(new int);       // takes ownership of pointer
  *sp = 10;
  std::cout << *sp << '\n';
  sp.reset(new int); // deletes managed object, acquires new pointer
  *sp = 20;
  std::cout << *sp << '\n';
  sp.reset(); // deletes managed object
}