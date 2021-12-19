#include <bits/stdc++.h>
using namespace std;
vector<int> res;
int main() {
  int n;
  cin >> n;
  //确定n的二进制位个数为num
  int temp = n;
  int num = 0;
  while (temp > 0) {
    temp = temp >> 1;
    num++;
  }
  cout << ((~n) & ((1 << num) - 1));
}

