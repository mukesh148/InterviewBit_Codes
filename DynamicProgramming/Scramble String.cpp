int Solution::isScramble(const string A, const string B) {
    
    if( A.length() != B.length() ) return 0;
    unordered_map<char, int> hash;
    for(int i=0; i<A.length(); i++){
        
        if(hash.find(A[i])==hash.end()){
            hash[A[i]] = 1;
        }
        else hash[i]++;
        
    }
    for(int i=0; i<B.length(); i++){
        
        if(hash.find(B[i])==hash.end() || hash[B[i]]<=0){
            return 0;
        }
        else hash[i]--;
        
    }
    
    return 1;
}


