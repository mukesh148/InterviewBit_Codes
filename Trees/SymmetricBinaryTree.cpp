/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSymmetric(TreeNode* A) {
    
    if(A==NULL) return 1;
    queue<TreeNode*> q;
    q.push(A->left);
    q.push(A->right);
    
    while( !q.empty() ){
        TreeNode* l = q.front();
        q.pop();
        TreeNode* r = q.front();
        q.pop();
        if( l == NULL && r == NULL) continue;
        if( l == NULL || r == NULL) return 0;
        if(l->val != r->val ) return 0;
        
        q.push( l->left);
        q.push( r->right);
        q.push( l->right);
        q.push( r->left);
    }
    return 1;
}

