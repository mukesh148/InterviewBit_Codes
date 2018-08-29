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

void makesum( TreeNode* root, int sum){
    
    if( flag )  return;
    if( !root ) return;
    
    
    // sum+= root->val;
    // if( sum == B && root->left==NULL && root->right==NULL ){
    //     flag = true;
    //     return;
    // }
    if( root->left==NULL && root->right==NULL ){
        if(sum == root->val )flag = true;
        return;
    }
    int remain_sum = sum - root->val;
    makesum( root->left, remain_sum);
    
    makesum( root->right, remain_sum);
    return;
}

int Solution::hasPathSum(TreeNode* A, int B) {
    flag = false;
    // int sum = 0;
    makesum(A, B);
    return flag;
}

