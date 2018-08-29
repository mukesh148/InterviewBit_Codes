int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int ans = INT_MAX;
    int i=A.size()-1;
    int j=B.size()-1;
    int k=C.size()-1;
    while( i>=0 && j>=0 && k>=0 ){
        
        int max_ = ( A[i] > B[j] ) ? max( A[i], C[k]) : max( B[j], C[k]);
        // int max_ = max( A[i], B[j] );
        // max_ = max( max_, C[k] );
        // int min_ = min( A[i], B[j] );
        // max_ = min( min_, C[k] );
        int min_ = ( A[i] < B[j] ) ? min( A[i], C[k]) : min( B[j], C[k]);
        int diff = abs(max_ - min_);
        // cout << diff << " diff \n";
        
        if( diff < ans ) ans = diff;
        
        if( max_ == A[i] ){
            i--;
        }
        else if( max_ == B[j] ){
            j--;
        }
        else if( max_ == C[k] ){
            k--;
        }
    }
    return ans;
}

