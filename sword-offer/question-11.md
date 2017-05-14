## 面试题11 数值的整数次方

<!-- TOC -->

- [面试题11 数值的整数次方](#面试题11-数值的整数次方)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目1
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。不考虑大数问题

### 思路
1. 考虑base为0时的处理
2. 考虑指数为负值时的处理
3. 考虑乘法的加速，考虑`a^n=a^(n/2)*a^(n/2) n为偶数时`与`a^n=a^[n/2]*a^[n/2]*a n为奇数时`

### 实现
```cpp
// 比较浮点数的相等
bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    return false;
}

// 计算乘方
double PowerUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double result = PowerUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 1) == 1)
        result *= base;
    return result;
}

double Power(double base, int exponent)
{
    if (equal(base, 0.0) && exponent < 0)
        throw "Invalid Parameter.";
    unsigned int absExponent = (unsigned int)exponent;
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);
    double result = PowerUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1 / result;
    return result;
}
``` 

