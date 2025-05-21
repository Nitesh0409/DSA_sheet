#include <bits/stdc++.h>

// here i m providing => top, left, right, bottom view of tree..
/*
approach : we have to use vertical traversal algo and just do some modification ..
            so basically need to learn vertical algo in details.
*/

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
    vector<int> topView(TreeNode *root)
    {
        map<int, int> mp;
        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, col] = q.front();
            q.pop();

            if (mp.find(col) == mp.end()) // this condition for only first item
            {
                mp[col] = node->val;
            }

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        vector<int> result;
        for (auto &[col, val] : mp)
        {
            result.push_back(val);
        }

        return result;
    }

    // bottom
    vector<int> bottomView(TreeNode *root)
    {
        map<int, int> mp;
        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, col] = q.front();
            q.pop();

            mp[col] = node->val;

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        vector<int> result;
        for (auto &[col, val] : mp)
        {
            result.push_back(val);
        }

        return result;
    }

    // left side view
    vector<int> leftView(TreeNode *root)
    {
        map<int, int> mp;               // row, value
        queue<pair<TreeNode *, int>> q; // node, row

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, row] = q.front();
            q.pop();

            if (mp.find(row) == mp.end())
            { // to allow only first val;
                mp[row] = node->val;
            }

            if (node->left)
                q.push({node->left, row + 1});

            if (node->right)
                q.push({node->right, row + 1});
        }

        vector<int> result;
        for (auto &[col, val] : mp)
        {
            result.push_back(val);
        }

        return result;
    }

    // right side view
    vector<int> rightView(TreeNode *root)
    {
        if(!root)
            return {};
            
        map<int, int> mp;               // row, value
        queue<pair<TreeNode *, int>> q; // node, row

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, row] = q.front();
            q.pop();

            mp[row] = node->val;

            if (node->left)
                q.push({node->left, row + 1});

            if (node->right)
                q.push({node->right, row + 1});
        }

        vector<int> result;
        for (auto &[col, val] : mp)
        {
            result.push_back(val);
        }

        return result;
    }
};

int main()
{
    /*              1
                   / \
                  2   3
                 / \   \
                4   5   6
                   / \
                  7   8
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    Traversal trv;

    vector<vector<int>> result;
    result.push_back(trv.topView(root));
    result.push_back(trv.bottomView(root));
    result.push_back(trv.leftView(root));
    result.push_back(trv.rightView(root));

    vector<string> Traversal = {"top view: ", "bottom View: ", "left view: ", "right view: "};

    for (int i = 0; i < result.size(); i++)
    {
        cout << Traversal[i];
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}