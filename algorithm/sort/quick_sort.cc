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

void quickSort(int *arr, int l, int r) { //输入参数
  int i, j, temp;
  if (l < r) {
    i = l;
    j = r;
    int x = arr[(l + r) / 2]; //
    //以中间元素为轴
    bool flag = true;
    while (flag) {
      while (i <= r && arr[i] < x) {
        i++;
      }
      while (j >= 0 && arr[j] > x) {
        j--;
      }
      if (i >= j) //相遇则跳出
      {
        flag = false;
      } else {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //交换
      }
    }
    quickSort(arr, l, i - 1); //对左半部分进行快排
    quickSort(arr, j + 1, r); //对右半部分进行快排
  }
}
