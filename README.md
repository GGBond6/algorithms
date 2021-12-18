### exercise1

#### N皇后问题

- 因为要进行当前位置的有效性判断，所以需要知道当前决策的层数，我使用`track.size()+1`表示

使用了一个标志二维数组flag，记录某行某列是否被放置皇后，进而在后面的选择时，可以依据flag进行有效性的判断

```c++
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
```

因为选择列表是固定的，所以trackback函数参数只有路径，没有选择列表（隐式的存在）

```c++
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
```



### exercise6

#### 集合相似度

https://blog.csdn.net/You_are_my_dream/article/details/65631162

#### 半数集

半数集的产生过程可以看做是一个多叉树结构

![img](https://img-blog.csdnimg.cn/2021050609045397.png)

那么我们使用深度优先搜索将树结构遍历一遍，即可得到半数集中元素的个数

```c++
//求n的半数集个数
int dfs(int n) {
  //递归出口：半数集只有自身
  if (n <= 1) {
    return 1;
  }
  int res = 1;//自己本身肯定在半数集中，那么res初值为1
  for (int i = 1; i <= n / 2; ++i) {//可以将半数集看成一个多叉树，这里是遍历多叉树
    res += dfs(i);
  }
  return res;
}
```

#### 子集和问题

> 典型的回溯问题

给n个不同的正整数集合w和一个正数W，要求找出w的子集，该子集中的所有元素之和为W

- 在将路径加入结果集时，需要判断是否和已有结果集元素重复（或在做选择时排除不合法的选择）
- 因为这是多叉树，那么递归结构需要for循环，来遍历选择列表中的每一个选项；那么`i<可选列表.size()`，如果是总路径，会发生段错误

#### 插入排序还是堆排序

##### 方法1（暴力解法）

分别写出插入排序与堆排序，每排一个元素就要与中间序列比较一次，如果相同，那么再排一个元素，然后输出即可

##### 方法2（分析规律）

分析插入排序与堆排序的区别：

- 插入排序：从前往后有序；当某个元素小于前面的元素，那么它就是下一个待排序元素（依次与前面的元素比较，插入到合适位置）；未排序部分与原序列相同
- 堆排序：从后往前有序；当某个元素小于第一个元素，那么表示它还未进行置换，就为下一个待排序元素（将其与首元素交换，然后进行下沉）；未排序部分与原序列不同

步骤：

1. 检查中间序列的无序部分，若与原序列相同，那么为插入排序，否则为堆排序
2. 如果为插入排序，找到待排序元素，即arr1[j]<arr1[j-1]的那个j点
3. 如果为堆排序，找到比arr1[0]小的点，即为下一步要进行置换下沉的点

我们先假设这是插入排序，找到arr1[j]<arr1[j-1]的j点，然后比较arr[j,n]与arr1[j,n]是否相同，若相同则为插入排序，否则为堆排序；





### question

1. 同样都是并查集问题，社交集群与冰岛家谱有什么区别与联系？

### exercise7

#### 愿天下有情人都是失散多年的兄妹

- 使用vector数组来存储当前用户（下标）的父亲节点与母亲节点
- 又分别有sex字符数组和vis整型数组
- 使用dfs进行遍历







## 知识点

### tips

#### 万能头文件

```
#include <bits/stdc++.h>
```

#### 科学计数法

```c++
double a = 1e3; // a= 1000
double b = 2.3e2;  //b = 230
double c = -1.3e2; //c = -130
```

#### 赋值表达式的返回值

```c++
int x;
int main() {
  cout << (x = 1) << endl;
  cout << &(x = 1) << endl;
  cout << &x << endl;
}
```

输出依次是：

```
1
0x406034
0x406034
```

可见赋值表达式返回的是**表达式左值的引用**

### set集合取交集并集差集

说明：在C++编程中，使用set集合时，常用到取并集，交集，差集功能。在算法库中，提供了三个函数可以快速进行这三个操作。

**需要包含头文件：**

```cpp
#include <algorithm>
```

**基本介绍**

set里面有`set_intersection`（取集合交集）、`set_union`（取集合并集）、`set_difference`（取集合差集）、`set_symmetric_difference`（取集合对称差集）等函数。
其中，关于函数的五个参数问题做一下小结：

特性：这几个函数的前四个参数一样，只有第五个参数有多重版本。

EX1：set_union(A.begin(),A.end(),B.begin(),B.end(),inserter( C1 , C1.begin() ) );前四个参数依次是第一的集合的头尾，第二个集合的头尾。第五个参数的意思是将集合A、B取合集后的结果存入集合C中。

EX2：set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator(cout," “));这里的第五个参数的意思是将A、B取合集后的结果直接输出，（cout," "）双引号里面是输出你想用来间隔集合元素的符号或是空格。

### 并查集

解决不相交集合的合并问题

**模板**

fa[N]数组：下标表示要进行合并操作的目标元素，拥有的值表示当前元素的祖先元素（也是下标）

元素x的祖先是fa[x]，其祖先fa[x]的祖先是其本身，即fa[fa[x]]

并就是对fa数组中的不同集合进行合并，只需将一个集合的祖先指向另一个集合的祖先即可

```c++
//查：找到当前元素的祖先
int find(int i) {
  //递归出口，当到达祖先位置就返回祖先；否则不断往上查找祖先
  return fa[i] == i ? i : fa[i] = find(fa[i]);
}
//并：将a所在集合合并到b所在的集合
void join(int a, int b) {
  a = find(a);
  b = find(b);
  fa[a] = b;//将a的祖先指向b的祖先
}
```

### 回溯

[https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E8%AF%A6%E8%A7%A3%E4%BF%AE%E8%AE%A2%E7%89%88.md](https://github.com/labuladong/fucking-algorithm/blob/master/算法思维系列/回溯算法详解修订版.md)

**解决一个回溯问题，实际上就是一个决策树的遍历过程**。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

回溯就是在遍历下个节点前，做出选择的操作，遍历之后，再撤销选择

```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

核心代码如下：

- 做选择：从选择列表移除，加入路径
- 撤销选择：从路径移除，加入选择列表

```python
for 选择 in 选择列表:
    # 做选择
    将该选择从选择列表移除
    路径.add(选择)
    backtrack(路径, 选择列表)
    # 撤销选择
    路径.remove(选择)
    将该选择再加入选择列表
```

#### 例题

- 对于排除不合法的选择有两个时机：一是选择前，二是结束条件那里加入结果集时

1. [子集和问题](#子集和问题)
2. [N皇后问题](#N皇后问题)

先写出回溯三要素：

1. 路径

   一般为数组或字符串，看题目要求

2. 选择列表

   如果选择列表在决策树的每一层都是固定的，那么可以不显示的声明出来，backtrack函数参数中只写路径即可

   - 如果选择列表不固定（例题1）

     backtrack函数是

     ```c++
     void backtrack(vector<int> track, vector<int> nums){}
     ```

     for循环是

     ```c++
     for (int i = 0; i < nums.size(); ++i) {}
     ```

     并且每次选择都要移除元素，撤销恢复元素

   - 选择列表固定（例题2）

     backtrack函数是

     ```c++
     void backtrack(string &track){}
     ```

     for循环是

     ```c++
     //N为常数
     for (int i = 1; i <= N; i++){}
     ```

3. 结束条件



### 递归

函数自己调用自己，把当前问题转化为<strong style="color:#92d050;">性质相同但是规模更小</strong>的子问题

有两个特征：

- 递归出口
- 自我调用

自我调用是在解决子问题，而递归出口定义了最简子问题的答案

比如上面的并查集模板中的find函数：递归出口是定义了最简子问题的答案，自我调用时规模更小但是性质相同

**<strong style="color:#ff0000;">明白一个函数的作用并相信它能完成这个任务，千万不要试图跳进细节</strong>。**千万不要跳进这个函数里面企图探究更多细节，否则就会陷入无穷的细节无法自拔，人脑能压几个栈啊

- 遍历二叉树

  ```
  void traverse(TreeNode* root) {
      if (root == nullptr) return;
      traverse(root->left);
      traverse(root->right);
  }
  ```

- 遍历多叉树

  使用for循环遍历多叉树，可以参考[半数集](#半数集)

  ```
  void traverse(TreeNode* root) {
      if (root == nullptr) return;
      for (child : root->children)
          traverse(child);
  }
  ```

### dfs与bfs

深度优先搜索与广度优先搜索

- bfs显式的使用栈，dfs隐式的使用栈（递归）

  回溯是dfs的一种

- bfs

  1. 将根节点入队
  2. 将队首节点的全部子节点入队，然后队首出队；如果没有子节点，那么队首直接出队；
  3. 重复步骤2，直到找到目标元素或队列为空（没找到目标元素）

- 



## devc++编译

工具-编译选项-代码生成/优化-连接器-产生调试信息（yes）

















