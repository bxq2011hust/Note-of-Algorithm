## 面试题48 不能被继承的类

<!-- TOC -->

- [面试题48 不能被继承的类](#面试题48-不能被继承的类)
- [题目](#题目)
    - [思路1](#思路1)
    - [实现](#实现)
    - [思路2](#思路2)
    - [实现](#实现-1)
    - [思路3](#思路3)
    - [实现3](#实现3)

<!-- /TOC -->

## 题目
用C++设计一个不能被继承的类

### 思路1
1. C++11支持的final关键字

### 实现

```cpp
class base final {};
class derived: public base{};
``` 

```bash
error: cannot derive from 'final' base 'base' in derived type 'derived'
 class derived: public base{};
```
### 思路2
1. 设置类的构造函数和析构函数为私有的，类似于单例的实现，参考这里[实现Singleton模式](question-2.md)

### 实现

```cpp
class SealedClass
{
  public:
    static SealedClass *GetInstance()
    {
        return new SealedClass();
    }
    static void DeleteInstance(SealedClass *instance)
    {
        delete instance;
    }

  private:
    SealedClass() {}
    ~SealedClass() {}
};
``` 

### 思路3
1. 利用虚拟继承实现

### 实现3

```cpp
template <typename T>
class MakeSealed
{
    friend T;
  private:
    MakeSealed() {}
    ~MakeSealed() {}
};
class SealedClass : virtual public MakeSealed<SealedClass>
{
  public:
    SealedClass() {}
    ~SealedClass() {}
};
class Try : public SealedClass
{
  public:
    Try() {}
    ~Try() {}
};
``` 
