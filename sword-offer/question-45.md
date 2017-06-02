## 面试题45 圆圈中最后剩下的数字

<!-- TOC -->

- [面试题45 圆圈中最后剩下的数字](#面试题45-圆圈中最后剩下的数字)
- [题目（约瑟夫环）](#题目约瑟夫环)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2](#思路2)
    - [实现2](#实现2)

<!-- /TOC -->

## 题目（约瑟夫环）

0,1,...,n-1这n个数字排成一个圆，从数字0开始，每次从圆圈里删除第m个数字，然后继续从m+1这个数字为1开始计数，再次删除第m个数字，直到只剩最后一个数字。例如`0,1,2,3,4`这5个数字组成一个圆圈，每次删除第3个数字，则删除的前四个数字依次是`2,0,4,1`，所以最后剩下3。[牛客网地址][url]

### 思路1
1. 使用链表来模拟圆圈，每次删除第m个节点
2. 使用STL中的list模拟，每次到end()节点时，转到begin()节点
3. 时间复杂度O(mn)，空间复杂度O(n)

### 实现1

```cpp
class Solution
{
  public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;
        list<int> numbers;
        for (int i = 0; i < n; ++i)
            numbers.push_back(i);
        auto current = numbers.begin();
        while (numbers.size() > 1)
        {
            for (int i = 1; i < m; ++i)
            {
                ++current;
                if (current == numbers.end())
                    current = numbers.begin();
            }
            auto next = ++current;
            if (next == numbers.end())
                next = numbers.begin();
            --current;
            numbers.erase(current);
            current = next;
        }
        return *current;
    }
};
``` 
### 思路2
1. 参考《剑指Offer》第230-232页，分析得到递推公式
2. f(n,m)表示最初的序列，删除第m个数字之后剩余的数字，则有`f(n,m)=(f(n-1,m)+m)%n  n>1`与`f(n,m)=0 n=1`


### 实现2

```cpp
class Solution
{
  public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;
        int last = 0;
        for (int i = 2; i <= n; ++i)
            last = (last + m) % i;
        return last;
    }
};
``` 

[url]:https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking