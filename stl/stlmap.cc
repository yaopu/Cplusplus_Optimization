#include <iostream>
#include <map>

int main() {
  std::map<char, int> mymap;
  mymap['a'] = 100;
  mymap['b'] = 200;
  mymap['c'] = 300;

  /// iterator of map
  for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end();
       it++) {
    std::cout << it->first << "  " << it->second << std::endl;
  }
  /// insert
  std::pair<char, int> a('k', 100);
  mymap.insert(a);
  std::cout << mymap.size() << std::endl;
  // find elements
  std::map<char, int>::iterator it;
  it = mymap.find('k');
  std::cout << it->first << "  " << it->second << std ::endl;
  return 0;
}
