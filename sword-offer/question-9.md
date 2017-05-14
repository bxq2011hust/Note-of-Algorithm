## 面试题9 [斐波那契数列][url1]

<!-- TOC -->

- [面试题9 [斐波那契数列][url1]](#面试题9-斐波那契数列url1)
- [题目1](#题目1)
    - [思路](#思路)
    - [递归实现](#递归实现)
    - [非递归实现](#非递归实现)
- [题目2](#题目2)
    - [思路](#思路-1)
    - [递归实现](#递归实现-1)
    - [非递归实现](#非递归实现-1)
- [题目3](#题目3)
    - [思路](#思路-2)
- [时间复杂度为O(logn)的解法](#时间复杂度为ologn的解法)
- [题目4 变态跳台阶](#题目4-变态跳台阶)
    - [思路](#思路-3)

<!-- /TOC -->

## 题目1
求斐波那契数列的第`n`项

### 思路
1. 非递归实现
2. 递归实现

### 递归实现
```cpp
int Fibonacci(int n) 
{
	if(n<2) return n;
	return Fibonacci(n-1) + Fibonacci(n-2);
}
``` 
### 非递归实现
```cpp
int Fibonacci(int n)
{
	if (n < 2)
		return n;
	int first = 0;
	int second = 1;
	int res = 1;
	for (; n >= 2; --n)
	{
		res = first + second;
		first = second;
		second = res;
	}
	return res;
}
``` 

 ****
## 题目2
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

### 思路
1. 非递归实现
2. 递归实现
3. 记`f(n)`表示n级台阶的跳法，则`f(n)=f(n-1)+f(n-2)`
### 递归实现
```cpp
int jumpFloor(int n) {
        if(n<3) return n;
        return jumpFloor(n-1)+jumpFloor(n-2);
}
``` 
### 非递归实现
```cpp
    int jumpFloor(int n) {
        if(n<3) return n;
        int last=2,tmp=0;
        int num=3,sum=3;
        while(num<n)
        {
            ++num;
            tmp=sum;
            sum+=last;
            last=tmp;
        }
        return sum;
    }
``` 

## 题目3

我们可以用`2*1`的小矩形横着或者竖着去覆盖更大的矩形。请问用n个`2*1`的小矩形无重叠地覆盖一个`2*n`的大矩形，总共有多少种方法？

### 思路
1. 当`n==1`只有一种可能，当`n==2`有两种可能
2. 当`n==k`，则有竖着放时`f(k-1)`种可能，横着放则有`f(k-2)`种可能

****
## 时间复杂度为O(logn)的解法

基于矩阵乘法
```cpp
struct Matrix2By2
{
    long long m_00,m_01,m_10,m_11;
    Matrix2By2(long long m00 = 0, 
        long long m01 = 0, 
        long long m10 = 0, 
        long long m11 = 0):m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}
}

Matrix2By2 MatrixMultiply
(
    const Matrix2By2& matrix1, 
    const Matrix2By2& matrix2
)
{
    return Matrix2By2(
        matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
        matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
        matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
        matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0);

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0)
    {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1)
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}

```

****
## 题目4 变态跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

### 思路
1. 跳第一级台阶有1中可能，第二级有两种可能
2. 跳第`n`级台阶，相当于先跳k级再跳`n-k`级，而跳k级的可能是`f(k)`，k可能的取值为`0->(n-1)`
3. 所以跳第`n`级台阶的可能有`f(n-1)+f(n-2)+...+f(1)+1`
```cpp
int jumpFloorII(int number)
{
    if (number < 3)
        return number;
 /*   vector<int> res(1, 0);
    int sum = 0;
    for (int i = 1; i <= number; ++i)
    {
        res.push_back(sum + 1);
        sum += res[i];
    }
    return res[number];
*/
    int sum = 0,curr=0;
    for(int i=1;i<=number;++i)
    {
        curr=sum+1;
        sum+=curr;
    }
    return curr;
}
```
[url1]:https://github.com/yunshouhu/InterviewQuestions/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%989%E4%B9%8B%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97_Fibonacci.cpp