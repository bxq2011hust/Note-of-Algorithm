## 面试题35 第一个只出现一次的字符

<!-- TOC -->

- [面试题35 第一个只出现一次的字符](#面试题35-第一个只出现一次的字符)
- [[题目][url]](#题目url)
    - [思路1](#思路1)
    - [实现](#实现)

<!-- /TOC -->

## [题目][url]
在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置

### 思路1
1. 两个unordered_map分别存储出现一次和一次以上的字符
2. 遍历字符串，如果字符存在于multi则处理下一个，如果存在于once则将其移入multi，否则将其加入once，并记录其下标加1(为了与map的0区分)
3. 遍历once，找到最小的下标值，返回下标值-1
4. unordered_map是哈希实现，查找、插入、删除时间复杂度为O(1)，所以总体时间复杂度为O(n)


### 实现

```cpp
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
		unordered_map<char,int> once,multi;
        for(int i=0;i<str.size();++i)
        {
            if(multi[str[i]]>0) continue;
            if(once[str[i]]>0)
            {
                multi[str[i]]=once[str[i]];
                once.erase(str[i]);
                continue;
            }
            once[str[i]]=i+1;
        }
        int res=str.size()-1;
        for(auto kv:once)
            if(kv.second<=res) res=kv.second-1;
        return res;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
