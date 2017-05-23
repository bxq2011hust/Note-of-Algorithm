## 面试题18 树的子结构

<!-- TOC -->

- [面试题18 树的子结构](#面试题18-树的子结构)
- [[题目1][url]](#题目1url)
    - [思路](#思路)
    - [实现-牛客网](#实现-牛客网)

<!-- /TOC -->

## [题目1][url]
输入两棵二叉树A和B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

### 思路
1. 如果`root1`和`root2`有一个为`NULL`则直接返回`false`，因为空树不是任意一个树的子结构
2. 如果`root1`和`root2`的值相等，则调用`isSubTree`判断`root2`是不是`root1`的子树
3. 如果2的返回值为false，则递归`HasSubtree`判断`root1->left`与`root2`
4. 如果3的返回值为false，则递归`HasSubtree`判断`root1->right`与`root2`

其中`isSubTree`也通过递归实现，如果两个节点值不想等，则以`root1`和`root2`为根的两个子树肯定不具有相同节点；如果相同则判断左右节点的值是否相等；递归退的条件是到达`root1`或`root2`的叶子结点，如果先到达`root2`的叶子结点则表明都相同，否则`root1`的深度比`root2`浅，返回`false`

### 实现-牛客网

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
    bool isSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return isSubTree(pRoot1->left, pRoot2->left) && isSubTree(pRoot1->right, pRoot2->right);
    }
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        bool isSame = false;
        if (pRoot1->val == pRoot2->val)
            isSame = isSubTree(pRoot1, pRoot2);

        if (!isSame)
            isSame = HasSubtree(pRoot1->left, pRoot2);
        if (!isSame)
            isSame = HasSubtree(pRoot1->right, pRoot2);
        return isSame;
    }
};
``` 

[url]:https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking