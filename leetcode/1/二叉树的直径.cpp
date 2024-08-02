
#include <algorithm>

//递归思路

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    int ans;

    int depth(TreeNode* rt){
        if(rt == NULL){
            return 0;
        }
        int L = depth(rt->left);
        int R = depth(rt->right);
        ans = std::max(ans, L+ R +1);
        return std::max(L,R) + 1;
    }


public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};