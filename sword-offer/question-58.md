## 面试题58 二叉树的下一个结点

<!-- TOC -->

- [面试题58 二叉树的下一个结点](#面试题58-二叉树的下一个结点)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。[牛客网地址][url]

### 思路
1. 如果该节点存在右子节点，那么其右子节点的最后一个左子节点就是下一个节点
2. 如果不存在右子节点，那么遍历寻找其父节点，直到某个节点是其父节点的左子节点，则该节点的父节点是下一个节点
3. 步骤2中，到达根节点退出循环，pNext=pNode->next会指向NULL
 
### 实现

```cpp
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution
{
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == NULL)
            return NULL;
        TreeLinkNode *pNext = NULL;
        // 存在右子节点
        if (pNode->right != NULL)
        {
            pNode = pNode->right;
            while (pNode->left != NULL)
                pNode = pNode->left;
            pNext = pNode;
        }
        // 不存在右子节点，则寻找父节点，直到某个节点是其父节点的左子节点，则其父节点是下一个节点
        else if (pNode->next != NULL)
        {
            while (pNode->next != NULL && pNode->next->left != pNode)
                pNode = pNode->next;

            pNext = pNode->next;
        }

        return pNext;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking