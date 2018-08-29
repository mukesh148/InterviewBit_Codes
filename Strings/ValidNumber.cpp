bool check_num_new(char x){
    if( ( x >= '0' and x <= '9') ){
        return true;
    }
    return false;
}
bool check_num(char x){
    if( ( x >= '0' and x <= '9') or x==' '){
        return true;
    }
    return false;
}

int Solution::isNumber(const string A) {
    
    if( A.length() == 0) return 0;
    bool ret = true;
    int count_dot = 0, count_e = 0, count_b = 0, count_a = 0;
    bool check_e = false;
    int n = A.length();
    bool check1 = false, check2 = false;
    
    for(int i=0; i<A.length(); i++){
        
        if( check_num_new(A[i]) and !check1 ){
            check1 = true;   
        }
        if( check1 and A[i]==' '){
            check2 = true;
        }
        if( (check1 & check2) and check_num_new(A[i]) ){
            cout << " come here \n";
            return 0;
        }
    }
    
    for(int i=0; i<A.length(); i++){
        
        bool check;
        
        if(A[i]=='.') count_dot++;
        if(A[i]=='.' and check_e) return 0;
        if(A[i]=='e') count_e++;
        if( (A[i]=='+' or A[i]=='-') and !check_e ) count_b++;
        if( (A[i]=='+' or A[i]=='-') and check_e ) count_a++;
        if(count_dot>1 or count_e>1 or count_a>1 or count_b>1) return 0;
        
        if( (i+1)<n and !check_num(A[i+1]) and A[i]=='.') return 0;
        
        check = check_num_new(A[i]);
        
        if( A[i] == 'e') check_e = true;
        if( (i+1)<n and check_num(A[i+1]) and A[i]=='.') check=true;
        if( (i+1)<n and check_num(A[i+1]) and A[i]=='e') check = true;
        if( (i+1)<n and check_num(A[i+1]) and (A[i]=='-' or A[i]=='+')) check = true;
        if( (i+2)<n and check_num(A[i+2]) and (A[i+1]=='-' or A[i+1]=='+') and A[i]=='e') check = true;
        ret = check & ret;
        // cout << ret << " " << i << " " <<  A[i] << " check \n";
        
    }
    if(ret) return 1;
    return 0;
}

