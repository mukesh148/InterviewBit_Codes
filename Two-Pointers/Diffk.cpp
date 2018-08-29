int Solution::diffPossible(vector<int> &A, int B) {
    
    
    int low =0;
    int high=1;
    while( low < A.size() && high<A.size() ){
        
        int temp = A[high] - A[low];
        if( low!=high and temp == B ) return 1;
        else if( temp < B ) high++;
        else low++;
        
    }
    return 0;
}

/*
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            
            if( i!=j and A[j]-A[i]==B ){
                return 1;
            }
            if( A[j]-A[i] > B ){
                break;
            }
        }
    }
    return 0;
*/
