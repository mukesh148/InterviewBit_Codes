int Solution::diffPossible(const vector<int> &A, int B) {
    
    map<int, int> hash;
    
    for(int i=0; i<A.size(); i++){
        int a = A[i] - B;
        int b = B + A[i];
        
        if( hash.find(a)!= hash.end() || hash.find(b)!= hash.end()) return 1;
        else {
            hash.insert( make_pair(A[i], i) );
        }
        
    }
    return 0;
}

