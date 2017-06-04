## 面试题65 滑动窗口的最大值

<!-- TOC -->

- [面试题65 滑动窗口的最大值](#面试题65-滑动窗口的最大值)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。[牛客网地址][url]

### 思路
1. 使用一个队列，存储滑动窗口可能的最大值的索引，遍历数组，当(i-size)>=index.front()表明这个索引已经不在滑动窗口的范围内
2. 例如{2,3,4,2,6,2,5,1}

|步骤|输入数字|滑动窗口|队列中的下标|最大值|
|:---|:---|:---|:---|:---|
|1|2|2|0(2)|N/A|
|2|3|2,3|1(3)|N/A|
|3|4|2,3,4|2(4)|4|
|4|2|3,4,2|2(4),3(2)|4|
|5|6|4,2,6|4(6)|6|
|6|2|2,6,2|4(6),5(2)|6|
|7|5|6,2,5|4(6),6(5)|6|
|8|1|2,5,1|6(5),7(1)|5|

### 实现

```cpp
class Solution
{
  public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> max;
        if (num.size() < size || size < 1)
            return max;
        deque<int> index;
        for (unsigned int i = 0; i < size; ++i)
        {
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for (unsigned int i = size; i < num.size(); ++i)
        {
            max.push_back(num[index.front()]);
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if (!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();
            index.push_back(i);
        }
        max.push_back(num[index.front()]);
        return max;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
