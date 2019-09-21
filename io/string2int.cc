#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int string2int(string ss) {
  int value;

  for (int i = 0; i < ss.length(); i++) {
    value = atoi(&ss[0]);
  }
  return value;
}
int main() {

  string s;
  cin >> s;
  cout << string2int(s) << endl;

  return 0;
}