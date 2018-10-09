/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {

public:

    TreeNode* invertTree(TreeNode* root) {

    if (root == NULL)
    {
        return root;
    }

    vector<TreeNode*> nodes;

    nodes.push_back(root);

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        TreeNode* tmp = nodes[i]->left;
        nodes[i]->left = nodes[i]->right;
        nodes[i]->right = tmp;
        if (nodes[i]->left != NULL)
        {
            nodes.push_back(nodes[i]->left);
        }

        if (nodes[i]->right != NULL)
        {
            nodes.push_back(nodes[i]->right);
        }
        
    }

    return root;

    }

};

int main()
{
    return 0;
}
