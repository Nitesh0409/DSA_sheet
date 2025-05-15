#include<bits/stdc++.h>

using namespace std;

/*
            1
           / \
          2   3
         / \   \
        4   5   6
*/

//will do in stack version later...

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Traversal{
public: 

    void inOrder(TreeNode * root){
        if(root == nullptr){
            return;
        }

        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }



    void preOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }



    void postOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }


    void levelOrder(TreeNode * root){

        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val<< " ";
            if(node->left !=  nullptr ) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }

    vector<vector<int>>  zigzag(TreeNode * root){
        vector<vector<int>> result;

        bool leftToRight = true;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();

                int idx = leftToRight ? i : (size - 1 - i);
                level[idx] = node->val;

                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }

            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};



int main(){
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Traversal trv;

    cout << "Inorder: ";
    trv.inOrder(root);

    cout << "\nPreorder: ";
    trv.preOrder(root);

    cout << "\nPostorder: ";
    trv.postOrder(root);

    cout << "\nLevel Order: ";
    trv.levelOrder(root);
    cout << endl;

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