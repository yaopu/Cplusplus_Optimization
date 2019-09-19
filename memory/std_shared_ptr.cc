// shared_ptr::reset example
// unique_ptr::
//
// C++11的智能指针确实带来了很多方便，
//但是shared_ptr因为要维护很多元信息，会牺牲一些效率，如果大量使用智能指针
//一定不要忘记开启编译器的优化选项。。

#include <iostream>
#include <memory>
using namespace std;
void test_1();
void test_2();
void test_3();
int main() {

  // test_1();
  // test_2();

  test_3();
  return 0;
}

void test_3() {
  //重要的事情说三遍：
  //  unique_ptr 不能被拷贝
  // unique_ptr初始化的方法
  unique_ptr<int> up = make_unique<int>(10); // make_unique
  //  *up.get() = 10;
  //*up = 10;

  cout << "up所指向的地址:" << up.get() << endl;
  cout << "up地址的值" << *up.get() << endl;
}
void test_2() {
  shared_ptr<int> p = make_shared<int>(42);
  cout << "p所指对象的引用计数为：" << p.use_count() << endl;
  cout << "p所指向的地址:" << p.get() << endl;
  // p.reset(); 释放掉后，无法访问
  cout << "p地址的值" << *p.get() << endl;

  shared_ptr<int> q(p);
  cout << "p所指对象的引用计数为：" << p.use_count() << endl;

  shared_ptr<int> r = make_shared<int>(42);
  r = q;
  cout << "p所指对象的引用计数为：" << p.use_count() << endl;
}
void test_1() {
  std::shared_ptr<int> sp; // empty
  sp.reset(new int);       // takes ownership of pointer
  *sp = 10;
  cout << "p所指对象的引用计数为： " << sp.use_count() << endl;
  std::cout << *sp << '\n';
  sp.reset(new int); // deletes managed object, acquires new pointer
  *sp = 20;
  std::cout << *sp << '\n';
  sp.reset(); // deletes managed object
}
