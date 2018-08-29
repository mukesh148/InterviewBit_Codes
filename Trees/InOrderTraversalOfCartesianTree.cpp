/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* build( TreeNode* inorder, int start, int end){
    
    if( start == end ){
        TreeNode* node = new TreeNode(inorder[start]);
        return node;
    }
    
    int maxval = INT_MIN, max_ind = -1;
    for(int i=start; i<=end; i++){
        if( inorder[i] > maxval){
            maxval = inorder[i];
            max_ind = i;
        }
    }
    
    TreeNode* root = new TreeNode(maxval);
    root->left = build( inorder, start, max_ind-1);
    root->right = build( inorder, max_ind+1, end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    return build( A, 0, A.size()-1);
}

