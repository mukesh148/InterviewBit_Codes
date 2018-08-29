int combination(int n, int k){
    if( n <= k) return 1;
    return ( n * combination(n-1, k) ) / (n-k) ;
}

int Solution::numDistinct(string A, string B) {
    
    int lena = A.length(), lenb= B.length();
    vector<vector<int>> dp(lena+1, vector<int>(lenb+1));
    for(int i=0; i<=lenb; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=lena; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=lena; i++){
        for(int j=1; j<=lenb; j++){
            
            if(A[i-1] != B[j-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            
        }    
    }
    return dp[lena][lenb];
    // cout << A.length() << " " << B.length() << endl;
    
    // if(A.length()<B.length()) return 0;
    // int ind1 = 0, ind2 =0, ret = 0;
    // while(ind1 < A.length() && ind2 <B.length()){
        
        
    //     int i=ind1, j=ind2, count1=0, count2=0;
    //     while( j < B.length() && B[ind2] == B[j]) {
    //         j++;
    //         count2++;
    //     }
    //     // cout << ind1 << " " << ind2 << " " << i << " " << j << " " <<A[i]<<" "<<B[j] << endl;
        
    //     while( i<A.length() && j<B.length() && ( A[i]!=B[j] || count1<count2 ) ) {
    //         // cout << A[i] << "  " << ind2 <<  " print \n";
    //         if( A[i] == B[ind2] ) {
    //             count1++;
    //             // cout << " once more \n";
    //             if(!ret) ret = 1;
    //         }
    //         i++;
    //     }
    //     if( j>=B.length() && i<A.length() ){
    //         while(i<A.length() && A[i]!=B[0]){
    //             if( A[i] == B[ind2] ) {
    //                 count1++;
    //                 if(!ret) ret = 1;
    //             }
    //             i++;
    //         }
    //         j=0;
    //     }
    //     if(ret) ret *= combination(count1, count2); 
    //     cout <<ind1<<" "<<ind2<<" "<<i<<" " <<j<<" "<<ret<<" "<<count1<<" "<<count2<<" "<<combination(count1, count2)<<endl; 
    //     ind1 = i;
    //     ind2 = j;
    // }
    // return ret;
}

