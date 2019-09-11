//递归方法实现归并排序
//理解递归的执行过程
// 1.每一级的递归都使用它自己的私有的变量
// 2.栈的结构来理解
#include <iostream>
using namespace std;
void merge(int *A, int *L, int leftCount, int *R, int rightCount); //归并
void mergesort(int *A, int n) { //传入参数，数组，数组长度
  int mid, i, *L, *R;
  if (n < 2) //如果元素少于两个，递归停止条件
    return;
  mid = n / 2;
  L = new int[mid];
  for (i = 0; i < mid; i++) {
    L[i] = A[i]; // 构建左子序列
  }

  R = new int[n - mid]; //构建右子序列
  for (i = mid; i < n; i++) {
    R[i - mid] = A[i];
  }

  mergesort(L, mid);            //递归左  分左右
  mergesort(R, n - mid);        //递归右
  merge(A, L, mid, R, n - mid); // 归并.
  delete[] R;                   //不能忘掉delete 内存
  delete[] L;                   //不能忘掉delete内存
}

void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
  int i = 0; // i,左子序列下标索引
  int j = 0; // j,右子序列下标索引
  int k = 0; // k，归并完毕后的坐标索引

  while (i < leftCount && j < rightCount) { //下标是且操作
    if (L[i] < R[j])                        //排序
      A[k++] = L[i++];
    else
      A[k++] = R[j++];
  } //当一个序列走完了，另外一个序列还有剩余，把余下的添加到A中
  while (i < leftCount) //剩余的往后放
    A[k++] = L[i++];
  while (j < rightCount)
    A[k++] = R[j++];
}

int main() {

  int A[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17}; // 赋予初始值.
  int numberOfElements = sizeof(A) / sizeof(A[0]);
  mergesort(A, numberOfElements); //归并排序

  for (int i = 0; i < numberOfElements; i++)
    cout << " " << A[i] << '\n';
  return 0;
}
