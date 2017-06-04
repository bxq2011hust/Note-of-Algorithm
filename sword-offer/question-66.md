## 面试题66 矩阵中的路径

<!-- TOC -->

- [面试题66 矩阵中的路径](#面试题66-矩阵中的路径)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。[牛客网地址][url]

### 思路
1. 定义一个矩阵存储路径是否访问过，然后使用回溯法
2. 假设矩阵中某个格子的字符是ch，且这个格子对应于路径上的第i个字符，如果第i个字符不是ch，那么这个格子可能处于第i个位置；如果是相同的，那么往相邻的格子寻找第i+1个字符，重复上述过程，直到路径上所有字符都在矩阵找到相应位置


### 实现

```cpp
class Solution
{
  public:
    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, int &pathLength, bool *visited)
    {
        if (str[pathLength] == '\0')
            return true;
        bool foundPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
        {
            ++pathLength;
            visited[row * cols + col] = true;
            foundPath = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);
            if (!foundPath)
            {
                --pathLength;
                visited[row * cols + col] = false;
            }
        }
        return foundPath;
    }
    
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int pathLength = 0;
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col)
                if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
        delete[] visited;
        return false;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
