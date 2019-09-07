#include <iostream>
#include <memory.h>
#include <string>
#include <vector>

using namespace std;

void show_vector(vector<int> a) {

  for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
    cout << *it << "\n";
  }
}
void test_vector_naive() {
  vector<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  a.push_back(40);
  show_vector(a);

  int *b = new int[a.size()];
  memcpy(b, &a[0], a.size() * sizeof(int));

  for (int i = 0; i < a.size(); i++) {
    cout << b[i] << "\n";
  }
  delete[] b;
  b = nullptr;
}

int main() { test_vector_naive(); }