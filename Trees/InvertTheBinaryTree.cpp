/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void invert( TreeNode* A ){
    
    if( !A ) return;
    
    invert( A->left);
    
    TreeNode* temp1 = A->left;
    TreeNode* temp2 = A->right;
    
    A->left = temp2;
    A->right = temp1;
    
    invert( temp2 );
    
    
} 
TreeNode* Solution::invertTree(TreeNode* A) {
    invert( A) ;
    return A;
}

