int Solution::maxArea(vector<int> &A) {
    
    int low = 0;
    int high = A.size()-1;
    int ret = 0;
    while(low < high){
        
        int temp = (high-low) * min(A[low], A[high]);
        if(temp > ret) ret = temp;
        
        if( A[low]>A[high] ){
            high--;
        }
        else low++;
        
    }
    return ret;
}

/*

    int ret = 0;
    for(int i=0; i<A.size(); i++){
        
        for(int j=A.size()-1; j>i; j--){
            
            int temp = (j-i) * min(A[i], A[j]);
            if(temp>ret) ret = temp;
        }
    }
    return ret;
*/
