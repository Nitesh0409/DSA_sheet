// question link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x) : val(x), left(nullptr), right(nullptr) , next(nullptr) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        /*
            level by level movement from left
            traverse only internal not leaf
            while traversal make next connection

        */

        if (!root)
            return nullptr;

        Node *leftNode = root;

        while (leftNode->left)
        {
            Node *node = leftNode;
            while (node)
            {
                node->left->next = node->right;

                if (node->next)
                {
                    node->right->next = node->next->left;
                }

                node = node->next;
            }
            leftNode = leftNode->left;
        }

        return root;

        /*
        method 2 : this is level order base but not optimal
        */

        // queue<Node*> q;
        // if(!root) return root;
        // else{
        //     q.push(root);
        // }
        // while(!q.empty()){
        //     int size = q.size();
        //     Node* temp = nullptr;
        //     for(int i = 0; i < size; i++){
        //         Node* node = q.front();
        //         q.pop();
        //         if(temp) temp->next = node;
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //         temp = node;
        //     }
        // }
        // return root;
    }

    void preOrder(Node *root)
    {
        if (!root)
        {
            return;
        }
        preOrder(root->left);
        cout << root->val << " ";
        preOrder(root->right);
    }

    void nextOrder(Node *root)
    {
        if(!root)
            return;
        Node *node = root;
        while(node|| node->left){
            Node *temp = node;
            while(temp){
                cout << temp->val << " ";
                temp = temp->next;
            }
            node = node->left;
        }
    }
};

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;

    sol.preOrder(root);
    cout << endl;
    Node* node = sol.connect(root);
    sol.nextOrder(node);
    cout << endl;

    return 0;
}