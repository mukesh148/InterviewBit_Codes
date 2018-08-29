/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void just_trav( TreeNode* A ){
    
    if( !A ) return;
    
    hash[ A->val ] = -1;
    if( A->val == find ) return;
    
    just_trav( A->left, hash, find);
    
    
    
    
    
    just_trav( A->right, hash, find);
    
} 
int Solution::lca(TreeNode* A, int B, int C) {
    
    
}

