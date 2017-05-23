## 面试题19 二叉树的镜像

<!-- TOC -->

- [面试题19 二叉树的镜像](#面试题19-二叉树的镜像)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
操作给定的二叉树，将其变换为源二叉树的镜像。 

### 思路
1. 如果`root==NULL`返回
2. 对左子树求镜像
3. 对右子树求镜像
4. 交换左右子树

非递归时，则可以借助先序遍历二叉树的非递归实现

### 实现


- 递归实现

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
class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
    }
};
``` 

- 非递归实现
```cpp
class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return;
        TreeNode *node = pRoot, *tmp = NULL;
        stack<TreeNode *> s;
        while (node != NULL || !s.empty())
        {
            while (node != NULL)
            {
                tmp = node->left;
                node->left = node->right;
                node->right = tmp;
                s.push(node);
                node = node->left;
            }
            if (!s.empty())
            {
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
    }
};
```

[url]:https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking