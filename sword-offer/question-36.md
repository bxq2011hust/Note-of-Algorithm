## 面试题36 数组中的逆序对

<!-- TOC -->

- [面试题36 数组中的逆序对](#面试题36-数组中的逆序对)
- [[题目][url]](#题目url)
    - [输入描述及例子](#输入描述及例子)
    - [思路1](#思路1)
    - [思路2](#思路2)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

### 输入描述及例子

题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5

输入例子:1,2,3,4,5,6,7,0
输出:7

### 思路1
1. 遍历数组，每次和他后面的数字比较一遍，时间复杂度O(n^2)

### 思路2
1. 考虑借助归并排序的过程，时间复杂度O(nlongn)
2. 每次merge的时候，从最大的元素依次放入原数组，如果left数组中的i下标的元素比right数组中j下标的元素大，则存在(j+1)个逆序对，否则没有逆序对，按序放入原数组
3. 步骤2中，统计过逆序对之后，会将数组排序，避免重复统计
4. 例如`7 5 6 4`，处理过程如下，其中最后一步，首先7比6大，所以逆序对从2加上j+1为4，然后放入7，6，此时5比4大逆序对再加1为5

|步骤|数组元素|逆序对||
|:---|:--:|:--:|:--:|
|0|`7 5 6 4`|0|初始状态|
|1|`5 7 6 4`|1|处理`7 5`|
|2|`5 7 4 6`|2|处理`6 4`|
|3|`4 5 6 7`|5|处理`5 7`与`4 6`|

### 实现

```cpp
class Solution
{
  public:
    long long merge(vector<int> &data, int left, int mid, int right)
    {
        int len1 = mid - left;
        int len2 = right - mid;
        vector<int> leftItems, rightItems;
        for (int i = 0; i < len1; ++i)
            leftItems.push_back(data[i + left]);
        for (int i = 0; i < len2; ++i)
            rightItems.push_back(data[i + mid]);
        int i = len1 - 1, j = len2 - 1, k = right - 1;
        long long times = 0;
        while (i >= 0 && j >= 0)
        {
            if (leftItems[i] > rightItems[j])
            {
                data[k--] = leftItems[i--];
                times += j + 1;
            }
            else
            {
                data[k--] = rightItems[j--];
            }
        }
        while (j >= 0)
            data[k--] = rightItems[j--];
        while (i >= 0)
            data[k--] = leftItems[i--];

        return times;
    }
    unsigned int InversePairs(vector<int> data)
    {
        if (data.empty())
            return 0;
        int left, mid, right;
        int len = data.size();
        long long times = 0;
        for (int size = 1; size < len; size *= 2)
        {
            left = 0;
            while (left + size < len)
            {
                mid = left + size;
                right = mid + size;
                if (right > len)
                    right = len;
                times += merge(data, left, mid, right);
                left = right;
            }
        }
        return times % 1000000007;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
