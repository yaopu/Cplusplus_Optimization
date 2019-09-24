#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M N + 1
#define NUM (M + 1) * M / 2 //宏定义只是简单的文本替换
#pragma pack(2)
struct Test1 {
  int a;
  char b;
  short c;
  int *d;
} A;
#pragma pack()
#pragma pack(4)
struct Test2 {
  int *d;
  char b;
  int a;
  short c;
} B;

#pragma pack()

struct C {
  unsigned int a : 19;
  unsigned int b : 11;
  unsigned int c : 4;
  unsigned int d : 29;
  char index;
};

using namespace std;
int main() {
  cout << NUM << endl;
  printf("sizeof(1) = %d\n",sizeof(1));
  printf("sizeof(int) = %d\n", sizeof(int));
  printf("sizeof(float)=%d\n", sizeof(float));
  printf("sizeof(char)=%d\n", sizeof(char));
  // string
  printf("sizeof(double)=%d\n", sizeof(double));
  printf("short int =%d\n", sizeof(short int));
  printf("long double=%d\n", sizeof(long double));
  printf("usigned int =%d\n", sizeof(unsigned int));
  // pointer
  printf("sizeof(*int ) = %d\n", sizeof(int *));
  printf("sizeof(float *)=%d\n", sizeof(float *));
  printf("sizeof(double *) = %d\n", sizeof(double));
  printf("sizeof(A)=%d\n", sizeof(A));
  printf("sizeof(B) = %d\n", sizeof(B));
  C temp_c;
  printf("= %d\n", temp_c.c);

  //// int arr[2][3] = {{1, 2}, {3, 4}, {5, 6}};这是错误的定义方式
  //  int arr[2][3] = {{1, 2, 3}, {2, 3, 4}};
}
// 0x开头是16进制数
// 0开头是8进制数
