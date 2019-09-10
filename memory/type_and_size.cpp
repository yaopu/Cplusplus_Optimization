#include <stdio.h>
#include <stdlib.h>
int main() {
  printf("sizeof(int) = %d\n", sizeof(int));
  printf("sizeof(float)=%d\n", sizeof(float));
  printf("sizeof(char)=%d\n", sizeof(char));
  // string
  printf("sizeof(double)=%d\n", sizeof(double));
  printf("short int =%d\n", sizeof(short int));
  printf("long double=%d\n", sizeof(long double));
  printf("usigned int =%d\n", sizeof(unsigned int));

  //// int arr[2][3] = {{1, 2}, {3, 4}, {5, 6}};这是错误的定义方式
  //  int arr[2][3] = {{1, 2, 3}, {2, 3, 4}};
}
// 0x开头是16进制数
// 0开头是8进制数
