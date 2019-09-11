/*
 *
 * 201909

 * ofstream：写操作，由ostream引申而来
 * ifstream：读操作，由istream引申而来
 * fstream ：同时读写操作，由iostream引申而来
 *  yaoweipu@126.com
 * wechart 1417511526
 * about me https://yaopu.github.io
 */
// getchar()
#include <fstream>
#include <iostream>

namespace IO {
static void test_cin_cout() {
  int i;
  float r;
  std::string str;    // string
  std::cin >> i >> r; // int and float
  std::cin >> str;
  std::cout << i << " " << r << "\n";
  std::cout << str << "\n";
  // getline
  std::getline(std::cin, str);
  std::cout << str << "\n";

  char c[20];
  std::cin.get(c, 10, '\n');
  std::cout << c << "\n";

  // cin.get()
  // cin.get（字符指针，字符个数n，终止字符）
  //读取n-1个字符，若在n-1个字符之前遇到终止字符，提前结束读取
  // cin.get（字符数组，字符个数n，终止字符）
}

static void test_fin() {
  std::ifstream fin("test.txt"); // write to a file

  if (fin.is_open()) {
    char c = fin.get();

    while (fin.good()) {
      std::cout << c;
      c = fin.get();
    }
  } else {
    // show message:
    std::cout << "Error opening file"
              << "\n";
  }
}

static void test_fout() { //写入到文件内
  std::ofstream fout("out.txt");

  if (fout.is_open()) {

    std::string str;
    str = " I love Mace";
    fout << str;

  } else {
    std::cout << "Can not open file"
              << "\n";
  }
}

} // namespace IO

int main() {
  // IO::test_cin_cout();
  // IO::test_fin();
  IO::test_fout();
}
