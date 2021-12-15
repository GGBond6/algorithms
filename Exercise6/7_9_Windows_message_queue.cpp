#include <bits/stdc++.h>
using namespace std;
map<int, string> mp;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string instruct;
    cin >> instruct;
    if (instruct == "PUT") {
      int priority;
      string name;
      cin >> name;
      cin >> priority;
      mp[priority] = name;//map默认按照key升序排列
    } else {//instruct==GET
      if (mp.size() != 0) {
        cout << mp.begin()->second << endl;
        mp.erase(mp.begin());
      } else {
        cout << "EMPTY QUEUE!" << endl;
      }
    }
  }
}

