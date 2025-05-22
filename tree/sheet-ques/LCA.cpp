// question link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
go deep as possible till not find p or q
check in both side left and right if find then
if one is left other is right return root
else if one side is not null reture left .
*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    TreeNode *p = root->right;        // Node 2
    TreeNode *q = root->right->right; // Node 3

    Solution sol;
    TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
    {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
