## 面试题62 序列化二叉树

<!-- TOC -->

- [面试题62 序列化二叉树](#面试题62-序列化二叉树)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

请实现两个函数，分别用来序列化和反序列化二叉树。[牛客网地址][url]

### 思路
1. 序列化实现，如果有值则将值转为字符串，为空则输入'$'表示空节点，使用`,`分割每个节点
2. 反序列化，依次读入每个节点，如果节点有值，则转为数字，创建新节点，直到字符串结尾

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
    void SerializeCore(TreeNode *root, string &str)
    {
        if (root == NULL)
        {
            str += "$,";
            return;
        }
        str += to_string(root->val) + ",";
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }
    char *Serialize(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        string str;
        SerializeCore(root, str);
        char *p = new char[str.size() + 1];
        memcpy(p, str.data(), str.size() + 1);
        return p;
    }
    bool ReadNode(char **str, int &number)
    {
        if (str == NULL || *str == NULL || *str == '\0')
            return false;
        string s;
        while (**str != '\0' && **str != ',')
        {
            if (**str == '$')
            {
                (*str) += 2;
                return false;
            }
            else
                s += **str;
            (*str)++;
        }
        if (**str == ',')
            (*str)++;
        number = stoi(s, nullptr, 10);
        return true;
    }
    TreeNode *DeserializeCore(char **str)
    {
        if (str == NULL || *str == NULL || **str == '\0')
            return NULL;
        int number;
        TreeNode *root = NULL;
        if (ReadNode(str, number))
        {
            root = new TreeNode(number);
            root->left = DeserializeCore(str);
            root->right = DeserializeCore(str);
        }
        return root;
    }
    TreeNode *Deserialize(char *str)
    {
        char *p = str;
        TreeNode *root = DeserializeCore(&p);
        delete[] str;
        return root;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
