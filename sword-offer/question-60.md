## 面试题60 把二叉树打印成多行

<!-- TOC -->

- [面试题60 把二叉树打印成多行](#面试题60-把二叉树打印成多行)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。[牛客网地址][url]

### 思路
1. 按层遍历二叉树
2. 记录当前层节点数和下一层节点数
 
### 实现

```cpp
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
  public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> result;
        if (pRoot == NULL)
            return result;
        vector<int> line;
        queue<TreeNode *> q;
        q.push(pRoot);
        int toBeAdd = 1;
        int nextLevel = 0;
        while (!q.empty())
        {
            TreeNode *pNode = q.front();
            line.push_back(pNode->val);
            if (pNode->left != NULL)
            {
                q.push(pNode->left);
                ++nextLevel;
            }
            if (pNode->right != NULL)
            {
                q.push(pNode->right);
                ++nextLevel;
            }
            q.pop();
            --toBeAdd;
            if (toBeAdd == 0)
            {
                result.push_back(line);
                line.clear();
                toBeAdd = nextLevel;
                nextLevel = 0;
            }
        }
        return result;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking