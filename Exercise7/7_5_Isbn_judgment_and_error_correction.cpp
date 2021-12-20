#include <bits/stdc++.h>
using namespace std;
char code;
int main() {
  int n;
  cin >> n;
  for (int j = 0; j < n; ++j) {
    string s;
    cin >> s;
    vector<int> isbn;
    for (char c: s) {
      if (c != '-') {
        isbn.push_back(atoi(&c));
      }
    }
    int sum = 0;
    for (int i = 10; i >= 2; i--) {
      sum += isbn[10 - i] * i;
    }
    int r = sum % 11;
    if (r == 0)
      code = '0';
    else {
      int d = 11 - r;
      if (d == 10)
        code = 'X';
      else code = to_string(d)[0];
    }
    if (code == s[s.length() - 1])
      cout << "OK" << endl;
    else {
      s[s.length() - 1] = code;
      cout << s << endl;
    }
  }
}

