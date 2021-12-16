#include <bits/stdc++.h>
using namespace std;
string track;//路径
//此题的选择列表是固定的1-8，因此不需要显示的写出来
vector<string> res;//结果集
const int N = 8;//皇后的个数
int flag[N + 1][N + 1];//标志数组，用来进行位置有效性的判断。默认为0，即都未存放皇后

bool isvalid(int row, int column) {
  // 遍历全部行，检查当前列是否有冲突
  for (int i = 1; i < row; i++) {//针对当前列，对row之前的行进行遍历
    if (flag[i][column] == 1) {//如果已经选择，不合法
      return false;
    }
  }
  //检查左上是否有冲突
  for (int i = row - 1, j = column - 1; i >= 1 && j >= 1; i--, j--) {
    if (flag[i][j] == 1) {
      return false;
    }
  }
  //检查右上是否有冲突
  for (int i = row - 1, j = column + 1; i >= 1 && j <= N; i--, j++) {
    if (flag[i][j] == 1) {
      return false;
    }
  }
  //无冲突
  return true;
}

void backtrack(string &track) {
  //结束条件：全部皇后都放置完成
  if (track.size() == N) {
    res.push_back(track);
    return;
  }
  //track.size()<8，皇后未放置完成
  int row = track.size() + 1;//对第(track.size+1)行进行选择
  for (int i = 1; i <= N; i++) {
    int column = i;
    //如果当前选择不合法，那么就跳过当次循环
    if (!isvalid(row, column)) {
      continue;
    };
    //做选择
    track.append(to_string(i));
    flag[row][column] = 1;//将此行列设置为1，即皇后放置的位置
    backtrack(track);
    //撤销选择
    track.pop_back();
    flag[row][column] = 0;
  }
}

int main() {
  res.push_back("");//事先放入一个，让有效数据从下标1开始，对应输入的顺序
  backtrack(track);
  int count;
  cin >> count;
  for (int i = 0; i < count; ++i) {
    int x;
    cin >> x;
    cout << res[x] << endl;
  }
}