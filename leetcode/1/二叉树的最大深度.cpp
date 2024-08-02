#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int n =0;
        return depth(root, n);
    }

    int depth(TreeNode *root, int n)
    {
        if (root == nullptr)
        {
            return n;
        }

        int leftDepth = depth(root->left, n + 1);

        int rightDepth = depth(root->right, n + 1);

        return max(leftDepth, rightDepth);
    }
};