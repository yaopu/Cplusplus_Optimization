#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n = 5;
  vector<int> a;
  set<int> b;
  for (int i = 0; i < n; i++) {
    a.push_back(i);
    b.insert(i);
  }

  for (int i = 0; i < n; i++) {
    a.push_back(i);
    b.insert(i);
  }
  cout << a.size() << b.size() << endl;
  cout << *b.find(1); //返回的是迭代器
  return 0;
}