/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// void inorder(vector<int> &ret, TreeNode* A){
    
//     if( A==NULL ) return;
    
//     inorder(ret, A->left);
//     ret.push_back(A->val);
//     inorder(ret, A->right);

// }
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> ret;
    // inorder(ret, A);
    // return ret;
    stack<TreeNode* > stack;
    TreeNode* curr = A;
    while( curr || !stack.empty() ){
        
        if( curr ){
            stack.push( curr );
            curr = curr->left;
        }
        else{
            TreeNode* temp =  stack.top();
            ret.push_back( temp->val );
            stack.pop();
            curr = temp->right;
        }
        
    }
    return ret;
}

