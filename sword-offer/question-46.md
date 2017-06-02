## 面试题46 求1+2+3+...+n

<!-- TOC -->

- [面试题46 求1+2+3+...+n](#面试题46-求123n)
- [题目](#题目)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2](#思路2)
    - [实现2](#实现2)
    - [思路3](#思路3)
    - [实现3](#实现3)
    - [思路4](#思路4)
    - [实现4](#实现4)

<!-- /TOC -->

## 题目

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。[牛客网地址][url]

### 思路1
1. 使用函数指针

### 实现1

```cpp
class Solution
{
  public:
    typedef int (Solution::*fun)(int);
    int Sum_Solution_Teminator(int n)
    {
        return 0;
    }
    int Sum_Solution(int n)
    {
        static fun f[2] = {&Solution::Sum_Solution_Teminator, &Solution::Sum_Solution};
        return n + (this->*f[!!n])(n - 1);
    }
};
``` 
### 思路2
1. 使用构造函数求解

### 实现2

```cpp
class Temp
{
  public:
    Temp()
    {
        ++N;
        Sum += N;
    }
    static void Reset()
    {
        N = 0;
        Sum = 0;
    }
    static unsigned int GetSum() { return Sum; }

  private:
    static unsigned int N;
    static unsigned int Sum;
};
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution(unsigned int n)
{
    Temp::Reset();
    Temp *a = new Temp[n];
    delete[] a;
    a = NULL;
    return Temp::GetSum();
}
``` 
### 思路3
1. 使用虚函数求解

### 实现3

```cpp
class A
{
  public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};
A *Array[2];
class B : public A
{
  public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n - 1) + n;
    }
};
unsigned int Sum_Solution(unsigned int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);
    return value;
}
``` 

### 思路4
1. 使用模板类型求解，需要在编译时确定n

### 实现4

```cpp
template <unsigned int n>
struct Sum_Solution
{
    enum Value
    {
        N = Sum_Solution<n - 1>::N + n
    };
};
template <>
struct Sum_Solution<1>
{
    enum Value
    {
        N = 1
    };
};
int main()
{
    Sum_Solution<5> s; 
    cout<<s.N;
    return 0;
}
``` 

[url]:https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking