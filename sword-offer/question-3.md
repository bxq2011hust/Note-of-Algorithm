## 面试题3 [赋值运算符][url1]

<!-- TOC -->

- [面试题3 [赋值运算符][url1]](#面试题3-赋值运算符url1)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)
    - [牛客网](#牛客网)

<!-- /TOC -->

## 题目
在一个二维数组中，每一行都按照从左到右递增的顺序排列，每一列都按照从上到下递增的顺序排列。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

### 思路
从二维数组的右上角或者左下角开始查找，假设从右上角`arr[row][col]`开始查找，则当查找元素`target`大于该值，则`row`这一行可以排除，如果`target`小于该值，则`col`这一列可以排除，否则相等返回结果。

### 实现
```cpp
bool find(int *mat, int rows, int cols, int target)
{
    if (mat == NULL || rows < 1 || cols < 1)
        return false;
    int row = 0, col = cols - 1;
    while (row < rows && col >= 0)
    {
        if (mat[row * cols + col] < target)
            ++row;
        else if (mat[row * cols + col] > target)
            --col;
        else
            return true;
    }
    return false;
}

```

### 牛客网
```cpp
class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        if (array.size() == 0)
            return false;
        int row = 0;
        int col = array[0].size() - 1;
        while (row < array.size() && col >= 0)
        {
            if (array[row][col] < target)
                ++row;
            else if (array[row][col] > target)
                --col;
            else
                return true;
        }

        return false;
    }
};
``` 
[url1]:https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
