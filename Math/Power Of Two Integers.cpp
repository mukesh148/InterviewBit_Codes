int Solution::isPower(int A) {
    if(A==1) return 1;
    if(A==2) return 0;
    for(int i=2; i<=32; i++){
        float count = pow(A, 1.0/i);
        float frac, intpart;
        frac = modf (count , &intpart);
        if( frac == 0) return 1;
    }
    return 0;
}

