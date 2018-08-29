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

int check( TreeNode* A){
    if( !flag ) return 0;
    if( A== NULL ) return 0;
    int left, right;
    left = check(A->left);
    right = check(A->right);
    if( abs(left-right) > 1 ){
        flag = false;
        return 0;
    }
    return max( left, right )+1;
}
 
int Solution::isBalanced(TreeNode* A) {
    
    flag = true;
    if(check(A)) return flag;
    return flag;
}

