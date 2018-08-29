string give_dot(string temp, int *i){
    
    string ret="";
    // int i=0;
    while( *i<temp.length() and temp[*i] != '.' ){
        ret+= temp[*i];
        *i+= 1;
    }
    return ret;
}

int find_big( string A, string B ){
    
    int i=0, j=0;
    while( i<A.length()){
        
        if(A[i]!='0'){
            break;
        }
        i++;
    }
    while( j<B.length()){
        
        if(B[j]!='0'){
            break;
        }
        j++;
    }
    if( (A.length() - i) > (B.length() - j) ) return 1;
    if( (A.length() - i) < (B.length() - j) ) return -1;

    if( (A.length() - i) == (B.length() - j) ){
        while( i<A.length() and j<B.length() ){
            
            int c1 = (int) (A[i]-'0');
            int c2 = (int) (B[j]-'0');
            if( c1>c2 ) return 1;
            if( c2>c1 ) return -1;
            i++;
            j++;
        }
    }
    // while( i< A.length() ) {
    //     return 1;
    // }
    // while( j< B.length() ) {
    //     return -1;
    // }
    return 0;
}

int Solution::compareVersion(string A, string B) {
    
    int i=0;
    int j=0;
    long long int c1=0, c2=0;
    while( i<A.length() && j<B.length() ){
        
        string v1 = give_dot(A, &i);
        string v2 = give_dot(B, &j);
        i++;
        j++;
        // cout << v1 << " " <<  i << " " << v2 << " " << j << " \n";
        int num = find_big( v1, v2 );
        // cout << num << " int vale \n";
        if( num == 1 ) return 1;
        if( num == -1 ) return -1;
    }
    while( i < A.length() ) {
        string v1 = give_dot(A, &i);
        i++;
        int num = find_big( v1, "0" );
        if( num == 1) return 1;
    }
    while( j < B.length() ) {
        string v2 = give_dot(B, &j);
        j++;
        int num = find_big( "0", v2 );
        if( num == -1) return -1;
    }

    return 0;
}

