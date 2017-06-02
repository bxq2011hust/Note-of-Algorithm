## 面试题49 把字符串转换成整数

<!-- TOC -->

- [面试题49 把字符串转换成整数](#面试题49-把字符串转换成整数)
- [题目](#题目)
    - [输入描述](#输入描述)
    - [输出描述](#输出描述)
- [测试用例](#测试用例)
    - [思路](#思路)
    - [实现1](#实现1)
    - [实现2](#实现2)

<!-- /TOC -->

## 题目

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0 。[牛客网地址][url]

### 输入描述
输入一个字符串,包括数字字母符号,可以为空

### 输出描述
如果是合法的数值表达则返回该数字，否则返回0

## 测试用例
```bash
输入例子:
+2147483647
    1a33
输出例子:
2147483647
    0
```

### 思路
1. 考虑符号
2. 考虑正数和负数的溢出问题

### 实现1

```cpp
class Solution
{
  public:
    int StrToInt(string str)
    {
        if (str.empty())
            return 0;
        int sgn = 1;
        int index = 0;
        long long result = 0;
        if (str[index] == '+')
            ++index;
        else if (str[index] == '-')
        {
            ++index;
            sgn = -1;
        }
        while (index < str.size())
        {
            if (isdigit(str[index]))
            {
                result = result * 10 + str[index] - '0';
            }
            else
            {
                result = 0;
                break;
            }
            ++index;
        }
        if ((sgn > 0 && result > 0x7fffffff)
            || (sgn < 0 && result > 0xffffffff))
            result = 0;
        return (int)result * sgn;
    }
};
``` 
### 实现2

```cpp
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include <stdio.h>
#include <stdlib.h>

long long StrToIntCore(const char* str, bool minus);

enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;

    if(str != NULL && *str != '\0') 
    {
        bool minus = false;
        if(*str == '+')
            str ++;
        else if(*str == '-') 
        {
            str ++;
            minus = true;
        }

        if(*str != '\0') 
        {
            num = StrToIntCore(str, minus);
        }
    }

    return (int)num;
}

long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0') 
    {
        if(*digit >= '0' && *digit <= '9') 
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if((!minus && num > 0x7FFFFFFF) 
                || (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }

            digit++;
        }
        else 
        {
            num = 0;
            break;
        }
    }

    if(*digit == '\0') 
    {
        g_nStatus = kValid;
    }

    return num;
}

// ====================测试代码====================
void Test(char* string)
{
    int result = StrToInt(string);
    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(NULL);
    Test("");
    Test("123");
    Test("+123");
    Test("-123");
    Test("1a33");
    Test("+0");
    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    
    Test("-2147483647");
    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    
    Test("+2147483649");
    Test("-2147483649");
    Test("+");
    Test("-");

    return 0;
}
``` 

[url]:https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking