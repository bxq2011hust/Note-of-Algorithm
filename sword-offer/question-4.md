## 面试题4 [替换空格][url1]

<!-- TOC -->

- [面试题4 [替换空格][url1]](#面试题4-替换空格url1)
- [题目](#题目)
    - [思路](#思路)
    - [牛客网实现](#牛客网实现)

<!-- /TOC -->

## 题目
实现一个函数，把字符串中的每个空格替换成`"%20"`

### 思路
先遍历字符串，统计空格个数`blanks`，则替换后的字符串长度为`len+2*blanks`，然后从后往前复制，遇到空格时替换。

### 牛客网实现
```cpp
class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        if (str == NULL || length <= 0)
            return;
        int numberOfBlank = 0;
        int i = 0;
        while (str[i] != '\0')
            if (str[i++] == ' ')
                ++numberOfBlank;
        int originalLength = i;
        int newLength = originalLength + 2 * numberOfBlank;
        if (newLength > length)
            return;
        while (originalLength >= 0 && newLength > 0)
        {
            if (str[originalLength] == ' ')
            {
                str[newLength--] = '0';
                str[newLength--] = '2';
                str[newLength--] = '%';
            }
            else
            {
                str[newLength--] = str[originalLength];
            }
            --originalLength;
        }
    }
};
``` 
[url1]:https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
