int Solution::bulbs(vector<int> &A) {
    
    if( A.size()==0 ) return 0;
    
    bool check = false;
    int ret = 0;
    for(int i=0; i<A.size(); i++){
        
        if( A[i]== 0 ){
            if( check ) continue;
            else{
                ret++;
                check = true;
            }
        }
        else{
            if( !check ) continue;
            else{
                ret++;
                check = false;
            }
        }
    }
    return ret;
}

