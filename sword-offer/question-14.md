## 面试题14 调整数组顺序使奇数位于偶数前面

<!-- TOC -->

- [面试题14 调整数组顺序使奇数位于偶数前面](#面试题14-调整数组顺序使奇数位于偶数前面)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)
- [[题目2][url2.1]](#题目2url21)
    - [思路](#思路-1)
    - [实现](#实现-1)

<!-- /TOC -->

## 题目1
输入一个整数数组，实现一个函数调整数组中数字顺序，使得所有的奇数位于前半部分，偶数位于后半部分

### 思路
1. 头尾两个指针，头指针前进直到第一个偶数，尾指针反向前进直到第一个奇数
2. 如果头指针小于尾指针，交换头尾指针指向的值
3. 当头指针不小于尾指针时退出
4. 考虑可扩展性，将判断改为函数指针

### 实现
```cpp
void Reorder(vector<int> &arr, bool (*pFun)(int))
{
    if (arr.empty())
        return;
    int head = 0, tail = arr.size() - 1;
    while (head < tail)
    {
        while (head < tail && !pFun(arr[head]))
            ++head;
        while (head < tail && pFun(arr[tail]))
            --tail;
        if (head < tail)
        {
            swap(arr[head], arr[tail]);
        }
    }
}

bool isEven(int n)
{
    return (n & 1) == 0;
}
``` 

## [题目2][url2.1]
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

### 思路
1. 空间换时间，`vector<int> res`先遍历将奇数加入res，然后遍历将偶数加入res
2. 将res赋值给原数组

### 实现
```cpp
void reOrderArray(vector<int> &array) {
        if(array.empty()) return;
        vector<int> res;
        for(size_t i=0;i<array.size();++i)
        {
            if(array[i]&1) res.push_back(array[i]);
        }
        for(size_t i=0;i<array.size();++i)
        {
            if((array[i]&1)==0) res.push_back(array[i]);
        }
        array=res;
    }
``` 
[url2.1]:https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking