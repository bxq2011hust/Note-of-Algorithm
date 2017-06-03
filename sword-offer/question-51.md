## 面试题51 数组中重复的数字

<!-- TOC -->

- [面试题51 数组中重复的数字](#面试题51-数组中重复的数字)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。[牛客网地址][url]

### 思路
1. 使用哈希表统计出现次数，如果次数等于2，则这个数字加入重复数字数组
2. 时间复杂度O(n)，空间复杂度O(n)
### 实现

```cpp
class Solution
{
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        if (numbers == NULL || length < 2 || duplication == NULL)
            return false;
        unordered_map<int, int> times;
        int j = 0;
        for (int i = 0; i < length; ++i)
        {
            ++times[numbers[i]];
            if (times[numbers[i]] == 2)
                duplication[j++] = numbers[i];
        }
        return (j > 0);
    }
};
``` 
[url]:https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking