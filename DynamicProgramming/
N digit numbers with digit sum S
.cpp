// void addNUM(long long int &ret, int digit, int cur_digit, int cur_sum, int desired_sum){
    
//     if(cur_digit==digit && cur_sum == desired_sum){
//         ret++;
//         ret %= 1000000007;
//         return;
//     }
//     else if( cur_digit==digit ) return;
//     for(int i=0; i<=desired_sum; i++){
//         if(i==0 && cur_digit==0) continue;
//         addNUM(ret, digit, cur_digit + 1, cur_sum + i, desired_sum);
//     }
//     return;
// }

int NUMcount(vector<vector<int>> &dp, int digit, int sum){
    
    if(sum < 0) return 0;
    if(digit == 0 && sum == 0) return 2;
    if(digit == 0) return 0;
    
    if(dp[digit][sum]!=-1) return dp[digit][sum];
    
    int ans = 0;
    for(int i=0; i<10; i++){
        ans += NUMcount(dp, digit-1, sum-i);
        ans %= 1000000007;
    }
    return dp[digit][sum] = ans;
}

int Solution::solve(int A, int B) {
    
    vector<vector<int>> vec(A+1, vector<int> (B+1, -1));
    
    int ans = 0;
    for(int i=1; i<10; i++){
        ans += NUMcount(vec, A-1, B-i);
        ans %= 1000000007;
    }
    
    return ans;
}

