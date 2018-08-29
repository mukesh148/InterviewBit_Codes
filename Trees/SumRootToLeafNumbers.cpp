/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int gen_num( string &A ){
    int ret=0;
    for(int i=0; i<A.length(); i++){
        ret += (int)(A[i]-'0') * pow( 10, A.length()-1-i );
        ret = ret%1003; 
    }
    return ret;
}

void findsum( TreeNode* root, string str, int &ret ){
    
    if( !root ) return;
    str+= to_string( root->val );
    if( root->left== NULL && root->right==NULL ){
        
        ret += gen_num( str );
         
        ret = ret%1003;
        // cout << str << " " << ret << " " << gen_num( str ) << "  str \n";
        return ;
    }
    findsum( root->left, str, ret );
    findsum( root->right, str, ret );
}

int Solution::sumNumbers(TreeNode* A) {
    
    int ret = 0;
    string str = "";
    findsum( A, str, ret);
    
    string a = "379128613686355";
    cout << gen_num(a) << " print \n";
    return ret;
}

