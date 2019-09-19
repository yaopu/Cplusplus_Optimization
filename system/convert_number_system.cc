// https://blog.csdn.net/florachy/article/details/79573427
// 3个二进制，表示一个8进制
/// 4个二进制，表示一个16进制
#include <iostream>
#include <stack>
using namespace std;
//没有终止条件的递归，栈溢出
void ten2binary(int a, stack<int> &s) {
  if (a == 0) {
    return;
  }
  if (a == 1) {
    s.push(a % 2);
    return;
  }
  s.push(a % 2);
  // cout << a % 2 << endl;
  ten2binary(a / 2, s);
}
int main() {

  stack<int> s;
  ten2binary(10, s);
  while (s.size() != 0) {
    cout << s.top() << "  ";
    s.pop();
  }

  
  cout << endl;
  return 0;
}