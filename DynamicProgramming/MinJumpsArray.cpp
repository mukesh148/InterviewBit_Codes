int Solution::jump(vector<int> &A) {

    if( A.size()<=1 ) return 0;
    // if(A[0]==0) return -1;
    // int n = A.size();
    // int ret = INT_MAX;
    // vector<int> vec(n, 1);
    // for(int i=0; i<n-1; i++){
        
    //     for(int j=1; j<=A[i]; j++){
    //         if( (i+j) < n && vec[i+j]==1){
    //             vec[i+j] = vec[i] + 1;
    //         }
    //         else if( (i+j) < n ){
    //             if(vec[i]+1 < vec[i+j]) vec[i+j] = vec[i] + 1;
    //         }
    //         if(i+j == n-1){
    //             if( vec[i] < ret )  return ret = vec[i];
    //         }
    //     }
    //     if( (i-1)>=0 && vec[i] < vec[i-1]) return -1;
    // }
    // if(ret == INT_MAX) return -1;
    // return ret;
    
    int max_reach = A[0];
    int curr_max_reach = A[0];
    int step = 1;
    for(int i=1; i<=max_reach; i++){
        
    }
    
}

