#include <bits/stdc++.h>
using namespace std;
vector<int> res;
//素数：除了1和本身，没有其他因子
void f(int x) {
  int mid = int(sqrt(x)) + 1;
  int flag = 0;
  for (int i = 2; i < mid; ++i) {
    if (x % i == 0) {//找到一个因数，进行分解之后，跳出循环
      res.push_back(i);
      f(x / i);
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    res.push_back(x);
  }
}
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    res.clear();
    int x;
    cin >> x;
    f(x);
    for (int j = 0; j < res.size(); j++) {
      if (j != res.size() - 1) {
        cout << res[j] << '*';
      } else {
        cout << res[j] << endl;
      }
    }
  }
}