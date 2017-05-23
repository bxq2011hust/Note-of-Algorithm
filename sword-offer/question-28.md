## 面试题28 字符串的排列

<!-- TOC -->

- [面试题28 字符串的排列](#面试题28-字符串的排列)
- [[题目1][url]](#题目1url)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2](#思路2)
    - [实现2](#实现2)
- [题目2](#题目2)
    - [思路](#思路)
    - [实现](#实现)
- [题目3 八皇后问题](#题目3-八皇后问题)
    - [思路](#思路-1)
    - [实现](#实现-1)
- [题目4](#题目4)
    - [思路](#思路-2)
    - [实现](#实现-2)
- [参考资料](#参考资料)

<!-- /TOC -->

## [题目1][url]
输入一个字符串(可能有字符重复),按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 

### 思路1
1. 将所有可能的组合存储在result中，每次将字符串分为第一个字符和后面的字符，如果第一个字符是`\0`，则打印该字符串，否则从将字符串的第一个字符分别和后面的字符交换，然后递归处理，处理完之后交换回来，以便进行与下一个字符交换
2. 由于字符有重复，所以此时需要去重，对处理结果排序，然后使用`unique_copy`将不重复的字符串拷贝到新的容器中(unique只是将不重复的排到前面，并不改变容器大小)

### 实现1

```cpp
class Solution {
public:
    void Permutation(string str,int start,vector<string> &result)
    {
        if(start==str.size())
            {
            result.push_back(str);
        }
        else
            {
            for(int i=start;i<str.size();++i)
                {
                swap(str[start],str[i]);
                Permutation(str,start+1,result);
                swap(str[start],str[i]);
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> result,uniqueResult;
        if(str.empty()) return result;
        Permutation(str,0,result);
        sort(result.begin(),result.end());
        unique_copy(result.begin(),result.end(),back_inserter(uniqueResult));
        return uniqueResult;
    }
};
``` 
### 思路2
1. 将所有可能的组合存储在result中，每次将字符串分为第一个字符和后面的字符，如果第一个字符是`\0`，则打印该字符串，否则从将字符串的第一个字符分别和后面的字符交换，然后递归处理，处理完之后交换回来，以便进行与下一个字符交换
2. 考虑`abb`能够得到`bab bba`，而`bab`又能得到`bba`，如果第一个`abb`不得到`bba`则不重复，要实现这个需要**与第一个字符交换的字符b，在第一个字符到该字符b之间没有与b相等的字符**，则`abb`的`a`与第三个字符`b`交换时由于第二个字符是`b`，不交换。也就是如果第`i`个字符与第`j`个字符交换，则[i,j)中没有与j相等的字符。

### 实现2
```cpp
class Solution {
public:
    //在 str 数组中，[start,end) 中是否有与 str[end] 元素相同的
    bool IsSwap(string str,int start,int end)
    {
        for(;start<end;++start)
        {
            if(str[start] == str[end])
                return false;
        }
        return true;
    }
    void Permutation(string str,int start,vector<string> &result)
    {
        if(start==str.size())
            {
            result.push_back(str);
        }
        else
        {
            for(int i=start;i<str.size();++i)
            {
                if(IsSwap(str,start,i))
                {
                    swap(str[start],str[i]);
                    Permutation(str,start+1,result);
                    swap(str[start],str[i]);
                }
                
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.empty()) return result;
        Permutation(str,0,result);
        sort(result.begin(),result.end());
        return result;
    }
};
``` 

## 题目2
输入一个字符串，求字符的所有组合，例如输入`a,b,c`则组合有`a,b,c,ab,ac,bc,abc` 

### 思路
1. 一共有`2^n-1`中可能，则遍历1到2^n，该值二进制表示中为1，则加入字符串，构成一种组合

### 实现

```cpp
void Combination(char *str)
{
	if(str == NULL)
		return ;
	int len = strlen(str);
	int n = 1<<len;
	for(int i=1;i<n;i++)    //从 [1,2^len -1]
	{
		for(int j=0;j<len;j++)
		{
			int temp = i;
			if(temp & (1<<j))   //对应位上为1，则输出对应的字符
			{
				printf("%c",*(str+j));
			}
		}
		printf("\n");
	}
}
``` 

## 题目3 八皇后问题
在8×8的国际象棋上摆放八个皇后，使其不能相互攻击，即任意两个皇后不得处在同一行、同一列或者同一对角斜线上。下图中的每个黑色格子表示一个皇后，这就是一种符合条件的摆放方法。请求出总共有多少种摆法。

### 思路
由于八个皇后的任意两个不能处在同一行，那么这肯定是每一个皇后占据一行。于是我们可以定义一个数组ColumnIndex[8]，数组中第i个数字表示位于第i行的皇后的列号。先把ColumnIndex的八个数字分别用0-7初始化，接下来我们要做的事情就是对数组ColumnIndex做全排列。由于我们是用不同的数字初始化数组中的数字，因此任意两个皇后肯定不同列。我们只需要判断得到的每一个排列对应的八个皇后是不是在同一对角斜线上，也就是数组的两个下标i和j，是不是i-j==ColumnIndex[i]-Column[j]或者j-i==ColumnIndex[i]-ColumnIndex[j]。

### 实现

转载自参考链接1

```cpp
#include<iostream>  
using namespace std;  
  
int g_number = 0;  
void Permutation(int * , int  , int );  
void Print(int * , int );  
  
void EightQueen( )  
{  
    const int queens = 8;  
    int ColumnIndex[queens];  
    for(int i = 0 ; i < queens ; ++i)  
        ColumnIndex[i] = i;    //初始化  
    Permutation(ColumnIndex , queens , 0);  
}  
  
bool Check(int ColumnIndex[] , int length)  
{  
    int i,j;  
    for(i = 0 ; i < length; ++i)  
    {  
        for(j = i + 1 ; j < length; ++j)  
        {  
            if( i - j == ColumnIndex[i] - ColumnIndex[j] || j - i == ColumnIndex[i] - ColumnIndex[j])   //在正、副对角线上  
                return false;  
        }  
    }  
    return true;  
}  
void Permutation(int ColumnIndex[] , int length , int index)  
{  
    if(index == length)  
    {  
        if( Check(ColumnIndex , length) )   //检测棋盘当前的状态是否合法  
        {  
            ++g_number;  
            Print(ColumnIndex , length);  
        }  
    }  
    else  
    {  
        for(int i = index ; i < length; ++i)   //全排列  
        {  
            swap(ColumnIndex[index] , ColumnIndex[i]);  
            Permutation(ColumnIndex , length , index + 1);  
            swap(ColumnIndex[index] , ColumnIndex[i]);  
        }  
    }  
}  
  
void Print(int ColumnIndex[] , int length)  
{  
    printf("%d\n",g_number);  
    for(int i = 0 ; i < length; ++i)  
        printf("%d ",ColumnIndex[i]);  
    printf("\n");  
}  
  
int main(void)  
{  
    EightQueen();  
    return 0;  
}  
``` 
## 题目4
输入两个整数n和m，从数列1,2,3...n中随意取几个数，使其和等于m，要求列出所有的组合。

### 思路
1. 首先判断，如果n>m,则n中大于m的数不可能参与组合，此时置n=m； 
2. 将最大的数n加入且n==m，则满足条件，输出； 
3. 将n分两种情况求解：n没有加入，取n=n-1,m=m,递归； 
4. n加入，取n=n-1,m=m-n,递归。
5. 终止条件是n<=0，以及sum<=0(sum<=0说明在上一次递归调用是减的n（相对于当前应该为n+1）是减多了，为负

### 实现

```cpp
#include <iostream>  
#include <list>  
using namespace std;  
list<int> list1;  
void find_factor(int sum,int n)  
{  
    //递归出口  
    if(n<=0||sum<=0)  
        return;  
    //输出找到的数  
    if(sum==n)  
    {  
        list1.reverse();  
        for(list<int>::iterator iter=list1.begin();iter!=list1.end();iter++)  
            cout<<*iter<<"+";  
        cout<<n<<endl;  
        list1.reverse();  
    }  
    list1.push_front(n);  
    find_factor(sum-n,n-1);//n放在里面  
    list1.pop_front();  
    find_factor(sum,n-1);//n不放在里面  
}  
  
int main(void)  
{  
    int sum,n;  
    cin>>sum>>n;  
    cout<<"所有可能的序列，如下："<<endl;  
    find_factor(sum,n);  
    return 0;  
}  
``` 
[url]:https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

## 参考资料
1. http://blog.csdn.net/hackbuteer1/article/details/7462447