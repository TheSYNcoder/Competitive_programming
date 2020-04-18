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
    
    int height( TreeNode* root){
        if  (root == NULL) return 0;
        return ( 1 + max( height( root -> left) , height( root -> right)));
    }
    
    int diameter( TreeNode* root){
        if ( root == NULL) return 0;
        int ld = diameter( root -> left);
        int rd = diameter( root -> right);
        return max( 1 + height( root -> left) + height( root -> right) , max( ld ,rd));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == NULL) return 0;
        return diameter( root)-1;
        
         
        
    }
};
