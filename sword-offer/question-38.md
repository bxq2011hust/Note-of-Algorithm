## 面试题38 数字在排序数组中出现的次数

<!-- TOC -->

- [面试题38 数字在排序数组中出现的次数](#面试题38-数字在排序数组中出现的次数)
- [[题目][url]](#题目url)
    - [思路1](#思路1)
    - [思路2](#思路2)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]

统计一个数字在排序数组中出现的次数。

### 思路1
1. 二分查找找到数字O(logn)
2. 分别在该数字前后找到头和尾
3. 当数组中全部是一个数，所以时间复杂度是O(n)

### 思路2
1. 二分查找找到数字O(logn)
2. 同样适用二分查找来查找数字数第一次出现和最后一次出现的下标
3. 时间复杂度O(logn)

### 实现

```cpp
class Solution
{
  public:
    int binarySearchFirst(vector<int> &data, int k, int start, int end)
    {
        if (start >= end)
            return -1;
        int mid = (start + end) / 2;
        if (k == data[mid])
        {
            if (mid > 0 && data[mid - 1] != k || mid == 0)
                return mid;
            else
                end = mid;
        }
        else if (k > data[mid])
            start = mid + 1;
        else
            end = mid;
        return binarySearchFirst(data, k, start, end);
    }
    int binarySearchLast(vector<int> &data, int k, int start, int end)
    {
        if (start >= end)
            return -1;
        int mid = (start + end) / 2;
        if (k == data[mid])
        {
            if (mid < data.size() - 1 && data[mid + 1] != k || mid == data.size() - 1)
                return mid;
            else
                start = mid + 1;
        }
        else if (k > data[mid])
            start = mid + 1;
        else
            end = mid;
        return binarySearchLast(data, k, start, end);
    }
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.empty())
            return 0;
        //int first = binarySearchFirst(data, k, 0, data.size());
        //if (first < 0)
            //return 0;
        //int last = binarySearchLast(data, k, 0, data.size());
        //return last - first + 1;
        
        // 简洁写法
        auto first=find(data.begin(),data.end(),k);
        if(first==data.end()) return 0;
        auto last=find(data.rbegin(),data.rend(),k);
        return last.base() - first;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
