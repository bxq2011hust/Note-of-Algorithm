## 面试题39 二叉树的深度 & 平衡二叉树

<!-- TOC -->

- [面试题39 二叉树的深度 & 平衡二叉树](#面试题39-二叉树的深度--平衡二叉树)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)
- [题目2](#题目2)
    - [思路1](#思路1)

<!-- /TOC -->

## 题目1

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。[牛客网地址][url]

### 思路
1. 使用递归解决问题
2. 如果根节点为NULL返回0，否则返回左右子树深度的最大值加1

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
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==NULL) return 0;
        int ldeepth=TreeDepth(pRoot->left);
        int rdeepth=TreeDepth(pRoot->right);
        return max(ldeepth,rdeepth)+1;
    }
};
``` 

## 题目2
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某棵二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。[牛客网地址][url2]

### 思路1
1. 使用递归解决问题，在遍历到每一个节点之前已经遍历了他的左右子树，只需要在遍历每个节点的事后记录它的深度

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
    bool isBalanced(TreeNode *root, int &depth)
    {
        if (root == NULL)
        {
            depth = 0;
            return true;
        }
        int left, right;
        bool isLeftBalance = isBalanced(root->left, left);
        bool isRightBalance = isBalanced(root->right, right);
        depth = max(left, right) + 1;
        if (isLeftBalance && isRightBalance)
        {
            int diff = left - right;
            if (diff >= -1 && diff <= 1)
                return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int depth = 0;
        return isBalanced(pRoot, depth);
    }
};
``` 


[url]:https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
[url2]:https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking