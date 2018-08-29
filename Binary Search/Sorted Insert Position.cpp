int binary_search(vector<int> &C, int x){
    
    int low = 0;
    int high = C.size()-1;
    while( low <= high){
        int mid = low + ( high - low)/2; 
        if( x == C[mid] ) return mid; 
        else if( C[mid] > x ) high = mid - 1;
        else low = mid + 1;
    }
    if(C[low] > x) return low ;
    return low ;
}


int Solution::searchInsert(vector<int> &A, int B) {
    
    int ans;
    ans = binary_search(A, B);
    return ans;
    
}

