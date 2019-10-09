// x^2 = n
#include <cmath>
#include <iostream>

using namespace std;
int n = 2;
float x_init = -1000000.0;
int count = 0;
float fun(float x) {
  count++;
  return (1.0 / x + x * 0.5);
}

float find_root(float x0) {
  float x1 = fun(x0);
  while (fabs(x1 - x0) > 1e-12) {
    x0 = x1;
    x1 = fun(x0);
  }
  return x1;
}
int main() {
  cout << find_root(x_init) << endl;
  cout << count << endl;
  return 0;
}
