#include <iostream>
#include <stack>
#include <vector>

///没有迭代器
///没有at()
///没有insert
//总的出栈可能性为C(n,2n)/(n+1)
using namespace std;
int nElement;
int *arr;

void dfs(stack<int> p, vector<int> ans, int cur) {
  if (cur == nElement && p.empty()) //边界输出结果
  {
    for (int i = 0; i < ans.size(); i++)
      cout << ans.at(i); //只有一处输出
    cout << "\n";
    return;                                 ///终止条件
  } else if (cur == nElement && !p.empty()) //全部出栈到结果中
  {
    int ch = p.top();
    ans.push_back(ch);
    p.pop();
    dfs(p, ans, cur); //递归
    p.push(ch);
    ans.pop_back();
    return;
  }
  if (!p.empty()) // 枚举出栈的个数
  {
    stack<int> nS = p;
    vector<int> nans = ans;
    while (!nS.empty()) {
      nans.push_back(nS.top());
      nS.pop();
      nS.push(arr[cur]);
      dfs(nS, nans, cur + 1); //递归
      nS.pop();
    }
  }
  //选择此次不出栈
  p.push(arr[cur]);
  dfs(p, ans, cur + 1); //
  p.pop();
}

int main() {
  nElement = 5;
  arr = new int[nElement];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  arr[4] = 5;
  stack<int> p;
  vector<int> ans;
  dfs(p, ans, 0);
  return 0;
}