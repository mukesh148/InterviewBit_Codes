int Solution::isMatch(const string A, const string B) {
    
    int n=A.length(), m=B.length();
    vector<vector<bool> > dp(n+1, vector<bool> (m+1, 0));
    dp[0][0] = 1;
    
    for(int i=1; i<=m; i++){
        if(B[i-1]=='*') {
            if(i-2>=0) dp[0][i] = dp[0][i-2] || dp[0][i-1];
            else dp[0][i] = 1;
        }
    }
    
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=m; j++){
            
            if(B[j-1]==A[i-1] || B[j-1]=='.'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(B[j-1]=='*'){
                dp[i][j] = dp[i][j-2] || ( (B[j-2]=='.' || B[j-2]==A[i-1]) ? dp[i-1][j] : 0 );
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

