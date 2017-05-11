## 面试题7 用两个栈实现队列

<!-- TOC -->

- [面试题7 用两个栈实现队列](#面试题7-用两个栈实现队列)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)
    - [牛客网](#牛客网)

<!-- /TOC -->

## 题目
使用两个栈实现队列，支持`pop() push()`操作

### 思路
1. 元素入队列，直接压入栈1
2. 元素出队列从栈2出，如果两个栈都为空，返回；如果栈2为空则将栈1的元素压入栈2，再出
3. 支持的操作`front() back() pop() push() size() empty() `

### 实现
```cpp
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class mQueue
{
    stack<T> inStack;
    stack<T> outStack;
    T tail;
    void transfer()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

  public:
    typedef typename stack<T>::value_type value_type;
    typedef typename stack<T>::size_type size_type;
    typedef typename stack<T>::reference reference;
    typedef typename stack<T>::const_reference const_reference;

    mQueue() {}
    bool empty() { return inStack.empty() && outStack.empty(); }
    size_type size() { return inStack.size() + outStack.size(); }
    reference front()
    {
        transfer();
        if (outStack.empty())
            throw "Queue is empty!";
        else
            return outStack.top();
    }
    const_reference front() const
    {
        if (outStack.empty())
            throw "Queue is empty!";
        else
            return outStack.top();
    }
    reference back()
    {
        if (empty())
            throw "Queue is empty!";
        else
            return tail;
    }

    const_reference back() const
    {
        if (empty())
            throw "Queue is empty!";
        else
            return tail;
    }

    void push(const value_type &x)
    {
        inStack.push(x);
        tail = x;
    }
    void pop()
    {
        transfer();
        if (!outStack.empty())
            outStack.pop();
    }
};
``` 
### 牛客网
```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res=0;
		if(!stack2.empty())
        {
        	res=stack2.top();
            stack2.pop();
        }
        else
        {
        	while(stack1.size()>1)
            {
            	stack2.push(stack1.top());
                stack1.pop();
            }
            res=stack1.top();
            stack1.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
``` 

