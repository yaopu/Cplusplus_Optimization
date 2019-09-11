#include <array>
#include <iostream>
using namespace std;
int main() {

  array<int, 10> a;
  a.at(0) = 10;
  cout << a.size() << endl;
  return 0;
}