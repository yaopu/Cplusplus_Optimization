#include <iostream>
using namespace std;
int main() {
  const char *a = "123";
  const char *b = "123";
  if (a == b) {
    cout << "YES " << endl;
  }
  return 0;
}