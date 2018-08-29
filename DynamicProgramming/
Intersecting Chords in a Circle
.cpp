// long long int combination(int n, int k){
//     if( n <= k) return 1;
//     return ( ( n * combination(n-1, k) ) / (n-k) ) % 1000000007 ;
// }

// long long int combination(vector<vector<int> > &comb, int A){
    
//     comb[0][0] = 1;
//     for(int i=1; i<comb.size(); i++){
//         comb[i][0] = 1;
//         for(int j=1; j<=i; j++){
            
//             comb[i][j] = (comb[i-1][j]%1000000007) + (comb[i-1][j-1]%1000000007);
//             comb[i][j] %= 1000000007;
//             // cout << i << " " << j << " " << comb[i][j] << endl;
//         }
//     }
//     // cout << "2A - " << 2*A << " A- " << A<<endl;
//     return comb[2*A][A];
// }

// long long int combo(int n, int k){
    
//     vector<long long int> vec(k+1,0);
//     vec[0] = 1;
//     for(int i=1; i<=n; i++){
//         for(int j=min(i,k); j>0; j--){
//             vec[j] = ( vec[j] + vec[j-1] ) % 1000000007;
//         }
//     }
//     return vec[k];
// }

int Solution::chordCnt(int A) {
    
    // int MAX = 2*A+1;
    // vector<vector<int> > comb( MAX, vector<int>(MAX,0) );
    
    // long long int ret = combination(2*A, A) / (A+1);
    // return ret % 1000000007;
    
    vector<long long int> vec(A+1, 0);
    vec[0] = 1;
    vec[1] = 1;
    for(int i=2; i<=A; i++){
        for(int j=0; j<i; j++){
            vec[i] += ( (vec[j] % 1000000007) * (vec[i-j-1] % 1000000007) );
            vec[i] %= 1000000007;
        }
    }
    return vec[A];
}

