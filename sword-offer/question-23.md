## 面试题23 从上往下打印二叉树

<!-- TOC -->

- [面试题23 从上往下打印二叉树](#面试题23-从上往下打印二叉树)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

### 思路
1. 实际是按层遍历二叉树
2. 将头节点加入队列q
3. 如果队列不为空，出队，然后将出队节点的非空子节点加入队列

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
class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *tmp;
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            res.push_back(tmp->val);
            if (tmp->left != NULL)
                q.push(tmp->left);
            if (tmp->right != NULL)
                q.push(tmp->right);
        }
        return res;
    }
};
``` 

[url]:https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking