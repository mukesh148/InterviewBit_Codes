int Solution::minPathSum(vector<vector<int> > &A) {
    
    vector<vector<int>> vec(A.size()+1, vector<int>(A[0].size()+1, 0));
    
    for(int i=1; i<=A[0].size(); i++){
        vec[1][i] = vec[1][i-1] + A[0][i-1]; 
    }
    for(int i=1; i<=A.size(); i++){
        vec[i][1] = vec[i-1][1] + A[i-1][0]; 
    }
    
    for(int i=2; i<=A.size(); i++){
        for(int j=2; j<=A[0].size(); j++){
            
            vec[i][j] = min(vec[i-1][j], vec[i][j-1]) + A[i-1][j-1];
            
        }
    }
    return vec[A.size()][A[0].size()];
}

