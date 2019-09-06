////虚函数之间的overload
#include <iostream>
using namespace std;

class Base {
public:
  virtual void f(int);
};
void Base::f(int a) { cout << a << endl; }

class Drived : public Base {
public:
  virtual void f();
};
void Drived::f() { cout << "Drived" << endl; }

int main() {

  Base *p1 = new Base;
  p1->f(100);
  Drived *p2 = new Drived;
  p2->f();
  Base *p3 = new Drived;
  p3->f(1000);
  p3->f(); //这种是错误的！！！
}