// question link : https : // leetcode.com/problems/binary-tree-cameras/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int minCamera = 0;

    // Returns:
    //  1 -> needs camera
    //  0 -> covered
    // -1 -> has camera
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 1 || right == 1)
        {
            minCamera++;
            return -1; // install camera here
        }

        if (left == -1 || right == -1)
        {
            return 0; // this node is covered
        }

        return 1; // this node needs a camera
    }

    int minCameraCover(TreeNode *root)
    {
        if (dfs(root) == 1)
        {
            minCamera++; // place camera at root if needed
        }
        return minCamera;
    }
};

// Helper function to build a sample tree
TreeNode *buildTestTree()
{
    // Example tree:
    //      0
    //     / \
    //    0   0
    //       / \
    //      0   0
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);
    return root;
}

int main()
{
    Solution sol;
    TreeNode *root = buildTestTree();

    int result = sol.minCameraCover(root);
    cout << "Minimum number of cameras needed: " << result << endl;

    return 0;
}
