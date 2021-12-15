#include <bits/stdc++.h>
using namespace std;
//对由n的单数集构成的树做深度优先搜索
int dfs(int n){
  //至少为本身
  int res=1;
  if(n>1){
    for (int i = 1; i <= n/2; ++i) {
      res+= dfs(i);
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  cout << dfs(n);
}

