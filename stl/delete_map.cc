#include <iostream>
#include <map>
using namespace std;
// sougou interviw problem, how to delete a container
int main() {

  map<int, int> A;
  for (int i = 0; i < 10; i++) {
    A.insert(pair<int, int>(i, i)); // A.insert(i, i)是错误的
  }

  map<int, int>::iterator it = A.begin();

  while (A.size() != 0) {
    cout << it->first << " ";
    cout << it->second << endl;
    A.erase(it);
    it++;
  }
  /*
    while (it != A.end()) {
      cout << it->first << " ";
      cout << it->second << endl;
      A.erase(it);
      it++;
    }
  */
  return 0;
}