## 面试题47 不用加减乘除做加法

<!-- TOC -->

- [面试题47 不用加减乘除做加法](#面试题47-不用加减乘除做加法)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)
- [相关题目](#相关题目)

<!-- /TOC -->

## 题目

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。[牛客网地址][url]

### 思路
1. 不考虑进位相加，使用异或处理
2. 与操作，然后左移一位，得到进位的数
3. 将第二步与第一步的结果再次相加，直到第二步进位为0

### 实现

```cpp
class Solution
{
  public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        do
        {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while (num2 != 0);
        return num1;
    }
};
``` 
## 相关题目
不使用新的变量，交换两个变量的值

|基于加减法|基于异或运算|
|:---|:---|
|a=a+b|a=a^b|
|b=a-b|b=a^b|
|a=a-b|a=a^b|

[url]:https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking