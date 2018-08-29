vector<int> Solution::maxone(vector<int> &A, int B) {
    
    vector<int> ret;
    
    int low = 0;
    int high = 0;
    for(int i=0; i<A.size(); i++){
        
        bool check = false;
        int low_ = i, high_ = A.size()-1;;
        int pick = i, count = 0;
        while( i<A.size() and count <= B ){
            
            if( !check and A[i]==0){
                check = true;
                pick = i;
            }
            if(A[i]==0) {
                count++;
                if(count > B) {
                    high_ = i-1;
                    break;
                }
            }
            i++;
        }
        if( i < A.size() ) i = pick;
        if((high_-low_) > (high-low)){
            low = low_;
            high = high_;
        }
    }
    for(int i=low; i<high+1; i++){
        ret.push_back(i);
    }
    return ret;
}

