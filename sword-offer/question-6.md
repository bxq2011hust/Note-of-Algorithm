## 面试题6 重建二叉树

<!-- TOC -->

- [面试题6 重建二叉树](#面试题6-重建二叉树)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)
    - [牛客网](#牛客网)

<!-- /TOC -->

## 题目
根据二叉树的前序和中序遍历，重建二叉树，遍历中不包含重复数字。

### 思路
1. 前序的第一个节点是根节点，根据根节点在中序中可以得到左右子树
2. 构造根节点，递归构造左右子树，直到前序遍历长度为1

### 实现
```cpp
TreeNode *reConstructBT(int *pre, int *vin, int len)
{
    if (pre == NULL || vin == NULL || len < 1)
        return NULL;
    TreeNode *root = new TreeNode(pre[0]);
    if (len == 1)
        return root;
    if (len >= 2)
    {
        int rootIndex = -1;
        for (int i = 0; i < len; ++i)
        {
            if (vin[i] == root->value)
            {
                rootIndex = i;
                break;
            }
        }
        if (rootIndex == -1)
            throw "Invalid input.";

        // 重建左子树
        int leftLen = rootIndex;
        int *lPre = pre + 1;
        int *lVin = vin;
        root->left = reConstructBT(lPre, lVin, leftLen);
        // 重建右子树 -1是去掉根节点
        int rightLen = len - leftLen - 1;
        int *rPre = pre + 1 + leftLen;
        int *rVin = vin + leftLen + 1;
        root->right = reConstructBT(rPre, rVin, rightLen);
    }
    return root;
}

``` 
### 牛客网
```cpp
class Solution
{
  public:
	TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (!pre.size() || !vin.size())
			return NULL;
		if (pre.size() != vin.size())
			return NULL;
		int len = pre.size();
		TreeNode *root = new TreeNode(pre[0]);
		if (len == 1)
			return root;
		if (len >= 2)
		{
			auto rootIndex = find(vin.begin(), vin.end(), pre[0]);
			auto sublen = rootIndex - vin.begin();
			vector<int> leftSubPre, leftSubVin, rightSubPre, rightSubVin;
			//left node
			copy(++pre.begin(), pre.begin() + sublen + 1, back_inserter(leftSubPre));
			copy(vin.begin(), vin.begin() + sublen, back_inserter(leftSubVin));
			root->left = reConstructBinaryTree(leftSubPre, leftSubVin);
			//right node
			copy(pre.begin() + sublen + 1, pre.end(), back_inserter(rightSubPre));
			copy(vin.begin() + sublen + 1, vin.end(), back_inserter(rightSubVin));
			root->right = reConstructBinaryTree(rightSubPre, rightSubVin);
		}
		return root;
	}
};
``` 

