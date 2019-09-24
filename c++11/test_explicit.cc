#include <cstring>
#include <iostream>
#include <memory>

// 加了explicit之后的代码
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

/*
class Point {
public:
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
};
void displayPoint(const Point &p) {
  cout << "(" << p.x << "," << p.y << ")" << endl;
}
int main() {
  displayPoint(1); //(存在隐式调用 )，加explicit后，是禁止的
  //而我们传入的是一个int, 这个程序却能成功运行, 就是因为这隐式调用
  Point p = 1; //(存在隐式转换)//
  //在对象刚刚定义时, 即使你使用的是赋值操作符=, 也是会调用构造函数,
  //而不是重载的operator=运算符.
}
*/

class Point {
public:
  int x, y;
  explicit Point(int x = 0, int y = 0)
      : x(x), y(y) {} // explicit 限定的构造函数
};

void displayPoint(const Point &p) {
  cout << "(" << p.x << "," << p.y << ")" << endl;
}

int main() {
  displayPoint(Point(1)); //采用构造函数,是允许的
  Point p(1);
}
