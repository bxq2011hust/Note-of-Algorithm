## 面试题29 数组中出现次数超过一半的数字

<!-- TOC -->

- [面试题29 数组中出现次数超过一半的数字](#面试题29-数组中出现次数超过一半的数字)
- [[题目][url]](#题目url)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2-基于Partition函数的O(n)算法](#思路2-基于partition函数的on算法)
    - [实现2](#实现2)
    - [思路3-根据数组特点找出O(n)的算法](#思路3-根据数组特点找出on的算法)
    - [实现3](#实现3)

<!-- /TOC -->

## [题目][url]
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

### 思路1
1. 遍历一遍数组，统计每个数字出现的次数，记录出现次数最多的数字
2. 如果出现次数多于一半则输出，否则输出0

### 实现1

```cpp
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        unordered_map<int,int> count;
        int freq=0,num=0;
        for(auto i:numbers)
        {
            ++count[i];
            if(count[i]>freq)
                {
                freq=count[i];
                num=i;
            }
        }
        if(freq>numbers.size()/2) return num;
        return 0;
    }
};
``` 
### 思路2-基于Partition函数的O(n)算法
1. 如果有一个数字超过一半，则排序后该数字必定在数组的中间位置n/2，也就是中位数
2. 对数组调用Partition，如果下标刚好是n/2，那么该数字就是中位数；如果返回的index大于n/2，那么中位数必定在index的左边，递归调用Partition；如果返回的index小于n/2那么中位数应该位于index的右边，递归调用partition；

### 实现2
```cpp
int partition(vector<int>& a, int left, int right)
{
    int len=right;
    int pivot=a[len];
    int tail=left;
    for(int i=left;i<len;++i)
    {
        if(a[i]<=pivot)
        {
            if(tail!=i) 
                swap(a[i],a[tail]);
            ++tail;
        }
    }
    //下面的交换可能导致不稳定
    if(tail!=len)
        swap(a[tail],a[len]);
    return tail;
}

bool CheckMoreThanHalf(vector<int> & numbers,int number)
{
    int times=0;
    for(int i=0;i<numbers.size();++i)
    {
        if(numbers[i]==number)
            ++times;
    }
    if(times*2<=numbers.size()) return false;
    return true;
}
int MoreThanHalNum(vector<int> numbers)
{
    if(numbers.empty()) return 0;
    int length = numbers.size();
    int middle = length>>1;
    int start = 0;
    int end = length - 1;
    int index = partition(numbers,start,end);
    while(index!=middle)
    {
        if(index>middle)
        {
            end=index-1;
            index=partition(numbers,start,end);
        }
        else
        {
            start=index+1;
            index=partition(numbers,start,end);
        }
    }

    int result=numbers[middle];
    if(!CheckMoreThanHalf(numbers,result))
        result = 0;
    return result;
}
``` 

### 思路3-根据数组特点找出O(n)的算法
1. 如果有一个数字超过一半，也就是其他数字出现次数之和都小于该数字出现次数，遍历数组时保存两个值，一个是数组中的数字number，一个是次数times，如果下一个数字与该数字相同则++times，如果不同则--times，如果times==0则将下一个数字赋值给number并将times置位1，继续循环。
2. 最差的情况是每个数字之后都是同样数量的超过一半的数字，则最后一次number依旧等于出现次数超过一半的数字。例如`3 3 2 2 4 2 1 1 2 2 2`
3. 如果没有超过一半的数字，则可能错误，所以最后要再做一次检查

### 实现3
```cpp
bool CheckMoreThanHalf(vector<int> & numbers,int number)
{
    int times=0;
    for(int i=0;i<numbers.size();++i)
    {
        if(numbers[i]==number)
            ++times;
    }
    if(times*2<=numbers.size()) return false;
    return true;
}
int MoreThanHalNum(vector<int> numbers)
{
    if(numbers.empty()) return 0;
    int result=numbers[0];
    int times=1;
    
    for(int i=1;i<numbers.size();++i)
    {
        if(times==0)
        {
            result=numbers[i];
            times=1;
        }
        else if(numbers[i]==result)
            ++times;
        else --times;
    }

    if(!CheckMoreThanHalf(numbers,result))
        result = 0;
    return result;
}
``` 


[url]:https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
