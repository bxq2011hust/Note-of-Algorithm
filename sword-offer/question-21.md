## 面试题21 包含min函数的栈

<!-- TOC -->

- [面试题21 包含min函数的栈](#面试题21-包含min函数的栈)
- [[题目1][url1.1]](#题目1url11)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url1.1]
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

### 思路
1. 使用两个栈，一个保存所有元素，另一个`vMin`保存当前的最小值
2. 如果新入栈的值小于等于当前最小值，则入栈`vMin`


### 实现

```cpp
class Solution
{
  public:
    void push(int value)
    {
        v.push(value);
        if (vMin.empty() || value <= vMin.top())
            vMin.push(value);
    }
    void pop()
    {
        if (vMin.top() == v.top())
            vMin.pop();
        v.pop();
    }
    int top()
    {
        return v.top();
    }
    int min()
    {
        return vMin.top();
    }

  private:
    stack<int> v;
    stack<int> vMin;
};
``` 


[url1.1]:https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking