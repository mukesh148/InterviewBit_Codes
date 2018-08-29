/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int> >ret;
    queue<pair<TreeNode*, int> > q;
    
    q.push( make_pair(A, 0) );
    vector<int> temp_vec;
    int depth=0;
    while( !q.empty() ){
        
        pair<TreeNode*, int> front = q.front();
        q.pop();
        TreeNode* temp_tree = front.first;
        int temp_int = front.second;
        // cout << temp_int << "  " << temp_tree->val < " print \n";
        if( depth == temp_int - 1 ){
            ret.push_back(temp_vec);
            temp_vec.clear();
            depth++;
        }
        
        temp_vec.push_back(temp_tree->val);
        if( temp_tree->left ){
            q.push( make_pair(temp_tree->left, temp_int+1) );
        }
        if( temp_tree->right ){
            q.push( make_pair(temp_tree->right, temp_int+1) );
        }
    }
    ret.push_back(temp_vec);
    temp_vec.clear();
    for(int i=0; i<ret.size(); i++){
        if(i%2!=0){
            reverse( ret[i].begin(), ret[i].end() );
        }
    }
    return ret;
}

