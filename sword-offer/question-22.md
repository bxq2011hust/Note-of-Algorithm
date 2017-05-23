## 面试题22 栈的压入、弹出序列

<!-- TOC -->

- [面试题22 栈的压入、弹出序列](#面试题22-栈的压入弹出序列)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。

### 思路
1. 按入栈序列入栈，如果栈不为空且栈顶元素等于出栈序列，则出栈
2. 完成循环之后判断栈是否为空，如果为空则出栈序列正确


### 实现

```cpp

class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() != popV.size())
            return false;
        if(pushV.empty()) return false;
        stack<int> s;
        for (size_t i = 0, j = 0; i < pushV.size(); ++i)
        {
            s.push(pushV[i]);
            while (!s.empty() && s.top() == popV[j])
            {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};
``` 

[url]:https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking