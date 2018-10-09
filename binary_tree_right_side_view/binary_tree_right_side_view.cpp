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

    vector<int> rightSideView(TreeNode* root) {
    m_currentLayer = 0;
    m_needVals.clear();

    visitTree(root, 0);

    return m_needVals;
}

    void visitTree(TreeNode* root, int layer)
    {
        if (root == NULL)
        {
           return;
        }

        if (layer >= m_currentLayer)
        {
            m_needVals.push_back(root->val);
            ++m_currentLayer;
        }

        ++layer;
        if (root->right != NULL)
        {
            visitTree(root->right, layer);
        }
    
        
        if (root->left != NULL)
        {
            visitTree(root->left, layer);
        }
    }

private:
    vector<int> m_needVals;
    int m_currentLayer;
};

int main()
{
    return 0;
}
