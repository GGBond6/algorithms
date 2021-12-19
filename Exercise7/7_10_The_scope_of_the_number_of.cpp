#include <bits/stdc++.h>
using namespace std;
int n;
//寻找一个数的二分查找
int binarySearch(int arr[], int target) {
  int left = 0, right = n - 1;
  while (left <= right) {//数组不为空
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {//target在mid右部
      left = mid + 1;
    } else {//target在mid左部
      right = mid - 1;
    }
  }
  return -1;
}
//寻找左侧边界的二分查找
int leftBound(int arr[], int target) {
  int left = 0, right = n - 1;
  while (left <= right) {//数组不为空
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      right = mid - 1;//因为要找左边界，那么缩小右侧边界，不断向左收缩
    } else if (arr[mid] < target) {//target在mid右部
      left = mid + 1;
    } else {//target在mid左部
      right = mid - 1;
    }
  }
  //检查越界
  if (left >= n || arr[left] != target)
    return -1;
  return left;
}
//寻找右侧边界的二分查找：在
int rightBound(int arr[], int target) {
  int left = 0, right = n - 1;
  while (left <= right) {//数组不为空
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      left = mid + 1;
    } else if (arr[mid] < target) {//target在mid右部
      left = mid + 1;
    } else {//target在mid左部
      right = mid - 1;
    }
  }
  //越界检查
  if (arr[right] != target || right < 0) {
    return -1;
  }
  return right;//left=right+1
}

int main() {
  int q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> arr[i];
  }
  for (int i = 0; i < q; ++i) {
    int target;
    cin >> target;
    int x = leftBound(arr, target);
    int y = rightBound(arr, target);
    cout << x << ' ' << y << endl;
  }
}

