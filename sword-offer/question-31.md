## 面试题31 连续子数组的最大和

<!-- TOC -->

- [面试题31 连续子数组的最大和](#面试题31-连续子数组的最大和)
- [[题目][url]](#题目url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]
输入一个整形数组，数组里有正数也有负数，数组中一个或者连续多个数组成一个子数组，求所有子数组的和的最大值，要求时间复杂度为O(n)

### 思路
1. 从头到尾遍历数组，存储累加和以及当前的最大值，如果累加和小于等于0，则将累加和置位当前值，否则累加
2. 保存每次处理之后的最大值

### 实现

```cpp
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.empty()) return 0;
        int sum=0,maxValue=array[0];
        for(int i=0;i<array.size();++i)
        {
            if(sum<=0)
                sum=array[i];
            else
                sum+=array[i];
            if(sum>maxValue)
                maxValue=sum;
        }
        return maxValue;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
