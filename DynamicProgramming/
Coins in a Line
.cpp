// int MinProfit(vector<int> &A, int start, int end);
// int MaxProfit(vector<int> &A, int start, int end){
    
//     if(start == end ) return 0;
    
//     return max( A[start] + MaxProfit(A, start+1, end), A[end] + MaxProfit(A, start, end-1) );
    
// }

// int MinProfit(vector<int> &A, int start, int end){
    
//     if(start == end ) return 0;
    
//     return min( MaxProfit(A, start+1, end), MaxProfit(A, start, end-1) );
    
// }



    vector<vector<vector<int> > > dp;
    int rec(int plyr, int start, int end, vector<int> vec) {
        if(start > end)
                return 0;
        if(dp[plyr][start][end] != -1)
                return dp[plyr][start][end];

        if(plyr == 0) {
            int ans = rec(1, start + 1, end, vec) + vec[start];
            ans = max(ans, rec(1, start, end - 1, vec) + vec[end]);
            return dp[plyr][start][end] = ans;
        } else {
            return dp[plyr][start][end] = min(rec(0, start + 1, end, vec), rec(0, start, end - 1, vec));
        }

    }
int Solution::maxcoin(vector<int> &vec) {
    // int a = MaxProfit(A, 0, A.size()-1);
    // int b = MinProfit(A, 0, A.size()-1);
    // cout << a << " " << b << endl;
    // return a - b;
               
        int N = vec.size();
        dp.clear();
        dp.resize(2, vector<vector<int > > (N, vector<int> (N, -1)));
        int ans = rec(0, 0, N - 1, vec);
        return ans;
}

//   int Solution::maxcoin(vector<int> vec) {

//   }

