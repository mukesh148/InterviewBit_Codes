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
    
//     inorder(ret, A->right);
//     ret.push_back(A->val);
// } 
vector<int> Solution::postorderTraversal(TreeNode* root) {
    
    // vector<int> ret;
    // inorder( ret, A );
    // return ret;
    
    
    stack<TreeNode*> nodeStack;
    vector<int> result;
    //base case
    if(root==NULL)
        return result;
    nodeStack.push(root);
    while(!nodeStack.empty()) {
        TreeNode* node= nodeStack.top();  
        result.push_back(node->val);
        nodeStack.pop();
        if(node->left)
            nodeStack.push(node->left);
        if(node->right)
            nodeStack.push(node->right);
    }
    reverse(result.begin(),result.end());
    return result;
}

