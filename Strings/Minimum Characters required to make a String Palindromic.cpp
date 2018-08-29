int Solution::solve(string A) {
    
    int go_ = (int)A.length()/2;
    int low = go_-1, high = go_+1;
    int n = A.length();
    int count = 0;
    while( low >= 0 ){
        
        if(A[low] == A[high]){
            low--;
            high++;
            count++;
        }
        else{
            low--;
            high = low + 2;
            count = 0;
            // if(high > n - 1) break;
        }
    }
    int ret = 0;
    int i = 0;
    if(count == 0){
        
        while( i < n and A[i] == A[i+1] ){
            i++;
        }   
        // cout << (i+1) << " i+1 \n";
        ret = n - (i+1);
        return ret;
        
    }
    else{
        ret = n - ( 2 * count + 1);
        return ret;
    }
    
    
    return ret;
}

