
/* 201909
 * 一重vector 对应一维数组
 * 二重vector 却难说对应二重数组！！
 *  yaoweipu@126.com
 * wechart 1417511526
 * about me https://yaopu.github.io
 */
#include <iostream>
#include <vector>

using namespace std;
struct DataType {
  int a, b, c;
};

void copy_vector_1D() {
  vector<DataType> A;
  for (int i = 0; i < 10; i++) {
    DataType temp_a = {i, i, i};
    A.push_back(temp_a);
  }

  vector<DataType> B(A);
  for (vector<DataType>::iterator it = B.begin(); it != B.end(); it++) {
    cout << it->a << "   " << it->b << "  " << it->c << endl;
  }
}

void copy_vector_2D() {
  vector<vector<DataType>> B;

  for (int i = 0; i < 10; i++) {
    vector<DataType> A;
    for (int j = 0; j <= i; j++) {
      DataType temp_a = {j, j, j};
      A.push_back(temp_a);
    }
    B.push_back(A);
  }

  vector<vector<DataType>> C(B); //构造拷贝函数
  for (int i = 0; i < C.size(); i++) {
    vector<DataType> A = C.at(i);
    for (vector<DataType>::iterator it = A.begin(); it != A.end(); it++) {
      cout << it->a << "  " << it->b << "  " << it->c << "\n";
    }
  }
}

int main() {
  // copy_vector_1D();
  copy_vector_2D();
}
