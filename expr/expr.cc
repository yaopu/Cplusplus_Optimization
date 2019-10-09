//表达式前后缀表达形式
#include <iostream>
using namespace std;

void test1() {}
int main() {

  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;
  cout << ((a + (b * c)) - (d + e)) << endl;
  cout << -(+(a * (bc)) + (de)) << endl;

  return 0;
}