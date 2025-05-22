#include <iostream>
#include <cmath> // for abs()

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//approach:
/*
recursive : go to every node and ask what they get from left , right
and then return need : (leftneed+ rightneed+ node->val -1)

*/

class Solution
{
public:
    int movement = 0;

    int moveCalculate(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftNeed = moveCalculate(root->left);
        int rightNeed = moveCalculate(root->right);

        int need = leftNeed + rightNeed + root->val - 1;

        movement += abs(need);

        return need;
    }

    int distributeCoins(TreeNode *root)
    {
        moveCalculate(root);
        return movement;
    }
};

int main()
{


    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    Solution sol;
    int result = sol.distributeCoins(root);

    cout << "Minimum moves required: " << result << endl;

    return 0;
}
