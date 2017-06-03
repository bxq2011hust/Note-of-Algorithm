## 面试题54 表示数值的字符串

<!-- TOC -->

- [面试题54 表示数值的字符串](#面试题54-表示数值的字符串)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。[牛客网地址][url]

### 思路
1. 首先看是不是正负号，是则处理下一个字符，如果是'\0'则退出
2. 跳过数字部分，如果此时是'\0'则返回true；否则判断是不是小数，对小数跳过数字，然后判断是不是科学计数法；否则判断是不是科学计数法；其余情况直接返回false
3. 最后判断标志变量numeric和最后一个字符是不是'\0'

### 实现

```cpp
class Solution
{
  public:
    void scanDigits(char **str)
    {
        while (**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
    }
    bool isExponential(char **str)
    {
        if (**str != 'E' && **str != 'e')
            return false;
        ++(*str);
        if (**str == '-' || **str == '+')
            ++(*str);
        if (**str == '\0')
            return false;
        scanDigits(str);
        return (**str == '\0');
    }
    bool isNumeric(char *string)
    {
        if (string == NULL)
            return false;
        if (*string == '-' || *string == '+')
            ++string;
        if (*string == '\0')
            return false;
        bool numeric = true;
        scanDigits(&string);
        if (*string != '\0')
        {
            // 小数
            if (*string == '.')
            {
                ++string;
                scanDigits(&string);
                if (*string == 'e' || *string == 'E')
                    numeric = isExponential(&string);
            }
            // 科学计数法
            else if (*string == 'e' || *string == 'E')
                numeric = isExponential(&string);
            // 其他返回false
            else
                numeric = false;
        }
        return numeric && (*string == '\0');
    }
};
``` 
[url]:https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking