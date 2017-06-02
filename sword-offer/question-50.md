## 面试题49 把字符串转换成整数

<!-- TOC -->

- [面试题49 把字符串转换成整数](#面试题49-把字符串转换成整数)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)
- [相关题目](#相关题目)
    - [测试样例](#测试样例)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2](#思路2)
    - [实现2](#实现2)

<!-- /TOC -->

## 题目

输入一棵树(普通的树，可能不是二叉树)的根节点和两个节点，求两个节点的公共祖先，这里结点本身也可认为是其祖先。[牛客网类似题目地址][url]

### 思路
1. 遍历树，求得两个节点的路径
2. 判断路径的最后一个公共节点

### 实现
```cpp
//tree.h
#include <vector>
struct TreeNode 
{
    int                    m_nValue;    
    std::vector<TreeNode*>    m_vChildren;    
};

TreeNode* CreateTreeNode(int value)
{
    TreeNode* pNode = new TreeNode();
    pNode->m_nValue = value;

    return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild)
{
    if(pParent != NULL)
    {
        pParent->m_vChildren.push_back(pChild);
    }
}

void PrintTreeNode(TreeNode* pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d.\n", pNode->m_nValue);

        printf("its children is as the following:\n");
        std::vector<TreeNode*>::iterator i = pNode->m_vChildren.begin();
        while(i < pNode->m_vChildren.end())
        {
            if(*i != NULL)
                printf("%d\t", (*i)->m_nValue);
        }

        printf("\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(TreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        std::vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
        while(i < pRoot->m_vChildren.end())
        {
            PrintTree(*i);
            ++i;
        }
    }
}

void DestroyTree(TreeNode* pRoot)
{
    if(pRoot != NULL)
    {
        std::vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
        while(i < pRoot->m_vChildren.end())
        {
            DestroyTree(*i);
            ++i;
        }

        delete pRoot;
    }
}
```
```cpp
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include <list>
#include "tree.h"
using namespace std;

bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path)
{
    path.push_back(pRoot);
    if(pRoot == pNode)
        return true;
        
    bool found = false;

    vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
    while(!found && i < pRoot->m_vChildren.end())
    {
        found = GetNodePath(*i, pNode, path);
        ++i;
    }
 
    if(!found)
        path.pop_back();
 
    return found;
}

TreeNode *GetLastCommonNode(const list<TreeNode *> &path1, const list<TreeNode *> &path2)
{
    list<TreeNode *>::const_iterator iterator1 = path1.begin();
    list<TreeNode *>::const_iterator iterator2 = path2.begin();

    TreeNode *pLast = NULL;

    while (iterator1 != path1.end() && iterator2 != path2.end())
    {
        if (*iterator1 == *iterator2)
            pLast = *iterator1;
        iterator1++;
        iterator2++;
    }
    return pLast;
}

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2)
{
    if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
        return NULL;
 
    list<TreeNode*> path1;
    GetNodePath(pRoot, pNode1, path1);
 
    list<TreeNode*> path2;
    GetNodePath(pRoot, pNode2, path2);
 
    return GetLastCommonNode(path1, path2);
}

// ====================测试代码====================

void Test(char* testName, TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2, TreeNode* pExpected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if((pExpected == NULL && pResult == NULL) || 
        (pExpected != NULL && pResult != NULL && pResult->m_nValue == pExpected->m_nValue))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test2", pNode1, pNode5, pNode4, pNode4);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    TreeNode* pNode6 = CreateTreeNode(6);

    Test("Test3", pNode1, pNode5, pNode6, NULL);
}

// 输入NULL
void Test4()
{
    Test("Test4", NULL, NULL, NULL, NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
``` 

## 相关题目

有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。[牛客网地址][url]
### 测试样例
2，3 返回：1

### 思路1
1. 类似与上一个题目，求出路径，然后求最后一个公共节点

### 实现1
```cpp
class LCA
{
  public:
    int getLCA(int a, int b)
    {
        if (a < 1 || b < 1)
            return 0;
        list<int> path1, path2;
        while (a > 1)
        {
            path1.push_front(a / 2);
            a /= 2;
        }
        while (b > 1)
        {
            path2.push_front(b / 2);
            b /= 2;
        }
        auto p1 = path1.begin();
        auto p2 = path2.begin();
        int parent = 0;
        while (p1 != path1.end() && p2 != path2.end() && *p1 == *p2)
        {
            parent = *p1;
            ++p1;
            ++p2;
        }
        return parent;
    }
};
```

### 思路2
1. 某一个节点的父节点为a/2，如果输入的两个节点a，b不想等，则将较大的节点变为其父节点
2. 重复步骤1，直到两个节点值相等

### 实现2
```cpp
class LCA
{
  public:
    int getLCA(int a, int b)
    {
        if (a < 1 || b < 1)
            return 0;
        while (a != b)
        {
            if (a > b)
                a /= 2;
            else
                b /= 2;
        }
        return a;
    }
};
```

[url]:https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking