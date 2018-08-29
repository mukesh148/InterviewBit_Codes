int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int i=A.size()-1;
    int j=B.size()-1;
    int k=C.size()-1;
    
    int min_val = INT_MAX;
    while( i>=0 and j>=0 and k>=0 ){
        
        int max_diff = ( abs(A[i]-B[j]) > abs(A[i]-C[k]) ) ? max( abs(A[i]-B[j]),abs(B[j]-C[k]) ) : max( abs(A[i]-C[k]),abs(B[j]-C[k]) );  
        if(max_diff < min_val) min_val = max_diff;
        
        int max_ele = (A[i]>B[j]) ? max(A[i],C[k]):max(B[j],C[k]);
        if(max_ele == A[i]) i--;
        else if(max_ele == B[j]) j--;
        if(max_ele == C[k]) k--;
        
    }
    
    return min_val;
}

