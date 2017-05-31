## 面试题41 和为S的两个数字 & 和为S的连续正数序列

<!-- TOC -->

- [面试题41 和为S的两个数字 & 和为S的连续正数序列](#面试题41-和为s的两个数字--和为s的连续正数序列)
- [题目1](#题目1)
    - [思路1](#思路1)
    - [思路2](#思路2)
    - [实现](#实现)
- [题目2](#题目2)
    - [思路2](#思路2-1)

<!-- /TOC -->

## 题目1

输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。对应每个测试案例，输出两个数，小的先输出。 [牛客网地址][url]

### 思路1
1. 从第一个数，每次与其之后的数字求和，判断

### 思路2
1. 遍历数组，两个下标first与second分别指向第一个和最后一个元素
2. 如果两个数的和大于sum，则second前移；如果两个数的和小于sum，则first后移
3. 分析可知，第一个找到的就是乘机最小的
### 实现

```cpp
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.empty()) return result;
        int first=0,second=array.size()-1;
        while(first<second)
        {
            if(array[first]+array[second]==sum)
            {
            	result.push_back(array[first]);
                result.push_back(array[second]);
                break;
            }
            else if(array[first]+array[second]>sum)
                --second;
            else ++first;
        }
        return result;
    }
};
``` 
## 题目2

和为S的连续正数序列，输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。[牛客网地址][url2]

### 思路2
1. small、big分别指向序列的第一个数字和结束数字
2. 初始`small=1 big=2`，假设sum==9，则第一次执行，由于[1,2]的和小于9，所以将big增大；然后下一次[1,3]的和小于9，则继续增大big；[1,4]和为10，大于9，此时将small增大，也就是变成[2,3,4]，等于9，该序列符合条件，继续增大big.....
3. 由于序列至少有两个数字，所以small应该小于(sum+1)/2，否则的话，如果序列有两个数字则序列的和大于sum

例如，求和为9的连续序列

|步骤|small|big|序列|序列和|与sum相比|下一步|
|:--|:--|:--|:--|:--|:--|:--|
|1|1|2|[1,2]|3|小于|增加big|
|2|1|3|[1,3]|6|小于|增加big|
|3|1|4|[1,4]|10|大于|增加small|
|4|2|4|[2,4]|9|等于|符合条件，增加big|
|5|2|5|[2,5]|14|大于|增加small|
|6|3|5|[3,5]|12|大于|增加small|
|7|4|5|[4,5]|9|等于|符合条件，增加big|
|8|4|6|[4,6]|15|大于|增加small|
|8|5|6|[5,6]|11|大于|small不满足条件，退出|


```cpp
class Solution {
public:
    vector<int> numSeq(int start,int end)
    {
        vector<int> res;
        for(int i=start;i<=end;++i)
        {
            res.push_back(i);
        }
        return res;
    }
   
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if(sum<3) return result;
        int small=1,big=2,middle=(sum+1)/2;
        int currSum=3;
        while(small<middle)
 		{
            if(currSum==sum)
                result.push_back(numSeq(small,big));
            while(currSum>sum&&small<middle)
            {
                currSum-=small;
                ++small;
                if(currSum==sum)
                result.push_back(numSeq(small,big));
            }
            ++big;
            currSum+=big;
        }
        return result;
    }
};
``` 


[url]:https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3
[url2]:https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking