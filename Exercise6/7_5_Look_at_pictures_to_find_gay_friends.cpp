#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int pictureNum;
int times = 0;//合并次数，每一次合并，那么分组就少一个，分组个数=总人数-合并次数
int m = 0;//记录最大编号，即总人数
int fa[N];
int find(int i) {
  return fa[i] == i ? fa[i] : fa[i] = find(fa[i]);
}
int merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    fa[a] = b;
    times++;
  }
}
int main() {
  for (int i = 0; i < N; ++i) {
    fa[i] = i;
  }
  cin >> pictureNum;
  for (int i = 0; i < pictureNum; ++i) {
    int peopleNum;
    cin >> peopleNum;
    int flag = 1;
    int first;
    for (int j = 0; j < peopleNum; ++j) {
      int x;
      cin >> x;
      if (x > m) {//筛选出最大编号，即总人数
        m = x;
      }
      if (flag) {
        //此照片的第一个基友，不做操作，默认即可
        first = x;
        flag = 0;
      } else {
        //不是第一个基友，将其加入第一个基友所在的群聊即可
        merge(x, first);
      }
    }
  }
  //基友群的个数和所有人数
  int groupNum = m - times;
  cout << groupNum << ' ' << m << endl;

  int count;
  cin >> count;
  for (int i = 0; i < count; ++i) {
    int a, b;
    cin >> a >> b;
    if (find(a) == find(b)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}





