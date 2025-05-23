// quesstion link : https : // leetcode.com/problems/recover-binary-search-tree/


//more optimization can be possible by using morris traversal ...will write later
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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = new TreeNode(INT_MIN);

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);

        if (prev && prev->val > root->val)
        {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (first && second)
        {
            swap(first->val, second->val);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution s;
    s.recoverTree(root);

    return 0;
}
