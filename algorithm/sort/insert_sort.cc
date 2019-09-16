/*insert sort
移动、比较的次数可作为衡量时间复杂性的标准。
　　最优情况：如果原始的输入序列为正序：
　　比较次数：n-1
　　移动次数：0
　　最差情况：如果原始的输入序列为逆序：
　　比较次数：(n+2)(n-1)/2
　　移动次数：(n+4)(n-1)/2
　　所以直接插入排序的时间复杂度为O(n2)。
*/
#include <iostream>
using namespace std;
void insertSort(int arr[], int n);
int main() {

  int arr[] = {1, 34, 412, 20, 8291};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertSort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << "  ";
  }
  std::cout << "\n";
}

void insertSort(int arr[], int n) {
  for (int i = 1; i < n; i++) { //从1开始遍历
    int temp = arr[i];
    int j = i - 1;          //起始位置
    while (temp < arr[j]) { //思考，如何挪动？
      arr[j + 1] = arr[j];
      j--; //数组往后移动
      if (j == -1) {
        break;
      }
    }
    arr[j + 1] = temp; //此时j==-1,j+1 =1
                       //移动空了的位置给arr[i]
  }
}