int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    // int index = 0;
    for(int index=0, i=0; i<A.size(); i++){
        
        index = i;
        bool check = false;
        int carry = 0;
        for(int j=i; j<A.size(); j++){
            
            if( check && j==index ) return index;
            if( A[j]+carry >= B[j] ){
                carry = A[j]+carry-B[j];
            }
            else break;
            if( j==A.size()-1 ) {
                check = true;
                j=-1;
            }
        }
        
    }
    return -1;
    
}

