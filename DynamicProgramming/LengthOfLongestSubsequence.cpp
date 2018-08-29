// int binary_search(vector<int> &vec, int l, int r, int key){
    
//     while( r-l > 1{
//         int m = l + (r-l) / 2;
//         if(vec[m] >= key) r = m;
//         else l = m;
//     }
//     return r;
// }

// vector<int> sorting_count(vector<int> &vec, vector<int> & A){
    
//     vec[0] = A[0];
//     int length = 1; // empty slot
    
//     for(int i=1; i<A.size(); i++){
        
//         if(A[i] < vec[0]){
//             vec[0] = A[i];
//         }
//         else if(A[i] > vec[length-1]){
//             vec[length++] = A[i]
//         }
//         else{
//             vec[binary_search(vec, -1, length-1, A[i])] = A[i];
//         }
        
//     }
// }

vector<int> sorting_inc(const vector<int> &A){
    
    vector<int> ret(A.size(), 1);
    for(int i=1; i<A.size(); i++){
        
        for(int j=0; j<i; j++){
            
            if(A[i] > A[j] && ret[i] < ret[j] + 1){
                ret[i] = ret[j] + 1;
            } 
            
        }
    }
    return ret;
}

vector<int> sorting_dec(const vector<int> &A){
    
    vector<int> ret(A.size(), 1);
    for(int i=A.size()-2; i>=0; i--){
        
        for(int j=A.size()-1; j>i; j--){
            
            if(A[i] > A[j] && ret[i] < ret[j] + 1){
                ret[i] = ret[j] + 1;
            } 
            
        }
    }
    return ret;
}

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    if( n == 0 ) return 0;
    vector<int> fake1 = sorting_inc(A);
    vector<int> fake2 = sorting_dec(A);
    int ret = 1;
    for(int i=0; i<fake1.size(); i++){
        ret = max( ret, fake1[i] + fake2[i] - 1);
    }
    return ret;
}

