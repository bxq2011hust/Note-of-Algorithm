## 面试题44 扑克牌顺子

<!-- TOC -->

- [面试题44 扑克牌顺子](#面试题44-扑克牌顺子)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

大/小王可以看成任何数字,并且A看作1,J为11,Q为12,K为13，方便起见大小王为0，求问随机抽5张牌，这五张牌是不是顺子。[牛客网地址][url]

### 思路
1. 对数组排序，统计数组中0的次数
2. 统计排序后数字之间的差-1，如果0出现的次数不少于差-1，则是顺子

### 实现

```cpp
class Solution
{
  public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.empty() || numbers.size() != 5)
            return false;
        sort(numbers.begin(), numbers.end());
        int numberOfZero = 0;
        int numberOfGap = 0;
        for (auto i : numbers)
            if (i == 0)
                ++numberOfZero;
        int small = numberOfZero;
        int big = small + 1;
        while (big < numbers.size())
        {
            if (numbers[small] == numbers[big])
                return false;
            numberOfGap += numbers[big++] - numbers[small++] - 1;
        }
        return (numberOfZero >= numberOfGap);
    }
};
``` 


[url]:https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking