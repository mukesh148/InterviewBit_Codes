/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool flag;
void traverse( TreeNode* A, TreeNode* B){
    
    if( !flag ) return;
    if( A==NULL ^ B==NULL ) {
        flag = false;
        return;
    }
    if( A==NULL && B==NULL) return;
    traverse( A->left, B->left );
    traverse( A->right, B->right );
    
    if( A->val != B->val ) {
        flag = false;
        return;
    }
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    flag = true;
    traverse( A, B);
    return flag;
}

