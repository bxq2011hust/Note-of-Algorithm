# 191 [计算比特位为1的个数](https://leetcode.com/problems/number-of-1-bits/#/description)

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i=0;
        while(n!=0)
        {
            ++i;
            n&=(n-1);
        }
        return i;
    }
};
```

```cpp
// 平行算法
int BitCount(unsigned int n) {
     
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
 
        return n;
}
```