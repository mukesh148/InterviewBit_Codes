string Solution::addBinary(string A, string B) {
    
    string ret="";
    int count = 0;
    int len_a = A.length()-1;
    int len_b = B.length()-1;
    // int itr = min( len_a, len_b ) - 1;
    // cout << len_a << " " << len_b << " len \n";
    while( len_a >= 0 and len_b >= 0 ){
        
        int val1 = (int)(A[len_a] - '0');
        int val2 = (int)(B[len_b] - '0');
        
        // cout << val1 << " " << val2 << " val \n";
        
        if( (val1 + val2 + count) == 3 ){
            ret =  "1"  + ret ;
            count = 1;
        } 
        else if( (val1 + val2 + count) == 2 ){
            ret =  "0"  + ret ;
            count = 1;
        }
        else{
            ret =  to_string( (val1 + val2 + count) )  + ret ;
            count = 0;
        }
        
        // cout << ret << " return \n";
        
        len_a--;
        len_b--;
    }
    // cout << len_a << " " << len_b << " len \n";
    if( len_a==-1 && len_b==-1 ) {
        if( count != 0) {
            ret = "1" + ret;
            return ret;
        }
        return ret;
    }
    while( len_a >= 0){
        int val = (int) (A[len_a] - '0');  
        if( (val + count) == 2 ){
            ret = "0" + ret;
            count = 1;
            // cout << " i ma here \n"; 
        }
        else{
            ret = to_string( (val + count) )  + ret;
            count = 0;
        }
        len_a--;
    }
    while( len_b >= 0){
        int val = (int) (B[len_b] - '0');
        if( (val + count) == 2 ){
            ret = "0" + ret;
            count = 1;
        }
        else{
            ret = to_string( (val + count) )  + ret;
            count = 0;
        }
        len_b--;
    }
    if(count == 1) ret = "1" + ret;
    return ret;
    
}

