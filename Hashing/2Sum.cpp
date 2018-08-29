vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    map<int, int> hash;
    vector<int> ret;
    // int low = INT_MIN, high = INT_MAX;
    // for(int i=0; i<A.size(); i++){
    //     // if( hash.find(A[i]) == hash.end()) {
    //         hash.insert(make_pair(A[i], i));
    //         cout << hash[A[i]] << " " << A[i] << " hash \n";
    //     // }
    // }
    // for(int i=0; i<A.size(); i++){
        
    //     if( hash.find( B - A[i] ) != hash.end() ){
    //         cout << hash[B-A[i]] << " " << low << " " << high << " new hash \n";
    //         if( hash[B-A[i]] < high && hash[B-A[i]]>i){
    //             low = i;
    //             high = hash[B-A[i]];
    //             // if(low > high) swap(low, high);
    //         }
    //         else if( hash[B-A[i]] == high && hash[B-A[i]]>i ){
    //             if( i < low ) low = i;
    //             // if(low > high) swap(low, high);
    //         }   
    //     }
            
    // }
    
    for(int i=0; i<A.size(); i++){
        // cout << low << " " << high << " new hash \n";
        if( hash.find( B-A[i] ) != hash.end() ){
            // if( hash[B-A[i]] < high){
                ret.push_back(hash[B-A[i]]+1);
                ret.push_back(i+1);
                return ret;
            // }
        }
        else{
            hash.insert( make_pair(A[i], i) );
        }
        
        
        // if( hash.find( B - A[i] ) != hash.end() ){
        //     cout << hash[B-A[i]] << " " << low << " " << high << " new hash \n";
        //     if( hash[B-A[i]] < high && hash[B-A[i]]>i){
        //         low = i;
        //         high = hash[B-A[i]];
        //     }
        //     else if( hash[B-A[i]] == high && hash[B-A[i]]>i ){
        //         if( i < low ) low = i;
        //     }   
        // }
            
    }
    
    
    // if( low == INT_MIN and high == INT_MAX ) return ret;
    // if(low > high) swap(low, high);
    
    return ret;
}

