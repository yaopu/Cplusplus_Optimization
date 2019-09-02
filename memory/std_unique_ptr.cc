#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> up; // empty
  up.reset(new int);       // take ownership of pointer
  *up = 5;
  std::cout << *up << std::endl;
  up.reset(new int); // deletes managed objects,acquires new pointer
  *up = 10;
  std::cout << *up << '\n';
  //  up.reset(); //deletes managed objects
  std::cout << up.get() << '\n';  //输出地址
  std::cout << *up.get() << '\n'; //输出地址里的值
  up.release();                   //释放
  std::cout << up.get() << "\n";

  return 0;
}