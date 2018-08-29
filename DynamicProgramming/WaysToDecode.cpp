int Solution::numDecodings(string A) {
    
    if(A.length()==0) return 0;
    vector<int> dp(A.length()+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=A.length(); i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    int ret = 1, count = 0;
    for(int i=0; i<A.length()-1; i++){
        if( A[i]=='0' ){
            if( i-1 < 0 ) return 0;
            else {
                if( A[i-1]!='1' && A[i-1]!='2' ) {
                    return 0;
                }
            }
            continue;
        }
        string str = A.substr(i, 2);
        int check = stoi(str);
        // cout << str << " str" << check << endl;
        if(check <= 26){
            if(check == 10 || check == 20 ) {
                // cout << " jappensd ";
                count--;
                continue;
            }
            count++;
        }
        else{
            ret *= dp[count+1];
            // cout << dp[count+1] << " " << ret << " ret" << endl;
            count = 0;
        }
    }
    ret *= dp[count+1];
    return ret;
}

