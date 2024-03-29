#include <iostream>
using namespace std;
// c++类拷贝构造什么时候被调用（初始化，值传递，作为函数返回值)
//（1）用类的一个对象去初始化另一个对象时
//（2）当函数的形参是类的对象时（也就是值传递时），[如果是引用传递则不会调用],值传递会调用
//（3）当函数的返回值是类的对象或引用时，

class A {
private:
  int a;

public:
  A(int i) { a = i; } //内联的构造函数
  A(A &aa)            //拷贝构造函数
  {
    a = aa.a;
    cout << "拷贝构造函数执行！" << endl;
  }
  int geta() { return a; }
};
int get_a(A aa) //参数是对象，是值传递，会调用拷贝构造函数
{
  return aa.geta();
}
//如果参数是引用类型，本身就是引用传递，所以不会调用拷贝构造函数
int get_a_1(A &aa) { return aa.geta(); }

//返回值是对象类型，会调用拷贝构造函数。
//会调用拷贝构造函数，因为函数体内生成的对象aa是临时的，离开这个函数就消失了。
//所有会调用拷贝构造函数复制一份。
A get_A() {
  A aa(1);
  return aa; //返还值为对象，会调用构造函数
}

//会调用拷贝构造函数，因为函数体内生成的对象aa是临时的，离开这个函数就消失了。所有会调用拷贝构造函数复制一份。
A &get_A_1() {
  A aa(1);
  return aa;
}

int main(int argc, char *argv[]) {
  A a1(1);             //默认构造函数
  A b1(a1);            //用a1初始化b1，调用拷贝构造函数
  A c1 = a1;           //用a1初始化c1，调用拷贝构造函数
  int i = get_a(a1);   //函数形参是类的对象，调用拷贝构造函数
  int j = get_a_1(a1); //函数形参类型是引用，不调用拷贝构造函数
  // A d1 = get_A();   //调用拷贝构造函数
  // A e1 = get_A_1(); //调用拷贝构造函数
  return 0;
}
