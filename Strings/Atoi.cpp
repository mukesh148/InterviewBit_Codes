bool isNum(char x){
    if( x >= '0' & x <= '9' ) return true;
    return false;
}

int conver_int( string &A ){
    
    int count = 0;
    long long int ret = 0;
    int n = A.length();
    
    if( A[0]=='+' ){
        count = 1;
        n-=1;
    }
    else if( A[0]=='-' ){
        count = -1;
        n-=1;
    }
    
    if(n > 10){
        if(count == -1) return INT_MIN;
        if(count == 1 or count == 0) return INT_MAX;
    } 
    
    int end = (A.length() - n);
    for(int i = A.length() - 1; i >= end; i--){
        
        ret += (long long)( pow(10, A.length()-1-i) * ( A[i] - '0' ) );
    }
    d
    if( count == -1){
        ret = -ret;
        if(ret <= INT_MIN) return INT_MIN;
        return ret;
    }
    if( count == 1){
        if(ret >= INT_MAX) return INT_MAX;
        return ret;
    }
    if( count == 0) {
        if(ret >= INT_MAX) return INT_MAX;
        return ret;
    }
    return ret;
}

int Solution::atoi(const string A) {
    
    int ret=0;
    string temp = "";
    bool space = false;
    int count_min = 0;
    
    
    for(int i=0; i<A.length(); i++){
        
        if( A[i]=='-' or A[i]=='+' ){
            count_min+= 1;
            if(count_min > 1) {
                if(temp.length()==0) return 0;
                else return conver_int(temp);
            }
            if( (i+1)<A.length() and !isNum(A[i+1]) ) {
                if(temp.length()==0) return 0;
                else return conver_int(temp);
            }
            temp+= A[i];
            continue;
        }
        
        if( A[i] == ' ' and space){
            break;
        }
        else if( A[i] == ' ' and !space){
            continue;
        }
        else if( isNum(A[i]) ){
            temp+= A[i];
            space = true;
        }
        else{
            break;
        }
        
    }
    ret = conver_int(temp);
    
    return ret;
}

