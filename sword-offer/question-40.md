## 面试题40 数组中只出现一次的数字

<!-- TOC -->

- [面试题40 数组中只出现一次的数字](#面试题40-数组中只出现一次的数字)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)
    - [思路2](#思路2)

<!-- /TOC -->

## 题目1

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。[牛客网地址][url]

### 思路
1. 从头到尾异或每个数字，则最终结果是两个出现一次数字的异或，且这两个数字肯定不一样， 所以结果中至少有一位是1
2. 找到第一个为1的位置，记为第n位，则以第n位是不是1为标准，可以将原数组分为两个子数组，第一个子数组中第n位都为1，第二个子数组中第n位都为0。由于相同数字第n位相同，所以出现两次的数字一定在同一个子数组，所以两个子数组中各自有一个只出现一次的数字。只有要对子数组异或即可得到只出现一次的数字。

### 实现

```cpp
class Solution
{
  public:
    unsigned int FindFirstBitIs1(int num)
    {
        int index = 0;
        while (((num & 1) == 0) && (index < 8 * sizeof(int)))
        {
            num = num >> 1;
            ++index;
        }
        return index;
    }
    // index所指的位是不是1
    bool isBit1(int num, unsigned int index)
    {
        num = num >> index;
        return (num & 1);
    }
    
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.empty() || num1 == NULL || num2 == NULL)
            return;
        int resOR = 0;
        for (auto i : data)
            resOR ^= i;
        // 找到第一个为1的位
        unsigned int indexOf1 = FindFirstBitIs1(resOR);
        *num1 = *num2 = 0;
        // 两个子数组分别异或
        for (auto i : data)
        {
            if (isBit1(i, indexOf1))
                *num1 ^= i;
            else
                *num2 ^= i;
        }
    }
};
``` 

### 思路2
1. 使用hash表存储每个数字出现的次数，如果大于1，则删除该数字，否则加入
2. 因为出了两个数字，其他数字只出现两次，所以最终只剩出现1次的数字

```cpp

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.empty() || num1 == NULL || num2 == NULL)
            return;
        unordered_map<int, int> counts;
        for (auto i : data)
        {
            if (counts[i] > 0)
                counts.erase(i);
            else
                ++counts[i];
        }
        auto it = counts.begin();
        *num1 = it->first;
        ++it;
        *num2 = it->first;
    }
};
``` 


[url]:https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking