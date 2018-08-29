int Solution::lengthOfLongestSubstring(string A) {
    
    int ret = 0;
    for(int i=0; i<A.length(); i++){
        
        unordered_map<char, int> hash;
        int count = 0;
        while( i<A.length() && hash.find(A[i])==hash.end()){
            hash.insert( make_pair(A[i], i) );
            count++;
            i++;
        }
        if( count > ret) ret = count;
        if(i==A.length()) return ret;
        
        i = hash[A[i]];
    }
    return ret;
}

