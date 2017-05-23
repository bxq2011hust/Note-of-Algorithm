## 面试题20 顺时针打印矩阵

<!-- TOC -->

- [面试题20 顺时针打印矩阵](#面试题20-顺时针打印矩阵)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10. 

### 思路
1. 每次打印顺时针一圈，每次开始打印的起点`start`是对角线元素，如果`strt*2`不小于矩阵的宽或高，则打印完成
2. 打印一圈分为四步，第一行，最后一列，最后一行，第一列，其中第一行必定打印，后面三个可能退化，需要逐步判断


### 实现

```cpp
class Solution
{
  public:
    void printItem(vector<vector<int>> matrix, int start, vector<int> &res)
    {
        if (matrix.empty() || matrix[0].empty())
            return;
        int row = matrix.size(), col = matrix[0].size();
        int endX = col - 1 - start;
        int endY = row - 1 - start;
        // 第一行
        for (int i = start; i <= endX; ++i)
            res.push_back(matrix[start][i]);
        // 最后一列
        if (endY > start)
            for (int i = start + 1; i <= endY; ++i)
                res.push_back(matrix[i][endX]);
        // 最后一行
        if (endY > start && start < endX)
            for (int i = endX - 1; i >= start; --i)
                res.push_back(matrix[endY][i]);
        // 第一列 至少要是3行2列
        if (endY - 1 > start && start < endX)
            for (int i = endY - 1; i > start; --i)
                res.push_back(matrix[i][start]);
    }
    
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;
        int row = matrix.size(), col = matrix[0].size();
        int start = 0;
        while (row > start * 2 && col > start * 2)
        {
            printItem(matrix, start, res);
            ++start;
        }
        return res;
    }
};
``` 


[url]:https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking