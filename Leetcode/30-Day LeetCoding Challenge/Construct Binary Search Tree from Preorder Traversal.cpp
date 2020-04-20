/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* util( vector<int> pre, int &index , int mx ,int mn){
        if ( index == pre.size() )return nullptr;
        int val = pre[index];
        if ( val > mx || val < mn) return nullptr;
        TreeNode * root = new TreeNode( val);
        index++;
        root-> left = util( pre, index , val-1, mn);
        root -> right = util (pre, index, mx,  val+1);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if ( preorder.empty()) return NULL;
        int p =0;
        TreeNode* root = util( preorder , p , INT_MAX ,INT_MIN);
        return root;
        
    }
};
