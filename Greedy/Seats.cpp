int Solution::seats(string A) {
    
    int ret=0, i=0;
    // while( i<A.length() && A[i]=='.' ) i++;
    // while( j>=0 && A[j]=='.' ) j--;
    int count=0, sum_=0;
    for(int i=0; i<A.size(); i++){
        if( A[i]=='.' ){
            sum_+= i;
            count++;
        }
    }
    
    i = floor( sum_ / count );
    for(i=i; i<A.length(); i++){
        if(A[i]=='.') ret++;
    }
    return ret;
}

