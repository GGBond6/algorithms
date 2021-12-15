#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int temp;
  cin >> temp;//先读取初值
  int blocks = 1;//初值就作为一个段，所以段数从1开始
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    if (x != temp) {
      temp = x;
      blocks++;
    }
  }
  cout << blocks;
}

