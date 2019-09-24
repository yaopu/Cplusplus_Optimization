#include <iostream>

using namespace std;

int main() {
  int a[5] = {1, 2, 3, 4, 5};

  cout << a << endl;
  //  cout << a + 1 << endl;
  //  cout << a + 2 << endl;
  //  cout << a + 3 << endl;
  //  cout << a + 4 << endl;
  //  cout << a + 5 << endl;
  //  cout << a + 6 << endl;
  // cout << a + 1000 << endl;

  // cout << (&a) << endl;
  //  cout << *(&a) << endl;

  // cout << &a + 1 << endl;

  int *p = a; //指针指向数组的头部
  int *q = (int *)(&a);

  cout << *q << endl;
  // cout << q << endl;
  // cout << *(q - 1) << endl;

  return 0;
}