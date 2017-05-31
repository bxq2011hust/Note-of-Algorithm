## 面试题42 翻转单词顺序列 & 左旋转字符串

<!-- TOC -->

- [面试题42 翻转单词顺序列 & 左旋转字符串](#面试题42-翻转单词顺序列--左旋转字符串)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)
- [题目2](#题目2)
    - [思路](#思路-1)

<!-- /TOC -->

## 题目1

输入一个英文句子，翻转句子中单词的顺序，但是单词内字符顺序不变，标点符号和普通字母一样处理，例如输入“I am a student.”，则输出“student. a am I”。[牛客网地址][url]

### 思路
1. 首先翻转句子中所有字符
2. 翻转句子中每个单词

### 实现

```cpp
class Solution
{
  public:
    void reverseString(string &str, int start, int end)
    {
        if (str.empty() || start >= end || start < 0)
            return;
        while (start < end)
        {
            char tmp = str[start];
            str[start++] = str[end];
            str[end--] = tmp;
        }
    }
    string ReverseSentence(string str)
    {
        if (str.empty())
            return str;
        reverseString(str, 0, str.size() - 1);
        int start = 0, end = 0;

        while (start < str.size())
        {
            if (str[start] == ' ')
            {
                ++start;
                ++end;
            }
            else if (str[end] == ' ' || str[end] == '\0')
            {
                reverseString(str, start, end - 1);
                start = ++end;
            }
            else
                ++end;
        }
        return str;
    }
};
``` 
## 题目2

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果。[牛客网地址][url2]

### 思路
1. 考虑"abcdefg"，将其分为两部分，假设要把前2个字符移到后面
2. 将其分为两部分，先翻转前两个字符，然后翻转剩余字符得到"bagfedc"
3. 翻转整个字符串得到"cdefgab"


```cpp
class Solution {
public:
    void reverseString(string &str, int start, int end)
    {
        if (str.empty() || start >= end || start < 0)
            return;
        while (start < end)
        {
            char tmp = str[start];
            str[start++] = str[end];
            str[end--] = tmp;
        }
    }
    string LeftRotateString(string str, int n) {
        if(str.empty()||n<1) return str;
        int len=str.size();
        //如果n==len则操作结果与源字符串相同
        n%=len;
        if(n==0) return str;
        reverseString(str,0,n-1);
        reverseString(str,n,len-1);
        reverseString(str,0,len-1);
        return str;
    }
};
``` 


[url]:https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
[url2]:https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking