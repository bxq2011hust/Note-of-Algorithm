## 面试题59 对称的二叉树

<!-- TOC -->

- [面试题59 对称的二叉树](#面试题59-对称的二叉树)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。[牛客网地址][url]

### 思路
1. 遍历比较二叉树，分别比较对称节点
 
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
    bool isSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == NULL && pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return isSymmetrical(pRoot1->left, pRoot2->right) 
            && isSymmetrical(pRoot1->right, pRoot2->left);
    }
    bool isSymmetrical(TreeNode *pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }
};
``` 
[url]:https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking