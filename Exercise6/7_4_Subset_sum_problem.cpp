#include <bits/stdc++.h>
using namespace std;
int n;
int target;
vector<int> nums;
vector<int> track;
vector<vector<int>> res;

/** 回溯方法
 * 路径：记录在track中
   选择列表：记录在nums中
   结束条件：路径中全部值之和等于target
 */
void backtrack(vector<int> track, vector<int> nums) {
  //看路径的和是否达到了目标
  int sum = 0;
  for (int x: track) {
    sum += x;
  }
  //递归出口
  if (sum == target) {
    //先判断此路径在res中是否存在，若存在则不需要添加
    for (auto x: res) {
      //如果存在元素与track相等，那么直接返回
      vector<int> temp1 = x;
      vector<int> temp2 = track;
      sort(temp1.begin(),temp1.end());
      sort(temp2.begin(),temp2.end());
      if (temp1 == temp2) {
        return;
      }
    }
    res.push_back(track);
    return;
  } else if (sum > target) {
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    //排除不合法选择

    //选择
    int temp = nums[i];
    track.push_back(temp);//加入路径
    nums.erase(nums.begin() + i);//从选择列表中移除

    backtrack(track, nums);
    //撤销
    track.pop_back();
    nums.insert(nums.begin() + i, temp);
  }
}

int main() {
  cin >> n;
  cin >> target;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  backtrack(track, nums);
  for (auto x: res) {
    for (auto y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }
}