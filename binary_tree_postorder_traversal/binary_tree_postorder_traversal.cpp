/**
 * Definition for binary tree
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
    vector<int> postorderTraversal(TreeNode *root) {

    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        m_node.push_back(root->val);
    }
    
    return m_node;
    }
private:
    vector<int> m_node;  
};

int main()
{
    return 0;
}
