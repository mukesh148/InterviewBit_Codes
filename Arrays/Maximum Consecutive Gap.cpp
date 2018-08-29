int Solution::maximumGap(const vector<int> &A) {
    
    int count = 0;
    if(A.size()<2) return 0;
    vector<int> B=A;
    sort(B.begin(), B.end());
    for(int i=B.size()-1; i>0; i--){
        if( (B[i]-B[i-1]) > count) count = (B[i]-B[i-1]);
    }
    return count;
}

