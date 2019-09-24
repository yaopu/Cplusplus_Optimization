/*
内存用不完的时候，可以请求系统归还内存，最后，使得 capacity()==size()
3、预先保留空间——reserve() 和 resize() 函数
*/
#include <iostream>
#include <vector>
using namespace std;

void test_reserve() {
  vector<int> myVec;
  myVec.reserve(100); // 新元素还没有构造,

  cout << "  myVec.reserve(100)" << endl;
  // 此时不能用[]访问元素
  for (int i = 0; i < 100; i++) {
    myVec.push_back(i); //新元素这时才构造
  }

  cout << "没有进行 resize前的尺寸" << myVec.size() << "  " << myVec.capacity()
       << endl;
  cout << " myVec.resize(102) " << endl;
  myVec.resize(102); // 用元素的默认构造函数构造了两个新的元素
  cout << "resize(102)" << endl;
  cout << myVec.size() << "  " << myVec.capacity() << endl;
  myVec[100] = 1; //直接操作新元素
  myVec[101] = 2;
}

void test_shrink_to_fit() {
  vector<int> v1;
  for (int i = 1; i < 11; i++) {
    v1.push_back(i);
  }
  cout << "capacity = " << v1.capacity() << "    "
       << "size = " << v1.size() << endl;
  v1.shrink_to_fit();
  cout << v1.capacity() << endl;
}

int main() {
  test_reserve();
  test_shrink_to_fit();
  return 0;
}