/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    unordered_map<int , int> hash;
    for(int i=0; i<B.size(); i++){
        hash[B[i]] = i;
    }
    
    build(A, hash, 0, )
}

