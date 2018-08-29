/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* build( const vector<int>&A, int start, int end ){
    
    if( start == end ){
        TreeNode* node = new TreeNode(A[start]);
        return node;
    }
    if( start > end ) return NULL;
    
    int n = (start + end + 1) / 2;
    TreeNode* root = new TreeNode(A[n]);
    root->left = build( A, start, n-1);
    root->right = build( A, n+1, end);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    return build(A, 0, A.size()-1);
    
}

