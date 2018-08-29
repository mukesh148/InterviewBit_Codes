/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void finddepth( TreeNode* root, int &max_, int depth){
    
    if( root->left== NULL && root->right==NULL ){
        if( depth > max_ ) max_ = depth;
        return ;
    }
    finddepth( root->left, max_, depth+1);
    finddepth( root->right, max_, depth+1);
}
int Solution::maxDepth(TreeNode* A) {
    
    int max_ = 0;
    finddepth( A, max_, 1);
    return max_;
}

