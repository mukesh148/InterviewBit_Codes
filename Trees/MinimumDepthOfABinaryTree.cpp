/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void finddepth( TreeNode* root, int &min_, int depth){
    
    if( !root) return;
    if( root->left== NULL && root->right==NULL ){
        if( depth < min_ ) min_ = depth;
    }
    finddepth( root->left, min_, depth+1);
    finddepth( root->right, min_, depth+1);
}

int Solution::minDepth(TreeNode* A) {

    int min_ = INT_MAX;
    finddepth( A, min_, 1);
    return min_;
}

