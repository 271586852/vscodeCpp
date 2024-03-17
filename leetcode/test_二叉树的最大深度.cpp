#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int n = 0;
        depth(root, n);
        return n;
    }

    void depth(TreeNode* root, int& n) {
        if (root == nullptr) {
            return;
        }
        int leftDepth = 0;
        int rightDepth = 0;
        depth(root->left, leftDepth);
        depth(root->right, rightDepth);
        n = std::max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    // Test case 1: Empty tree
    Solution sol;
    TreeNode* root1 = nullptr;
    int result1 = sol.maxDepth(root1);
    std::cout << "Test case 1: " << result1 << std::endl;

    // Test case 2: Tree with one node
    TreeNode* root2 = new TreeNode(1);
    int result2 = sol.maxDepth(root2);
    std::cout << "Test case 2: " << result2 << std::endl;

    // Test case 3: Tree with multiple nodes
    TreeNode* root3 = new TreeNode(3);
    root3->left = new TreeNode(9);
    root3->right = new TreeNode(20);
    root3->right->left = new TreeNode(15);
    root3->right->right = new TreeNode(7);
    int result3 = sol.maxDepth(root3);
    std::cout << "Test case 3: " << result3 << std::endl;

    return 0;
}