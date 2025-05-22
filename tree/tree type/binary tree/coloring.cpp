// question link: https://leetcode.com/problems/binary-tree-coloring-game/

#include<bits/stdc++.h>

using namespace std;

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
    TreeNode *findNode(TreeNode *root, int x)
    {
        if (!root)
            return nullptr;
        if (root->val == x)
            return root;

        TreeNode *left = findNode(root->left, x);
        if (left)
            return left;

        return findNode(root->right, x);
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        TreeNode *node = findNode(root, x);

        int left = countNodes(node->left);
        int right = countNodes(node->right);
        int parent = n - (left + right + 1);

        return max({left, right, parent}) > n / 2;
    }
};

// Sample binary tree:
//         1
//       /   \
//      2     3
//     / \
//    4   5

TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main()
{
    Solution sol;
    TreeNode *root = buildSampleTree();

    int n = 5; // Total nodes
    int x = 2; // First player chooses node with value 2

    if (sol.btreeGameWinningMove(root, n, x))
    {
        cout << "Player 2 can win the game.\n";
    }
    else
    {
        cout << "Player 2 cannot win the game.\n";
    }

    return 0;
}
