#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
algorithm:
    push in queue;
    then pop out them
    and put its left and right in queue
    if flag true then put in i order
    other wise size - 1-i; 

*/

class Traversal
{
public:
    vector<vector<int>> vertical(TreeNode* root){
        //approach done by simply modification of level order traversal

        /*col: {
            {row1: val1, val2, val1},
            {row2: val3,val 2}
        }
        */
       //basically => col will be in sorted and cannot have duplicate values...but row can have duplicate values.
        map<int, map<int, multiset<int>>> mp;

        // queue store tupple for node, row, col;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while(!q.empty()){
            auto [node, col, row] = q.front();
            q.pop();

            if(node){
                mp[col][row].insert(node->val);
                q.push({node->left, col - 1, row + 1});
                q.push({node->right, col + 1, row + 1});
            }
        }

        vector<vector<int>> result;
        for(auto& [col,rows]: mp){
            vector<int> colVal;
            for(auto& [row, vals] : rows){
                colVal.insert(colVal.end(), vals.begin(), vals.end());
            }
            result.push_back(colVal);
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
    
    vector<vector<int>> result = trv.vertical(root);

    cout << "\n vertical traversal : " << endl;
    for(auto& col : result){
        for(int val: col){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}