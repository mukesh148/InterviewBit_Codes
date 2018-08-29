int Solution::mice(vector<int> &A, vector<int> &B) {

    // map<int, int> hash1;
    // map<int, int> hash2;
    // for(int i=0; i<A.size(); i++){
        
    //     hash1[A[i]]= i;
    //     hash2[B[i]]= i;
    // }
    sort( A.begin(), A.end() );
    sort( B.begin(), B.end() );
    int ret = 0;
    for(int i=0; i<A.size(); i++){
        ret = max(ret, abs(A[i]-B[i]));
    }
    return ret;
}

