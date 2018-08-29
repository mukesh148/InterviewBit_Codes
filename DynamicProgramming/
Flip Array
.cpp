int Solution::solve(const vector<int> &A) {
// 
    if(A.size()<=1) return 0;
    int n =A.size(), w =0;
    for(int i=0; i<A.size(); i++){
        w+= A[i];
    }
    w /= 2;
    // cout << w << " -w \n";
    
    // int ret = INT_MAX, count = 0, check = 0;
    vector<vector<int> > dp(n+1, vector<int> (w+1, 0));
    vector<vector<int> > count(n+1, vector<int> (w+1, 0));
    for(int i=0; i<=n; i++){
        // count = 0;
        // check = 0;
        for(int j=0; j<=w; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(A[i-1]<=j){
                // if(A[i-1]!=w){
                dp[i][j] = max(A[i-1] + dp[i-1][j-A[i-1]], dp[i-1][j]);
                
                if(i==1) {
                    count[i][j] += j/A[i-1];
                }
                if(i!=1){
                if(dp[i][j] == A[i-1] + dp[i-1][j-A[i-1]]) count[i][j]+=count[i-1][j-A[i-1]];
                else count[i][j] += count[i-1][j];
                }
            }
            else{
                // count++;
                dp[i][j] = dp[i-1][j];
                count[i][j] += count[i-1][j];
            }
            // check += dp[i][j];
            if(dp[i][j]==w) cout << i << " " << j << " " << count[i][j] << endl;
        }
        // cout << count << " -count " << endl;
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            cout << count[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

