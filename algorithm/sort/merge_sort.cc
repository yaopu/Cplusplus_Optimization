#include <iostream>

using namespace std;
void merget_sort(); //采用递归方法实现归并排序
void merge(int *A, int *L, int leftCount, int *R, int rightCount); //归并
void mergesort(int *A, int n) {
  int mid, i, *L, *R;
  if (n < 2)
    return;    ///如果元素少于两个，则不必排序
  mid = n / 2; /// 寻找中间元素
  /// 构建左右子序列
  // mid elements (from index 0 till mid-1) should be part of left sub-array
  // and (n-mid) elements (from mid to n-1) will be part of right sub-array
  L = new int[mid];
  R = new int[n - mid];

  for (i = 0; i < mid; i++)
    L[i] = A[i]; // 构建左子序列
  for (i = mid; i < n; i++)
    R[i - mid] = A[i]; //构建右子序列

  mergesort(L, mid);     // sorting the left subarray
  mergesort(R, n - mid); // sorting the right subarray

  merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
  // the delete operations is very important
  delete[] R;
  delete[] L;
}

void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
  int i = 0; // i,左子序列下标索引
  int j = 0; // j,右子序列下标索引
  int k = 0; // k，归并完毕后的坐标索引

  while (i < leftCount && j < rightCount) {
    if (L[i] < R[j])
      A[k++] = L[i++];
    else
      A[k++] = R[j++];
  } //当一个序列走完了，另外一个序列还有剩余，把余下的添加到A中
  while (i < leftCount)
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
