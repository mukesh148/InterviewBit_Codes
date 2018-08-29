int roman(char s){
    
    switch(s){
        case 'I' :
            return 1;
            break;
        case 'V' :
            return 5;
            break;
        case 'X' :
            return 10;
            break;
        case 'L' :
            return 50;
            break;
        case 'C' :
            return 100;
            break;
        case 'D' :
            return 500;
            break;
        case 'M' :
            return 1000;
            break;
        default  :
            return 0;
    }
    
}

int Solution::romanToInt(string A) {
    
    int n = A.length();
    int ret=0;
    for(int i=0; i<n; i++){
        
        if( (i+1) < n and roman(A[i]) < roman(A[i+1]) ){
            ret+= roman(A[i+1]) - roman(A[i]);
            i++;
        }
        else ret+= roman(A[i]);
        
    }
    
    return ret;
}

