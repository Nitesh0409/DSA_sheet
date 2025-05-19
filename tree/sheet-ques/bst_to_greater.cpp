// question link:  https: // leetcode.com/problems/convert-bst-to-greater-tree/description/

//love this approach of solving🤩

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void preOrder(TreeNode *root){
        if(!root){
            return;
        }
        preOrder(root->left);
        cout << root->val << " ";
        preOrder(root->right);
    }

    int sum = 0;
    TreeNode* bstToGreater(TreeNode* root){
        if(!root)
            return nullptr;

        bstToGreater(root->right);

        sum += root->val;
        root->val = sum;

        bstToGreater(root->left);

        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;

    sol.preOrder(root);
    cout << endl;
    TreeNode* node = sol.bstToGreater(root);
    sol.preOrder(node);
    cout << endl;

    return 0;
}