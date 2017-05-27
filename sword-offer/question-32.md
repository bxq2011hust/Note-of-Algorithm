## 面试题32 从1到n整数中1出现的次数

<!-- TOC -->

- [面试题32 整数中1出现的次数（从1到n）](#面试题32-整数中1出现的次数从1到n)
- [[题目][url]](#题目url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]
输入一个整数n，求出1~n的整数的十进制表示中1出现的次数。例如输入12，则包含1的数字有`1 10 11 12`其中1一共出现5次

### 思路
1. 考虑21345，将21345分为两段，一段是[1,1345]，另一段是[1346,21345]
2. 对于[1346,21345]，1的出现分量两种情况，分别是1出现在第一位和出现在其他低位。当1出现在第一位时，如果第一位大于1，则1出现在1-19999这一万个数的万位，一共是`10000=10^4`；如果第一位等于1，则1的出现次数是去除第一位之后剩下的数加1，例如1234中1出现在1000-1234一共234+1=235个
3. 接下来考虑1出现在其他低位的情况，对[1346,21345]我们可以将其分为[1346,11345]和[11346,21345]两段，对于[1346,11345]相当于[1-10000]，由于10000已经计算过，其实相当于[1,9999]，也就是1可以出现在低四位的任意一位，选一位然后其他三位可以为[0,9]，则1一共出现`4*10^3=4000`次，所以[1346,11345]和[11346,21345]两段一共出现2*4000=8000次
4. 对于[1,1345]可以递归处理

### 实现

```cpp
class Solution
{
  public:
    int NumberOf1(string str)
    {
        if (str.empty())
            return 0;
        if (str[0] < '0' || str[0] > '9' || str[0] == '\0')
            return 0;
        int first = str[0] - '0';
        int len = str.size();
        if (len == 1 && first == 0)
            return 0;
        if (len == 1 && first > 0)
            return 1;
        // 假设str为"21345"
        //numFirstDigit是数字10000-19999的第一个位中1的数目
        int numFirstDigit = 0;
        if (first > 1)
            numFirstDigit = pow(10, len - 1);
        else if (first == 1)
            numFirstDigit = stoi(str.substr(1), nullptr, 10) + 1;
        //numOtherDigit是1346-21345除了第一位之外的数位中的数字
        int numOtherDigit = first * (len - 1) * pow(10, len - 2);
        //numRecursive是1-1345中1的数目
        int numRecursive = NumberOf1(str.substr(1));
        return numFirstDigit + numOtherDigit + numRecursive;
    }
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n < 1)
            return 0;
        return NumberOf1(to_string(n));
    }
};
``` 
[url]:https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
