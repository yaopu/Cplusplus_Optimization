//使用printf函数打印一个double类型的数据，要求：输出为10进制，输出左对齐30个字符，4位精度
#include <stdio.h>
#include <stdlib.h>

int main(int, char **) {
  printf("%-30.4e\n", 2019093.1415628);
  printf("%-30.4f\n", 2019093.1415628);
  printf("%-4.30e\n", 2019093.1415628);
  printf("%4.30e\n", 2019093.1415628);

  return 0;
}
