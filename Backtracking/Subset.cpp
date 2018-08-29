// void subset( vector<vector<int> > &A, vector<int> &B);{
    
//     for(int i=0; i<B.size(); i++){
        
//     }
    
// }


void gencomb(vector<vector<int>>&ret, int start, vector<int>&ans, vector<int>&A ){
    
    ret.push_back(ans);
    for(int i=start; i<A.size(); i++){
        ans.push_back(A[i]);
        gencomb(ret, i+1, ans, A);
        ans.pop_back();
    }
    
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    
    sort(A.begin(), A.end());
    
    vector<vector<int> > ret;
    vector<int> ans;
    gencomb(ret, 0, ans, A);
    return ret;
}

