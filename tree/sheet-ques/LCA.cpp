// question link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>
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

//recursive approach:
    /*
    go deep as possible till not find p or q
    check in both side left and right if find then
    if one is left other is right return root
    else if one side is not null reture left .
    */

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }


    //but intituitive approach:
    /*
    map parent to every child till we can not find p and q;
    we store all ancestors of p in set
    then we just check for ancestor of q if they exist in ancestor of p;
    */

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){

        //mapping:
        unordered_map<TreeNode *, TreeNode*> parent;
        parent[root] = nullptr;
        stack<TreeNode *> st;
        st.push(root);

        while(parent.count(p) || parent.count(q)){
            TreeNode *node = st.top();
            st.pop();

            if(node->left) {
                parent[node->left] = node;
                st.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                st.push(node->right);
            }
        }

        set<TreeNode *> ancestor;

        // parents of p in set
        while(p){
            ancestor.insert(p);
            p = parent[p];
        }

        // parent of q is same as p
        while(!ancestor.count(q)){
            q = parent[q];
        }

        return q;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    TreeNode *p = root->right;        // Node 2
    TreeNode *q = root->right->right; // Node 3

    Solution sol;
    TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
    {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
