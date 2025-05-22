// Question link : https : // leetcode.com/problems/maximum-product-of-splitted-binary-tree/

#include <iostream>
                        using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int MOD = 1e9 + 7;

class Solution
{
    // approach:
    // find total sum
    // check for every subtree sum
    // store product val as subsum*(totalsum-subsum)
    // keep maxsum updated and return;

    long totalSum = 0;
    long maxProd = 0;

    // total sum
    long getTotalSum(TreeNode *root)
    {
        if (!root)
            return 0;
        return (root->val + getTotalSum(root->left) + getTotalSum(root->right));
    }

    // subtree check
    long subTreeSum(TreeNode *root)
    {
        if (!root)
            return 0;

        long leftSum = subTreeSum(root->left);
        long rightSum = subTreeSum(root->right);

        long subtreeSum = leftSum + rightSum + root->val;

        maxProd = max(maxProd, subtreeSum * (totalSum - subtreeSum));

        return subtreeSum;
    }

public:
    int maxProduct(TreeNode *root)
    {
        totalSum = getTotalSum(root);
        subTreeSum(root);
        return maxProd % MOD;
    }
};

// Sample tree builder (for testing)
TreeNode *buildSampleTree()
{
    // Example tree:
    //       1
    //      / \
    //     2   3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();
    Solution sol;
    int result = sol.maxProduct(root);
    cout << "Maximum product of subtree sums is: " << result << endl;
    return 0;
}
