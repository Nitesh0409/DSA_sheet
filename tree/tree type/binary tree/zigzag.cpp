#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Traversal
{
public:
    vector<vector<int>> zigzag(TreeNode *root)
    {
        vector<vector<int>> result;

        bool leftToRight = true;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int idx = leftToRight ? i : (size - 1 - i);
                level[idx] = node->val;

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            leftToRight = !leftToRight;
            result.push_back(level);
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

    Traversal trv;

    vector<vector<int>> result = trv.zigzag(root);

    cout << "\nZigzag Level Order Traversal: \n";
    for (auto &level : result)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}