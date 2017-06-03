## 面试题61 按之字形顺序打印二叉树

<!-- TOC -->

- [面试题61 按之字形顺序打印二叉树](#面试题61-按之字形顺序打印二叉树)
- [题目](#题目)
    - [思路1](#思路1)
    - [思路2](#思路2)
    - [思路1实现](#思路1实现)

<!-- /TOC -->

## 题目

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。[牛客网地址][url]

### 思路1
1. 按层遍历二叉树
2. 记录当前层节点数和下一层节点数
3. 记录当前层是否是从右往左打印，是则逆转line
### 思路2
1. 按层遍历二叉树
2. 记录当前层节点数和下一层节点数
3. 使用两个栈，一个栈是奇数层，先左后右入栈，另一个是偶数层，先右后左
代码参考[这里][url2]

### 思路1实现

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
        bool RightToLeft = false;
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
                //从右往左
                if (RightToLeft)
                    reverse(line.begin(), line.end());
                result.push_back(line);
                line.clear();
                toBeAdd = nextLevel;
                nextLevel = 0;
                RightToLeft = !RightToLeft;
            }
        }
        return result;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
[url2]:https://github.com/zhedahht/ChineseCodingInterviewAppendix/blob/master/PrintTreesInZigzag/PrintTreesInzigzag.cpp