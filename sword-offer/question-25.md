## 面试题25 二叉树中和为某一值的路径

<!-- TOC -->

- [面试题25 二叉树中和为某一值的路径](#面试题25-二叉树中和为某一值的路径)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

### 思路
1. 先序遍历二叉树，如果节点是叶节点且累加值等于期望值，则该路径符合条件
2. 如果不是叶节点，分别递归访问非空的左右子树
3. 返回上一层前，将累加和减去当前结点，并从路径中移除当前结点

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
		if(root==NULL) return result;
        
        vector<int> path;
        int sum=0;
        findPath(root,expectNumber,path,sum,result);
        return result;
    }
    void findPath(TreeNode * root,int expectNumber,vector<int> path,int &sum,vector<vector<int> > &res)
        {
        sum+= root->val;
        path.push_back(root->val);
        
        bool isLeaf = root->left==NULL && root->right==NULL;
        if(sum==expectNumber&&isLeaf)
            res.push_back(path);
            
        if(root->left!=NULL) findPath(root->left,expectNumber,path,sum,res);
        if(root->right!=NULL) findPath(root->right,expectNumber,path,sum,res);
		sum-=root->val;
        path.pop_back();
    }
};
``` 

[url]:https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking