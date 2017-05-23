## 面试题24 二叉搜索树的后序遍历序列

<!-- TOC -->

- [面试题24 二叉搜索树的后序遍历序列](#面试题24-二叉搜索树的后序遍历序列)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

### 思路
1. 序列的最后一个值是二叉搜索树的根节点，序列前边小于根节点的值是根的左子树，大于根节点的值是右子树
2. 从第一个值开始找到第一个大于根节点`i`的值是右子树的开始，接下来如果有节点小于根节点的值，则违反二叉搜索树的性质，返回`false`
3. 如果`i>0`(序列不止一个节点)，递归处理左子树，如果存在右子树，递归处理右子树


### 实现

```cpp
class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() < 1)
            return false;
        int root = sequence.back();
        int i = 0;
        for (; i < sequence.size() - 1; ++i)
        {
            if (sequence[i] > root)
                break;
        }
        int j = i;
        for (; j < sequence.size() - 1; ++j)
        {
            if (sequence[j] < root)
                return false;
        }
        bool left = true;
        if (i > 0)
            left = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin() + i));
        bool right = true;
        // j不是最有一个节点，即存在右子树
        if (j < sequence.size() - 1)
            right = VerifySquenceOfBST(vector<int>(sequence.begin() + i, sequence.end() - 1));
        return left && right;
    }
};
``` 

[url]:https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking