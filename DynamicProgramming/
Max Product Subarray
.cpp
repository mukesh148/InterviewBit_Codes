int Solution::maxProduct(const vector<int> &A) {

    long long int ret=0, max_=1, temp=1;
    for(int i=0 ;i<A.size(); i++){
        
        temp*= A[i];
        max_*= A[i];
        ret = max(ret, max(temp, max_));
        if( max_<=0 ) {
            max_ = 1;
        }
        if(temp==0) temp = 1;
        
    }
    
    temp = 1;
    max_ = 1;
    for(int i=A.size()-1; i>=0; i--){
        temp*= A[i];
        max_*= A[i];
        ret = max(ret, max(temp, max_));
        if( max_<=0 ) {
            max_ = 1;
            if( i==0) return ret;
        }
        if(temp==0) temp = 1;
        
    }
    
    ret = max(ret, max(temp, max_));
    return ret;
}

