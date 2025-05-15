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
    vector<int> vertical(TreeNode *root)
    {
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            auto [node, col] = q.front();
            q.pop();

            if(mp.find(col) ==mp.end())
            { // to allow only first val;
                mp[col] = node->val;
            }

            if(node->left)
                q.push({node->left, col - 1});

            if(node->right)
                q.push({node->right, col + 1});
        }

        vector<int> result;
        for(auto& [col, val]: mp){
            result.push_back(val);
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

    vector<int> result = trv.vertical(root);

    cout << "\n top view traversal : " << endl;

        for (int val : result)
        {
            cout << val << " ";
        }
        cout << endl;

    return 0;
}