void Solution::sortColors(vector<int> &A) {
    
    int count = 0;
    for(int i=0; i<3; i++){
        int k = 0;
        while( k < A.size() ){
            
            if(A[k]==i){
                swap( A[count], A[k] );
                count++;
                k++;
            }
            else k++;
        }
    }
    
}

