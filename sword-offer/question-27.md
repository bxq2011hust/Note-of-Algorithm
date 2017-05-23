## 面试题27 二叉搜索树与双向链表

<!-- TOC -->

- [面试题27 二叉搜索树与双向链表](#面试题27-二叉搜索树与双向链表)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

### 思路
1. 递归处理，如果根节点为空，则链表的头尾指针都为空
2. 处理左子树，左子树为空，头指针指向`root`节点；否则递归处理左子树，左子树转换的链表的头指针是`root`的头指针，`root->left=leftLast`且`leftLast->right=root`
3. 与第二步类似的方式处理右子树

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
};*/
class Solution {
public:
    void convertToList(TreeNode *root, TreeNode *&first, TreeNode *&last)
    {
        if (root == NULL)
        {
            first = NULL;
            last = NULL;
            return;
        }
        // 递归处理左子树
        TreeNode *leftFirst, *leftLast, *rightFirst, *rightLast;
        if (root->left == NULL)
        {
            first = root;
        }
        else
        {
            convertToList(root->left, leftFirst, leftLast);
            first = leftFirst;
            leftLast->right = root;
            root->left = leftLast;
        }
        // 递归处理右子树
        if (root->right == NULL)
        {
            last = root;
        }
        else
        {
            convertToList(root->right, rightFirst, rightLast);
            last = rightLast;
            root->right = rightFirst;
            rightFirst->left = root;
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        TreeNode *first,*last;
        convertToList(pRootOfTree,first,last);
        return first;

    }
};
``` 

[url]:https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking