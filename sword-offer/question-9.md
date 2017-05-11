## 面试题9 [斐波那契数列][url1]

<!-- TOC -->

- [面试题9 斐波那契数列](#面试题9-斐波那契数列)
- [题目1](#题目1)
    - [思路](#思路)
    - [递归实现](#递归实现)
    - [非递归实现](#非递归实现)
- [题目2](#题目2)
    - [思路](#思路-1)
    - [递归实现](#递归实现-1)
    - [非递归实现](#非递归实现-1)

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

[url1]:https://github.com/yunshouhu/InterviewQuestions/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%989%E4%B9%8B%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97_Fibonacci.cpp