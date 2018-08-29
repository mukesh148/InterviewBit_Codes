int Solution::canJump(vector<int> &A) {

    if( A.size()==1 ) return 1;
    
    int ind = A.size()-1;
    int i = 0;
    for(i=A.size()-2 ; i>=0; i--){
        
        if( A[i] >= (ind - i) ) {
            // cout << ind << " ind " << i << " i \n";
            ind = i;
        }
        
    }
    if( ind == i+1) return 1; 
    return 0;
}

