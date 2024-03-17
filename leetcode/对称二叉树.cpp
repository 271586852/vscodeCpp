#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 解法一：递归
class Solution
{
public:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};

// 解法二：迭代
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return false;
        }
        vector<int> m;
        vector<int> n;
        TreeNode *p = root;
        TreeNode *q = root;

        while (p->left != NULL || q->right != NULL)
        {

            if (p->left != NULL)
            {
                if (q->right != NULL)
                {
                    m.push_back(p->left->val);
                    n.push_back(q->right->val);
                }
                else
                {
                    return false;
                }
            }

            if (p->right != NULL)
            {
                if (q->left != NULL)
                {
                    m.push_back(p->right->val);
                    n.push_back(q->left->val);
                }
                else
                {
                    return false;
                }
            }
        }

        if (m != n)
        {
            return false;
        }
        return true;
    }
};

// 解法三：迭代
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};