## 面试题53 正则表达式匹配

<!-- TOC -->

- [面试题53 正则表达式匹配](#面试题53-正则表达式匹配)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。[牛客网地址][url]

### 思路
1. 分为第二个字符是`'*'`和不是`'*'`来处理
2. 第二个字符不是`'*'`，则判断模式字符串和原字符串，相同或者模式串为`'.'`，递归处理下一个字符
3. 第二个字符是`'*'`，则考虑前一个字符，分为前一个字符是相等或者`'.'`，不相同则表示匹配0个字符，分别递归调用

### 实现

```cpp
class Solution
{
  public:
    bool match(char *str, char *pattern)
    {
        if (str == NULL || pattern == NULL)
            return false;
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        //模式字符串的第二个字符是'*'
        if (*(pattern + 1) == '*')
        {
            if (*str == *pattern || (*pattern == '.' && *str != '\0'))
                //匹配1个字符，跳过通配符
                return match(str + 1, pattern + 2) 
                //匹配1个字符，继续通配符
                || match(str + 1, pattern) 
                //匹配0个字符
                || match(str, pattern + 2);
            else
                return match(str, pattern + 2);
        }
        //模式字符串的第二个字符不是'*'
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match(str + 1, pattern + 1);
        return false;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking