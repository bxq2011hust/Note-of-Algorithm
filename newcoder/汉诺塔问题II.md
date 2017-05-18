## [汉诺塔问题II][url1]
<!-- TOC -->

- [[汉诺塔问题II][url1]](#汉诺塔问题iiurl1)
    - [问题](#问题)
    - [测试样例](#测试样例)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->
### 问题
有一个int数组arr其中只含有1、2和3，分别代表所有圆盘目前的状态，1代表左柱，2代表中柱，3代表右柱，arr[i]的值代表第i+1个圆盘的位置。比如，arr=[3,3,2,1]，代表第1个圆盘在右柱上、第2个圆盘在右柱上、第3个圆盘在中柱上、第4个圆盘在左柱上。如果arr代表的状态是最优移动轨迹过程中出现的状态，返回arr这种状态是最优移动轨迹中的第几个状态。如果arr代表的状态不是最优移动轨迹过程中出现的状态，则返回-1。
给定一个int数组arr及数组的大小n，含义如题所述，请返回一个int，代表所求的结果。

### 测试样例
```cpp
[3,3]
返回：3
```
### 思路

**递归实现**：

1. 从最后往前推，process(arr,i,from,pass,to)表示前`i`个塔移动到和arr一样时需要的步数
2. from表示i当前所处的位置，to表示i最终要到达的位置
3. 如果arr[i-1]==pass，则不存在该路径
4. 如果arr[i-1]==from，则i不需要移动，此时前i-1个盘子应该在pass，返回前i-1个移动到pass过程需要的步数
5. 如果arr[i-1]==to，则k移动到to需要1<<k-1步，此时前i-1个盘子应该在pass，然后加上将i-1个盘子移动到to的步数
（k移动到to，首先将k-1移动到pass需要`2^(k-1)-1`，然后将k从from移动到to需要1步，一共是`2^(k-1)`）

### 实现
```cpp
class Hanoi
{
  public:
    int process(vector<int> arr, int i, int from, int pass, int to)
    {
        if (i == 1)
        {
            if(arr[i-1]==from) return 0;            
            if(arr[i-1]==to) return 1;
            return -1;
        }
		if(arr[i-1]==pass) return -1;
        else if(arr[i-1]==from) return process(arr,i-1,from,to,pass);
        else
        {
            int tmp=process(arr,i-1,pass,from,to);
            if(tmp==-1) return -1;
            return (1<<(i-1))+tmp;
        }
    }

    int chkStep(vector<int> arr, int n)
    {
        if(arr.empty()||n<=0)  
            return -1;  
        // 递归实现
        //return process(arr, n, 1, 2, 3);

        //非递归实现
        int from=1,pass=2,to=3;  
        int rest=0,tmp=0;  
        while(n>=1){  
            if(arr[n-1]==pass)  
                return -1;  
            if(arr[n-1]==to){  
                rest+=1<<(n-1);  
                tmp=from;  
                from=pass;  
            }  
            else{  
                tmp=to;  
                to=pass;  
            }  
            pass=tmp;  
            n--;  
        }  
        return rest; 
    }
};
```

[url1]:https://www.nowcoder.com/practice/b2d552cd60b7415fad2612a32e799812?tpId=49&&tqId=29342&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

