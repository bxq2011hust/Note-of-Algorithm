## 面试题63 二叉搜索树的第k个结点

<!-- TOC -->

- [面试题63 二叉搜索树的第k个结点](#面试题63-二叉搜索树的第k个结点)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

给定一颗二叉搜索树，请找出其中的第k大的结点。[牛客网地址][url]

### 思路
1. 中序遍历二叉树，非递归实现
2. 入栈`node`，将`node`赋值为其左孩子，如果左孩子不为空重复步骤2
3. `node`左孩子为空，取栈顶元素、出栈并访问栈顶元素，然后将`node`赋值为栈顶元素的右孩子，重复步骤2，直到`node`为空且栈为空，则遍历结束。

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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL || k < 1)
            return NULL;
        stack<TreeNode *> s;
        TreeNode *pNode = pRoot;
        while (pNode != NULL || !s.empty())
        {
            while (pNode != NULL)
            {
                s.push(pNode);
                pNode = pNode->left;
            }
            if (!s.empty())
            {
                pNode = s.top();
                --k;
                if (k == 0)
                    return pNode;
                s.pop();
                pNode = pNode->right;
            }
        }
        return NULL;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
