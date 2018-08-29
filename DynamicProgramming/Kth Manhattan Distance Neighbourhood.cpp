vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<vector<int> > dp = B;
    for(int i=1; i<=A; i++){
        B = dp;
        for(int j=0; j<B.size(); j++){
            for(int k=0; k<B[0].size(); k++){
                
                int val = INT_MIN;
                if(j-1>=0) val = max(val, B[j-1][k]);
                if(k-1>=0) val = max(val, B[j][k-1]);
                if(j+1<dp.size()) val = max(val, B[j+1][k]);
                if(k+1<dp[0].size()) val = max(val, B[j][k+1]);
                dp[j][k] = max( val, B[j][k] );
                
            }
        }
        
    }
    return dp;
}

