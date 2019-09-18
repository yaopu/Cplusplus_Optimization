#include <iostream>
#include <map>
#include <string>
using namespace std;
///查找的复杂度基本是Log(N)
///存储Key-value对
///按照键值自动排序
void test_insert_and_find() {

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
}

void test_map_string_int() {
  map<string, int> dict; // int 对应的初始值为0
  string str1("I have");
  dict[str1]++;
  string str2("I DO");
  dict[str2]++;
  cout << dict.size() << endl;

  map<string, int>::iterator it = dict.begin();
  for (; it != dict.end(); ++it)
    cout << it->first << "  " << it->second << endl;
}

void test_map_int_string() {
  ///采用数组方式插入
  map<int, string> dict; // int 对应的初始值为0
  string str1("I have");
  dict[0] = "I have";
  dict[2] = " I love"; //是允许的
  dict[1] = " I DO";
  cout << dict.size() << endl;

  map<int, string>::iterator it = dict.begin();
  for (; it != dict.end(); ++it)
    cout << it->first << "  " << it->second << endl;
}

void test_insert_and_see_sort() {
  map<int, string> dict;

  pair<int, string> pair1(1, "me");
  pair<int, string> pair2(2, "feng");
  pair<int, string> pair3(3, "xia");
  dict.insert(pair1);
  dict.insert(pair3);
  dict.insert(pair2);

  map<int, string>::iterator it = dict.begin();
  for (; it != dict.end(); ++it)
    cout << it->first << "  " << it->second << endl;
}

int main() {
  // test_map_int_string();
  test_insert_and_see_sort();
  return 0;
}
