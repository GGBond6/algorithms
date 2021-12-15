#include <bits/stdc++.h>
using namespace std;
//求n的半数集个数
int dfs(int n) {
  //递归出口：半数集只有自身
  if (n <= 1) {
    return 1;
  }
  int res = 1;//自己本身肯定在半数集中，那么res初值为1
  for (int i = 1; i <= n / 2; ++i) {//可以将半数集看成一个多叉树，这里是递归遍历多叉树
    res += dfs(i);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << dfs(n);
}

