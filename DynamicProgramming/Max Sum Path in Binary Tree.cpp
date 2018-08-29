/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void treeTraverse(TreeNode *A, int &ret){
    
    if(A==NULL) return;
    
    treeTraverse(A->left, ret);
    treeTraverse(A->right, ret);
    
    if( A->val > ret ) ret = A->val;
    
    int count = 0, fake = A->val;
    // cout << A->val << " ";
    if(A->left) {
        int fake1 = A->left->val;
        if(fake1 > 0) {
            count = fake1; 
            fake += fake1;
        }
    }
    if(A->right) {
        int fake1 = A->right->val;
        if(fake1 > 0 ) {
            fake += fake1;
            if(fake1 > count ) count = fake1;
        }
    }
    if(count) A->val+= count;
    if( A->val > ret ) ret = A->val;
    if( fake > ret ) ret = fake;
    // cout << A->val << " " << fake << " \n"; 
}

int Solution::maxPathSum(TreeNode* A) {
    
    int ret = A->val;
    
    treeTraverse(A, ret);
    // cout << A->val << " ret \n";
    return ret;
}

