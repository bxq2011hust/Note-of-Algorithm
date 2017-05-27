## 面试题33 把数组排成最小的数

<!-- TOC -->

- [面试题33 把数组排成最小的数](#面试题33-把数组排成最小的数)
- [[题目][url]](#题目url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

### 思路
1. 参考《剑指Offer》第177-180页

### 实现

```cpp
class Solution
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        string result;
        if (numbers.empty())
            return result;
        vector<string> numString;
        for (auto i : numbers)
            numString.push_back(to_string(i));
        // lambda 定义比较函数
        auto f = [](const string &s1, const string &s2) { return (s1 + s2) < (s2 + s1); };
        //排序
        sort(numString.begin(), numString.end(), f);
        for (auto s : numString)
            result += s;
        return result;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
