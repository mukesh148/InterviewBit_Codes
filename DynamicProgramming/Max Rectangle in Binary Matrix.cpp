int maxReturn(vector<int> V){
    
    int ret = 0;
    for(int i=0; i<V.size(); i++){
        int minval=INT_MAX;
        for(int j=i; j<V.size(); j++){
            if(V[j]==0 || V[i]==0) break;
            if(minval > min(V[i],V[j]) ) minval = min(V[i],V[j]);
            if( ret < minval* (j-i+1) ) ret = ( minval* (j-i+1) );
        }
        
    }
    return ret;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int ret = 0;
    for(int i=0; i<A.size(); i++){
        int check = 0;
        for(int j=0; j<A[0].size(); j++){
            
            if( A[i][j]==1) {
                check++;
                if(check > ret) ret = check;
            }
            else check = 0;
            
            if(i!=0) {
                if(A[i][j]!=0){
                    A[i][j] = A[i-1][j] + 1;
                }
                else A[i][j] = 0;
            }
        }
    }
    for(int i=1; i<A.size(); i++){
        
        int fake = maxReturn(A[i]);
        if(ret < fake ) ret = fake;
    }
    return ret;
}

