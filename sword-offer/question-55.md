## 面试题55 字符流中第一个不重复的字

<!-- TOC -->

- [面试题55 字符流中第一个不重复的字](#面试题55-字符流中第一个不重复的字)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符。 [牛客网地址][url]

### 思路
1. 使用哈希表实现，times数组存储某个字符出现的下标；初始置为-1
2. 每次插入新字符时，如果该字符有下标，则表示该字符出现两次，置其为-2；
3. 如果该字符下标为-1，则是第一次出现
4. 返回第一次出现的字符，只需要遍历times数组，找到下标大于-1的最小值

### 实现

```cpp
class Solution
{
  public:
    Solution() : index(0)
    {
        for (int i = 0; i < 256; ++i)
            times[i] = -1;
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if (times[ch] == -1)
            times[ch] = index;
        else if (times[ch] >= 0)
            times[ch] = -2;
        ++index;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int minIndex = numeric_limits<int>::max();
        for (int i = 0; i < 256; ++i)
        {
            if (times[i] >= 0 && times[i] < minIndex)
            {
                ch = (char)i;
                minIndex = times[i];
            }
        }
        return ch;
    }

  private:
    int index;
    int times[256];
};
``` 
[url]:https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking