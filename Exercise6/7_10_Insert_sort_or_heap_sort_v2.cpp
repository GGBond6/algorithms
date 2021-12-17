#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr, arr1;

void insertSortOneStep(int nextIndex) {
  for (int i = nextIndex; i >= 1; --i) {
    if (arr1[i] < arr1[i - 1]) {
      swap(arr1[i], arr1[i - 1]);
    } else {
      break;
    }
  }
}
//下沉操作
void shiftDown(int temp, int endIndex) {
  if (temp * 2 + 1 <= endIndex) {//存在左孩子
    int bigger = temp * 2 + 1;
    if (temp * 2 + 2 <= endIndex && arr1[temp * 2 + 2] > arr1[bigger]) {
      bigger = temp * 2 + 2;
    }
    if (arr1[temp] < arr1[bigger]) {
      swap(arr1[temp], arr1[bigger]);
      temp = bigger;
      shiftDown(temp, endIndex);
    }
  }
}
void heapSortOneStep(int nextIndex) {
  //将待排序元素与首元素交换
  swap(arr1[nextIndex], arr1[0]);
  //对交换后的首元素进行下沉操作；未排序元素的末尾下标为nextIndex-1
  int endIndex = nextIndex - 1;
  shiftDown(0, endIndex);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr1.push_back(x);
  }
  //我们先进行插入排序的检验，若通过则为插入排序，否则为堆排序
  int nextIndex = 0;//下一个要排序元素的下标
  //先假设这是插入排序，那么我们找到后一个比前一个小的元素，后一个即为nextIndex
  for (int i = 1; i < n; ++i) {
    if (arr1[i] < arr1[i - 1]) {
      nextIndex = i;
      break;
    }
  }
  //检验假设的正确性
  bool flag = true;
  for (int i = nextIndex; i < n; i++) {
    if (arr[i] != arr1[i]) {
      flag = false;//假设不成立，应该是堆排序
      break;
    }
  }
  if (flag) {
    cout << "Insertion Sort" << endl;
    insertSortOneStep(nextIndex);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (flag) {
        cout << arr1[i];
        flag = false;
      } else cout << ' ' << arr1[i];
    }
  } else {
    cout << "Heap Sort" << endl;
    //找出堆排序中下一个应该置换下沉的元素下标
    for (int i = n - 1; i >= 0; i--) {
      if (arr1[i] < arr1[0]) {
        nextIndex = i;
        break;
      }
    }
    heapSortOneStep(nextIndex);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (flag) {
        cout << arr1[i];
        flag = false;
      } else cout << ' ' << arr1[i];
    }
  }
  cout << endl;
}