#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int flag;
vector<int> people[N];
bool vis[N];
char sex[N];
void dfs(int my, int num) {
  if (num >= 4) {
    return;
  }
  for (int i = 0; i < people[my].size(); ++i) {
    if (vis[people[my][i]] == 1) {
      flag = 0;
      return;
    } else {
      vis[people[my][i]] = 1;
      dfs(people[my][i], num + 1);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int my, fa, ma;
    char c;
    cin >> my >> c >> fa >> ma;
    sex[my] = c;
    if (fa != -1) {//如果没有父亲或母亲就不存储
      people[my].push_back(fa);
      sex[fa] = 'M';
    }
    if (ma != -1) {
      people[my].push_back(ma);
      sex[ma] = 'F';
    }
  }
  int count;
  cin >> count;
  for (int i = 0; i < count; ++i) {
    memset(vis, 0, sizeof(vis));//将vis数组全部清零
    int x;
    int y;
    cin >> x >> y;
    if (sex[x] == sex[y]) {
      cout << "Never Mind" << endl;
    } else {
      //这里使用深度优先遍历
      vis[x] = 1;
      vis[y] = 1;
      flag = 1;//恢复可结婚标志
      dfs(x, 0);//若在遍历过程中，存在vis=1，那么存在存在相同的先辈，不可结婚
      dfs(y, 0);
      if (flag) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}