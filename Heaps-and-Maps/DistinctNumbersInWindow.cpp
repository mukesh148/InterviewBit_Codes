vector<int> Solution::dNums(vector<int> &A, int B) {
    
    unordered_map<int, int> hash;
    vector<int> vec;
    int temp = 0;
    
    for(int i=0; i<A.size(); i++){
        
        if(hash.find(A[i])==hash.end()){
            hash[A[i]] = 1;
            temp++;
        }
        else {
            hash[A[i]]++;
        }
        if(i>=B) {
            if(hash[A[i-B]]>1) { 
                hash[A[i-B]]--;
            }
            else {
                temp--;
                hash.erase(A[i-B]);
            }
        }
        if(i>=B-1) vec.push_back(temp);
    }
    return vec;
    // for(int i=0; i<B; i++){
    //     if(hash.find(A[i])==hash.end()){
    //         hash[A[i]] = 1;
    //         temp++;
    //     }
    //     else {
    //         hash[A[i]]++;
    //     }
    // }
    // vec.push_back(temp);
    
    // for(int i=B; i<A.size(); i++){
        
    //     if(hash[A[i-B]]>1) { 
    //         hash[A[i-B]]--;
    //     }
    //     else {
    //         temp--;
    //         hash.erase(A[i-B]);
    //     }
        
    //     if(hash.find(A[i])==hash.end()){
    //         hash[A[i]] = 1;
    //         temp++;
    //     }
    //     else {
    //         hash[A[i]]++;
    //     }
        
    //     vec.push_back(temp);
    // }
    // return vec;
}

