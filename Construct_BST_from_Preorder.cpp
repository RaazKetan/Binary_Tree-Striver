/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* Build(vector<int>& preorder, int PreStart, int PreSize, vector<int>& inorder, int InStart, int InSize,map<int, int >&mpp)
{
    if(PreStart>PreSize || InStart>InSize)
    return NULL;
    TreeNode* root = new TreeNode(preorder[PreStart]);

    int inRoot = mpp[root->val];
    int NumLeft = inRoot - InStart;

    root->left = Build(preorder, PreStart+1,PreStart+NumLeft,inorder, InStart, inRoot-1, mpp);
    root->right = Build(preorder, PreStart+NumLeft+1,PreSize,inorder, inRoot+1, InSize, mpp);

    return root;
} 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(), preorder.end());
          sort(inorder.begin(), inorder.end());
        map<int, int >mpp;
        for(int i = 0;i<inorder.size(); i++)
        mpp[inorder[i]] = i;

        TreeNode* root = Build(preorder, 0,preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};