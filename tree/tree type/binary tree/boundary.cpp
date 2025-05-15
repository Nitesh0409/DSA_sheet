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

    bool isLeaf(TreeNode* root){
        return (!root->left && !root->right);
    }

    void addLeft(TreeNode *root, vector<int>& res){
        TreeNode* node = root->left;

        while(node){
            if(!isLeaf(node))
                res.push_back(node->val);
            if(node->left)
                node = node->left;
            else
                node = node->right;
        }
    }

    void addLeaf(TreeNode *root, vector<int> &res){
        if (!root)
            return;

        if(isLeaf(root)){
            res.push_back(root->val);
            return;
        }

        if(root->left) addLeaf(root->left, res);
        if(root->right) addLeaf(root->right, res);
    }

    void addRight(TreeNode* root , vector<int>& res){
        TreeNode *node = root->right;
        vector<int> temp;
        while(node){
            if(!isLeaf(node))
                temp.push_back(node->val);
            
            if(node->right)
                node = node->right;
            else
                node = node->left;
        }

        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }


    vector<int> boundary(TreeNode * root){
        vector<int> result;

        if(!root)
            return result;

        if(!isLeaf(root))
            result.push_back(root->val);

        addLeft(root, result);
        addLeaf(root, result);
        addRight(root, result);

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

    vector<int> result = trv.boundary(root);

    cout << "\n boundary Order Traversal: \n";
    for(int i: result){
        cout << i << " ";
    }
    return 0;
}