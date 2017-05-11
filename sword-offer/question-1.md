## 面试题1 赋值运算符


```cpp
// MyString.h
class MyString
{
    public:
    MyString(char * pData=NULL);
    MyString(const MyString&str);
    MyString & operator=(const MyString &str);
    ~MyString();

    private:
    char * m_pData;
}

// MyString.cpp
MyString & MyString::operator=(const MyString & str)
{
    if(this!=&str)
    {
        MyString strTmp(str);
        char * pTemp = strTmp.m_pData;
        strTmp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}

```
异常安全，当发生异常时，不会导致原始实例的状态改变。

## 参考链接
1. [异常安全](http://www.cnblogs.com/zgfLawliet/p/3417308.html)
2. [争取异常安全（exception-safe）的代码](https://wizardforcel.gitbooks.io/effective-cpp/content/31.html)

