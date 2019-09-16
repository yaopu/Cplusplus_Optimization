#include <iostream>
void quickSort(int *, int, int);
int main() {

  int arr[] = {1, 34, 412, 20, 8291};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << "  ";
  }
  std::cout << "\n";
}

void quickSort(int *arr, int lelf, int right) { //输入参数
  //升序排列
  int i, j, temp;
  if (lelf < right) {
    i = lelf;
    j = right;
    int x = arr[(lelf + right) / 2]; // x为中间值
    bool flag = true;
    while (flag) {
      while (i <= right && arr[i] < x) {
        i++; //左边的往右边走，找到大于x的元素
      }
      while (j >= 0 && arr[j] > x) {
        j--; //右边往左边走，找到小于x的元素
      }
      if (i >= j) //相遇则跳出
      {
        flag = false;
      } else {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //交换这两个元素
      }
    }
    quickSort(arr, lelf, i - 1); //对左半部分进行快排，输入参数形式
    quickSort(arr, j + 1, right); //对右半部分进行快排,输入参数形式
  }
}
