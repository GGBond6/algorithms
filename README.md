### exercise6

#### 集合相似度

https://blog.csdn.net/You_are_my_dream/article/details/65631162

### question

1. 同样都是并查集问题，社交集群与冰岛家谱有什么区别与联系？

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



















