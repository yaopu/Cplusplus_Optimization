#include <iostream>
using namespace std;
class Base {
public:
  virtual void f();
  void f2() { cout << "YES Base" << endl; }
};

void Base::f() {

  cout << "Base f()"
       << "\n";
}

class Derived : public Base {

public:
  virtual void f();
  void f2() { cout << "YES Derived " << endl; }
};
void Derived::f() { cout << "Derived::f()" << endl; }

int main() {
  Base *p1 = new Base;
  Base *p2 = new Derived;
  Derived *p3 = new Derived;
  // Derived *p4 = new Base; //子类 new 父类是不行的

  p1->f();
  p2->f();
  p2->f2();
  p3->f();
  p3->f2();
  p3->Base::f();

  delete p1;
  delete p2;
}