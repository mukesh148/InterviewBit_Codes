// int Solution::solve(vector<vector<int> > &A) {
    
//     if(!A.size()) return 0;
//     // int ret = 0;
//     vector<pair<int,int>> vec;
//     int MAX = 1e6;
//     for(int i=0; i<A.size(); i++){
//         int count = 0, min_ = 1e7;
//         for(int j=0; j<A[0].size(); j++){
            
//             if(i>0){
//                 if(A[i][j]==1) {
//                     A[i][j] += A[i-1][j]; 
//                     count++;
//                 }
//                 // else A[i][j] = MAX;
//                 // if(A[i][j] > ret) ret = A[i][j];
//             }
//             else{
//                 // if(A[i][j] > ret ) ret = A[i][j];
//                 // if(A[i][j]==0) A[i][j] = MAX;
//                 if(A[i][j]==1) {
//                     count++;
//                     min_ = 1;
//                 }
//             }
//             // cout << A[i][j] << " ";
//             if( A[i][j]!=0 && A[i][j] < min_) min_ = A[i][j];
//         }
//         vec.push_back(make_pair(count, min_));
//     }
    
//     int ret = 0;
//     for(int i=0; i<vec.size(); i++){
//         ret = max(ret, vec[i].first * vec[i].second);
//     }
//     return ret;
// }
int Solution::solve(vector<vector<int> > &A){
int n, m, res = 0;
    n = A.size();
    m = A[0].size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(A[j-1][i-1] == 0) {
                dp[j][i] = 0;
            }
            else {
                dp[j][i] += dp[j-1][i] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int arr[n + 1], cnt = 0;
        memset(arr, 0, sizeof(arr));
        for (int j = 1; j <= m; ++j) {
            arr[dp[i][j]] ++;
        }
        for (int j = n; j >= 0; --j) {
            cnt += arr[j];
            res = max(res, cnt * j);
        }
    }
    return res;
}
