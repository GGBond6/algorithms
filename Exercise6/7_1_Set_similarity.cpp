#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
  //集合数量
  int listNum;
  cin >> listNum;
  //动态数组；存放集合
  vector<set<int>> lists;
  vector<double> results;
  for (int i = 0; i < listNum; i++) {
    //集合元素数量
    int count;
    cin >> count;
    set<int> set;

    //将当前集合元素存入set集合中，自动去重
    for (int j = 0; j < count; j++) {
      int k;
      cin >> k;
      set.insert(k);
    }
    lists.push_back(set);
    set.clear();
  }
  //此时lists中存放着所有集合，现在需要求集合相似度
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    int a;
    int b;
    cin >> a;
    cin >> b;
    a--;
    b--;
    //求seta与setb的相似度
    set<int> seta = lists.at(a);
    set<int> setb = lists.at(b);
    //总数量
    int total = seta.size() + setb.size();
    set<int>::iterator it;
    //相同元素个数
    int count = 0;
    for (it = seta.begin(); it != seta.end(); it++) {
      if (setb.find(*it) != setb.end()) {
        count++;
      }
    }
    total -= count;
    float result = (float) count * 100 / (float) total;
    results.push_back(result);
  }
  for (double result : results) {
    printf("%.2f%%\n", result);
  }
  return 0;
}
