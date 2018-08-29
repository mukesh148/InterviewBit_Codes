unsigned int Solution::reverse(unsigned int A) {
    
    unsigned int ret = 0;
    for(int i=31; i>=0; i--){
        bool temp = A & ( 1 << i );
        ret+= temp * pow(2, 31-i);    
    }
    return ret;
}

