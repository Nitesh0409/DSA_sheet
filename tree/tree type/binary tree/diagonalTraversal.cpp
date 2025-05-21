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
    /*
     first put val in queue and traversal all right node and put left one in queue
    */

    vector<int> diagonal(TreeNode *root)
    {
        // code here
        vector<int> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            while (curr)
            {
                result.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                curr = curr->right;
            }
        }

        return result;
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

    vector<int> result = sol.diagonal(root);

    for (int val: result){
        cout << val << " ";
    }

    return 0;
}