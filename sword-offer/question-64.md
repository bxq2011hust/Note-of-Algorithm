## 面试题64 数据流中的中位数

<!-- TOC -->

- [面试题64 数据流中的中位数](#面试题64-数据流中的中位数)
- [题目](#题目)
    - [思路](#思路)
    - [实现1](#实现1)
    - [实现2](#实现2)

<!-- /TOC -->

## 题目

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。[牛客网地址][url]

### 思路
1. 根据中位数，将数据分为两部分，左边的部分中位数是最大值，右边的部分，中位数是最小值
2. 使用两个堆，左边部分使用最大堆，右边部分是用最小堆
3. 保证两个堆的元素数目只差不超1，如果此时有偶数个元素，则新元素插入最小堆，否则插入最大堆；由于偶数是插入最小堆的元素可能比最大堆的最大值小，此时先将新元素插入最大堆，然后将最大堆的根插入最小堆;类似的处理奇数时，插入最大堆的元素可能比最小堆的最小值大的情况
4. 插入元素的时间复杂度是O(longn)，查找是O(1)
5. [make_heap, push_heap,pop_heap,sort_heap的使用][url2]
### 实现1

```cpp
class Solution
{
  public:
    void Insert(int num)
    {
        if (((max.size() + min.size()) & 1) == 0)
        {
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end());

                num = max[0];
                pop_heap(max.begin(), max.end());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else
        {
            if (min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());

                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end());
        }
    }

    double GetMedian()
    {
        double res = 0;
        int size = min.size() + max.size();
        if (size == 0)
            throw logic_error("No numbers are avaliable");

        if ((size & 1) == 1)
            res = min[0];
        else
            res = (max[0] + min[0]) / 2.0;
        return res;
    }

  private:
    vector<int> min;
    vector<int> max;
};
```

### 实现2

使用multizset实现

```cpp
class Solution
{
  public:
    void Insert(int num)
    {
        numbers.insert(num);
    }

    double GetMedian()
    {
        double res = 0;
        auto b = numbers.begin();
        int len = 0;
        if ((numbers.size() & 1) == 1)
        {
            len = numbers.size() / 2;
            for (int i = 0; i < len; ++i)
                ++b;
            res = *b;
        }
        else
        {
            len = numbers.size() / 2 - 1;
            for (int i = 0; i < len; ++i)
                ++b;
            res = *b + *++b;
            res /= 2;
        }
        return res;
    }

  private:
    multiset<int> numbers;
};
``` 
[url]:https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
[url2]:http://www.cnblogs.com/coderyoyo/archive/2011/01/21/stl_heap.html "make_heap, push_heap,pop_heap,sort_heap"