## 面试题2 实现Singleton模式
<!-- TOC -->

- [面试题2 实现Singleton模式](#面试题2-实现singleton模式)
    - [1. 饿汉模式](#1-饿汉模式)
    - [2. 懒汉模式](#2-懒汉模式)
    - [3. 懒汉模式改进](#3-懒汉模式改进)
    - [4. 静态局部变量](#4-静态局部变量)
- [参考链接](#参考链接)

<!-- /TOC -->
**单例模式**：保证单例类只能有一个实例

### 1. 饿汉模式

**特点**：程序运行时立刻初始化

**缺点**：单例类的构造函数里调用另一个单例类的方法，需要考虑初始化顺序，详情见末尾**参考链接**
```cpp
class Singleton
{
  public:
    static Singleton *getInstance()
    {
        return &instance;
    }

  private:
    Singleton(){};
    Singleton(const Singleton &s){};
    Singleton &operator=(const Singleton &s){};
    ~Singleton(){};

    static Singleton instance;
};
Singleton Singleton::instance;
```

### 2. 懒汉模式

**特点**：单例实例在第一次被使用时初始化

**缺点**：线程不安全
```cpp
class Singleton
{
  public:
    static Singleton *getInstance()
    {
        if (!instance)
            instance = new Singleton();
        return instance;
    }

  private:
    Singleton(){};
    Singleton(const Singleton &s){};
    Singleton &operator=(const Singleton &s){};
    ~Singleton(){};

    static Singleton *instance;
    class CGarbage //在析构函数中删除Singleton的实例
    {
      public:
        ~CGarbage()
        {
            if (Singleton::instance)
            {
                delete Singleton::instance;
                Singleton::instance = NULL;
            }
//            std::cout << "delete Singleton instanc" << std::endl;
        }
    };
    static CGarbage garbo; //静态成员，程序结束时，自动调用它的析构函数
};
Singleton::CGarbage Singleton::garbage;
Singleton *Singleton::instance = NULL;

```

### 3. 懒汉模式改进

**思路**：加锁，前后两次判断实力是否已经存在，实例创建前加锁，之后再次调用`getInstance()`不会影响性能。
```cpp
// g++ -std=c++11
#include <mutex>

std::mutex mtx;
class Singleton
{
  public:
    static Singleton *getInstance()
    {
        if (!instance)
        {
            mtx.lock();
            if (!instance)
                instance = new Singleton();
            mtx.unlock();
        }
            
        return instance;
    }

  private:
    Singleton(){};
    Singleton(const Singleton &s){};
    Singleton &operator=(const Singleton &s){};
    ~Singleton(){};

    static Singleton *instance;
    class CGarbage 
    {
      public:
        ~CGarbage()
        {
            if (Singleton::instance)
            {
                delete Singleton::instance;
                Singleton::instance = NULL;
            }
        }
    };
    static CGarbage garbo; 
};
Singleton::CGarbage Singleton::garbage;
Singleton *Singleton::instance = NULL;

```

### 4. 静态局部变量

**思路**：私有的辅助类静态成员，程序运行时创建
```cpp
class Singleton
{
  public:
    static Singleton *getInstance()
    {
        static Singleton instance;
        return &instance;
    }

  private:
    struct Object_creator
    {
        Object_creator()
        {
            Singleton::Instance();
        }
    };
    static Object_creator creator;
    Singleton(){};
    ~Singleton(){};
    Singleton(const Singleton &);
    Singleton &operator=(const Singleton &);
};
Singleton::Object_creator Singleton::creator;

```

## 参考链接
1. [探究C++单利模式](http://blog.csdn.net/crayondeng/article/details/24853471)
1. [C++单例实现的坑](http://blog.cnbang.net/tech/2229/)


