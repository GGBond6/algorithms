#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int fa[N];//节点N的祖先为fa[N]

int find(int i) {
  return fa[i] == i ? fa[i] : fa[i] = find(fa[i]);
}

int merge(int a, int b) {
  a = find(a);
  b = find(b);
  fa[a] = b;
}

int main() {
  for (int i = 0; i < N; ++i) {
    fa[i] = i;
  }
  int num;
  cin >> num;
  //i表示当前是第几条边
  for (int i = 1; i <= num; ++i) {
    int x, y;
    cin >> x >> y;
    //如果当前两个节点的祖先相同，那么他们连接到一起后会形成闭环
    if (find(x) == find(y)) {
      cout << i;
      break;
    } else {
      merge(x, y);
    }
  }
}

