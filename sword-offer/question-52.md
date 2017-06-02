## 面试题52 构建乘积数组

<!-- TOC -->

- [面试题52 构建乘积数组](#面试题52-构建乘积数组)
- [题目](#题目)
    - [思路](#思路)
    - [实现1](#实现1)

<!-- /TOC -->

## 题目

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。[牛客网地址][url]

### 思路
1. 定义`C[i]=A[0]*A[1]*...*A[i-1] C[0]=1`，则有`C[i]=C[i-1]*A[i-1] i>0`
2. 定义`D[i]=A[i+1]*...*A[n-2]*A[n-1] D[n-1]=1`，则有`D[i]=D[i+1]*A[i+1] i<n-1`
3. 所以`result[i]=C[i]*D[i]`

### 实现1

```cpp
class Solution
{
  public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> result;
        if (A.size() < 1)
            return result;
        result.resize(A.size(), 1);
        for (int i = 1; i < A.size(); ++i)
        {
            result[i] = result[i - 1] * A[i - 1];
        }
        double temp = 1;
        for (int i = A.size() - 2; i >= 0; --i)
        {
            temp *= A[i + 1];
            result[i] *= temp;
        }
        return result;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking