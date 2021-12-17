#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> arr1;
int n;
//插入排序
vector<int> insertSort() {
  vector<int> temp = arr;
  bool flag = false;
  //从第2个元素开始插入排序
  for (int i = 1; i < n; ++i) {
    //对temp[i]进行排序，与其前面的元素比较
    for (int j = i; j > 0; --j) {
      //待排序元素小于前面的元素，交换
      if (temp[j] < temp[j - 1]) {
        swap(temp[j], temp[j - 1]);
      } else {
        //待排序元素处于正确位置，跳出，进行下一个元素排序
        break;
      }
    }

    if (flag) {
      cout << "Insertion Sort" << endl;
      for (int i = 0; i < n; ++i) {
        if (i != n - 1) {
          cout << temp[i] << ' ';
        } else {
          cout << temp[i] << endl;
        }
      }
      return temp;
    }
    //插入排序过程中产生的序列与待比较序列相同，那么就是插入排序
    if (temp == arr1) {
      //是插入排序，我们还需要知道它的下一步排序
      flag = true;
    }
  }
  return temp;
}
//下沉
void shiftDown(vector<int> &temp, int k, int index) {//index是待排序中的最后一个元素的索引
  //存在孩子节点则下沉，不存在就不能下沉
  if ((2 * k + 1) <= index) {//左孩子下标不超过最大下标即可
    //bigger默认值为左节点下标，若存在右节点并且比左节点大，那么就将bigger赋值为右节点下标
    int bigger = 2 * k + 1;
    if (2 * k + 2 <= index && temp[2 * k + 1] < temp[2 * k + 2]) {
      bigger = 2 * k + 2;
    }
    //将temp[k]与bigger比较，如果小于它就下沉，否则就是到达了合适位置
    if (temp[k] < temp[bigger]) {
      swap(temp[k], temp[bigger]);
      k = bigger;
      shiftDown(temp, k, index);
    } else return;
  } else return;
}

//堆排序：找出最大值并放在数组的最后
vector<int> heapSort() {
  vector<int> temp = arr;
  int index = temp.size() - 1;
  //从最后一个非叶子节点开始进行shiftDown操作，直到根节点
  //把它当做满二叉树来看，求最后一个非叶子节点就是求最后一个元素(temp.size() - 1)的父节点，因为下标从0开始，那么其父节点为((temp.size() - 1)-1)/2
  for (int i = index - 1 / 2; i >= 0; --i) {
    shiftDown(temp, i, index);
  }
  //此时根元素存储的是最大值，将其与末尾元素交换；新的根再进行shiftDown操作
  bool flag = false;
  while (index > 0) {
    if (flag) {
      cout << "Heap Sort" << endl;
      for (int i = 0; i < n; ++i) {
        if (i != n - 1) {
          cout << temp[i] << ' ';
        } else {
          cout << temp[i] << endl;
        }
      }
      return temp;
    }
    //如果和arr1相等，直接返回
    if (temp == arr1) {
      flag = true;
    }
    //遍历一遍二叉堆之后可以得到最大值；为temp[0]，将其与最后一个节点交换；交换完成之后，下一次排序不再加入最后一个元素
    swap(temp[0], temp[index]);
    index--;
    //下沉
    shiftDown(temp, 0, index);
  }
  return temp;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr1.push_back(x);
  }
  /**
   * 插入排序与堆排序的区别
   * 插入排序从第一个元素开始向后有序，未排序部分与原序列不同。[有序,无序]
   * 堆排序从最后一个元素开始向前有序，未排序部分与原序列相同。[无序,有序]
   *
   * 检查中间序列的无序部分，若与原序列相同，则为插入排序；若不同则为堆排序
   *
   */
  insertSort();
  heapSort();
}


