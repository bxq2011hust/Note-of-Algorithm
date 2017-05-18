## [汉诺塔问题I][url1]
<!-- TOC -->

- [[汉诺塔问题I][url1]](#汉诺塔问题iurl1)
    - [问题](#问题)
    - [测试样例](#测试样例)
    - [思路](#思路)
    - [时间复杂度](#时间复杂度)
    - [实现](#实现)

<!-- /TOC -->
### 问题
对于传统的汉诺塔游戏我们做一个拓展，我们有从大到小放置的n个圆盘，开始时所有圆盘都放在左边的柱子上，按照汉诺塔游戏的要求我们要把所有的圆盘都移到右边的柱子上，请实现一个函数打印最优移动轨迹。
给定一个int n，表示有n个圆盘。请返回一个string数组，其中的元素依次为每次移动的描述。描述格式为： move from [left/mid/right] to [left/mid/right]。

### 测试样例
```cpp
1
返回：move from left to right
```
### 思路
1. 如果只有一个盘子，直接移动到`right`
2. 有`n`个盘子，先将`n-1`个盘子移动到`mid`，然后将第`n`个盘子移动到`right`
3. 将`n-1`个盘子从mid借助left移动到`right`

### 时间复杂度

`T(n)=1+2*T(n-1)=2^n-1`

### 实现
```cpp
class Hanoi {
public:
    void hanoi(string A,string B,string C,int n,vector<string>& res)
    {
        if(n==1)
        {
            res.push_back(string("move from ")+A+string(" to ")+C);
        }
        else
            {
            hanoi(A,C,B,n-1,res);
            res.push_back(string("move from ")+A+string(" to ")+C);
            hanoi(B,A,C,n-1,res);
        }
    }
    vector<string> getSolution(int n) {
        string left="left";
        string mid="mid";
        string right="right";
        vector<string> res;
        hanoi(left,mid,right,n,res);
        return res;
    }
};
```

[url1]:https://www.nowcoder.com/practice/7d6cab7d435048c4b05251bf44e9f185?tpId=49&&tqId=29341&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

