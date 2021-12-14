#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int hobby[N];//N代表爱好，hobby[N]代表此兴趣群聊的群主，hobby默认为0，即没有群主
int fa[N];//N代表用户，fa[N]代表当前用户所在兴趣群的群主，fa[N]默认为N，即群主为自己
int peopleNum;//用户数量
//查：找到当前元素所在群聊的群主
int find(int i) {
  return fa[i] == i ? fa[i] : fa[i] = find(fa[i]);
}
//并：将a所在群聊并到b所在群聊
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  fa[a] = b;
}

int main() {
  //初始化
  for (int i = 0; i < N; ++i) {
    fa[i] = i;
  }

  cin >> peopleNum;
  for (int i = 1; i <= peopleNum; ++i) {
    int hobbyNum;
    char c;
    cin >> hobbyNum >> c;
    for (int j = 1; j <= hobbyNum; ++j) {
      int x;
      cin >> x;
      if (hobby[x] == 0) {
        //当前兴趣还没有兴趣群，那么设置当前用户为兴趣群的群主
        hobby[x] = i;
      } else {
        //当前兴趣群已经存在，群主为hobby[x]；那么将当前用户加入兴趣群
        merge(i, find(hobby[x]));
      }
    }
  }
  map<int, int> map;
  //提取出每个群聊的人数
  for (int i = 1; i <= peopleNum; ++i) {
    map[find(i)]++;
  }
  vector<int> res;
  for (auto x: map) {
    res.push_back(x.second);
  }
  sort(res.begin(), res.end(), greater<>());
  int size = res.size();
  cout << size << endl;
  int flag = 0;
  for (int i = 0; i < size; ++i) {
    if (flag == 0) {
      flag = 1;
    } else {
      cout << ' ';
    }
    cout << res[i];
  }
}