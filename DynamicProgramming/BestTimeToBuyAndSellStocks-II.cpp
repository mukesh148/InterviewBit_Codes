int Solution::maxProfit(const vector<int> &A) {
    
    if (A.size() <= 1) return 0;
    // int K = A.size()/2; // number of max transation allowed
    // int maxProf = 0;
    // vector<vector<int> > f(K+1, vector<int>(A.size(), 0));
    // for (int kk = 1; kk <= K; kk++) {
    //     int tmpMax = f[kk-1][0] - A[0];
    //     for (int ii = 1; ii < A.size(); ii++) {
    //         f[kk][ii] = max(f[kk][ii-1], A[ii] + tmpMax);
    //         tmpMax = max(tmpMax, f[kk-1][ii] - A[ii]);
    //         maxProf = max(f[kk][ii], maxProf);
    //     }
    // }
    int maxProf = 0, count = A[0];
    for(int i=1; i<A.size(); i++){
        if(A[i]>count){
            maxProf += A[i]-count;
            count = A[i];
        }
        else{
            count = A[i];
        }
    }
    return maxProf;
    
}

