int Solution::solve(const vector<int> &A) {

    if(A.size()<=2) return A.size();
    vector<vector<int> > dp(A.size(), vector<int> (A.size(), 2));
    int ret = 2;
    unordered_map<int, int> hash;
    
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            
            int diff = A[i]-A[j];
            int X = 2*A[i] - A[j];
            
            if(hash.find(X)==hash.end()) continue;
            
            dp[i][j] = dp[X][i] + 1;
            if(dp[i][j]>ret) ret = dp[i][j];
        }
        hash[A[i]] = 1;
    }
    return ret;
}

