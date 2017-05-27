## 面试题34 丑数

<!-- TOC -->

- [面试题34 丑数](#面试题34-丑数)
- [[题目][url]](#题目url)
    - [思路1](#思路1)
    - [思路2](#思路2)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

### 思路1
1. 可以直接判断每个数依次对2，3，5取余是否都为0

### 思路2
1. 从1开始保存每个丑数
2. 存在一个丑数T2，使得`T2*2`大于当前最大的丑数，而T2之前的丑数乘2小于等于当前最大的丑数，类似也存在T3，T5使得`T3*3`和`T5*5`大于当前最大丑数
3. 从1开始每次选择`T2*2 T3*3 T5*5`三个数中的最小值作为新的丑数，然后更新`T2 T3 T5`

### 实现

```cpp
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index<1) return 0;
        vector<int> res(index,1);
        vector<int>::iterator pMulti2=res.begin();
        vector<int>::iterator pMulti3=res.begin();
        vector<int>::iterator pMulti5=res.begin();
		int tmp2=2,tmp3=3,tmp5=5;
        for(int i=1;i<index;++i)
        {
            res[i]=min(min(tmp2,tmp3),tmp5);
            while(tmp2<=res[i])
            {
                ++pMulti2;
                tmp2=*pMulti2*2;
            }
             while(tmp3<=res[i])
            {
                ++pMulti3;
                tmp3=*pMulti3*3;
            }
             while(tmp5<=res[i])
            {
                ++pMulti5;
                tmp5=*pMulti5*5;
            }
        }
        return res.back();
    }
};
``` 
[url]:https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
