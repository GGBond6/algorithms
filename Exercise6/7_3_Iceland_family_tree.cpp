#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7 + 10;
int fa[N];
int find(int i) {
  return fa[i] == i ? fa[i] : fa[i] = find(fa[i]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  fa[a] = b;
}
int main() {
  for (int i = 0; i < N; ++i) {
    fa[i] = i;
  }
  int count;
  cin >> count;
  for (int i = 0; i < count; ++i) {
    int q, a, b;
    cin >> q >> a >> b;
    if (q == 1) {
      merge(a, b);
    } else {//q==2
      a = find(a);
      b = find(b);
      if (a == b) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}


