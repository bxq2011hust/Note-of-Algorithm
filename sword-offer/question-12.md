## 面试题12 打印1到最大的n位数

<!-- TOC -->

- [面试题12 打印1到最大的n位数](#面试题12-打印1到最大的n位数)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目1
输入数字n，按顺序打印从1到最大的n位十进制数，输入3则打印1、2、3、...、999

### 思路
1. n很大时，可能导致溢出，故需要处理大数问题
2. 使用字符串模拟加法

### 实现
```cpp

// 大数加1，大数按照从低位到高位存储，例如123在string中存为321
void IncrBigInt(string &bigInt)
{
    ++bigInt[0];
    int carry = 0, newValue;
    for (size_t i = 0; i < bigInt.size(); ++i)
    {
        newValue = bigInt[i] - '0' + carry;
        carry = newValue / 10;
        bigInt[i] = newValue % 10 + '0';
    }
    if (carry == 1)
        bigInt += '1';
}

// 打印结果
void Print1ToMaxOfNDigits(int n)
{
    string num("1");
    while (num.size() <= n)
    {
        cout << string(num.rbegin(), num.rend()) << endl;
        IncrBigInt(num);
    }
}
``` 

