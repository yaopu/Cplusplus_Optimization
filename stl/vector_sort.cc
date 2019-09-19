//  sort(num.begin(), num.end(), sortFun);
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> p;

  p.push_back(2);
  p.push_back(5);
  p.push_back(1);
  p.push_back(0);

  vector<int>::iterator it = p.begin();
  while (it != p.end()) {
    cout << *it++ << endl;
  }

  sort(p.begin(), p.end());

  it = p.begin();
  while (it != p.end()) {
    cout << *it++ << endl;
  }

  reverse(p.begin(), p.end()); ///反序列

  it = p.begin();
  while (it != p.end()) {
    cout << *it++ << endl;
  }

  return 0;
}
