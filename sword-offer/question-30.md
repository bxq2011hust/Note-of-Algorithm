## 面试题30 最小的K个数

<!-- TOC -->

- [面试题30 最小的K个数](#面试题30-最小的k个数)
- [[题目][url]](#题目url)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2-基于Partition函数的O(n)算法](#思路2-基于partition函数的on算法)
    - [实现2](#实现2)

<!-- /TOC -->

## [题目][url]
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

### 思路1
1. 如果k大于数组含有的元素，或者k<=0，或者数组为空直接返回空数组
2. 遍历一遍数组，是用最大堆保存数组元素，如果小于k个，则直接插入，如果已经有k个则判断输入元素是否比已有元素的最大值小，如果是则删除最大值后插入。时间复杂度为O(nlongk)，multiset使用红黑树实现，查找、插入和删除等操作都只需要O(longk)的时间

### 实现1

```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty()||k<1||k>input.size()) return vector<int>();
        multiset<int,greater<int>> res;
        
        for(int i=0;i<input.size();++i)
        {
            if(res.size()<k)
                res.insert(input[i]);
            else
            {
                if(input[i]<*(res.begin()))
                {
                	res.erase(res.begin());
                    res.insert(input[i]);
                }
            }
        }
        vector<int> result(res.rbegin(),res.rend());
        return result;
    }
};
``` 
### 思路2-基于Partition函数的O(n)算法
1. 数组排序后前k个数字就是所求数字，基于partition函数来解决
2. 对数组调用Partition，如果下标刚好是k-1，前面的数字就是最小的k个数；如果返回的index大于k-1，修改end为index-1，递归调用Partition；如果返回的index小于k-1，修改start为index+1，递归调用partition；

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

vector<int> GetLeastKNumbers(vector<int> input,int k)
{
    vector<int> res;
    if(input.empty()||k<1||k>input.size()) return res;
    int length = input.size();
    int start = 0;
    int end = length - 1;
    int index = partition(input,start,end);
    while(index!=k-1)
    {
        if(index>k-1)
        {
            end=index-1;
            index=partition(input,start,end);
        }
        else
        {
            start=index+1;
            index=partition(input,start,end);
        }
    }

    for(int i=0;i<k;++i)
        res.push_back(input[i]);

    return res;
}
``` 

[url]:https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
