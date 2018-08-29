int Solution::majorityElement(const vector<int> &A) {
    
    unordered_map<int, int> hash;
    for(int i=0; i<A.size(); i++){
        
        if( hash.find(A[i]) == hash.end() ){
            hash[A[i]] = 1;
        }
        else hash[A[i]]++;
        
        if( hash[A[i]] > floor( A.size()/2 ) ) return A[i];
    }
    return -1;
}

