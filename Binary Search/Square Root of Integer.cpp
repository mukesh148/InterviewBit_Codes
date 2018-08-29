int give_sqrt(int x){
    if(x==0) return 0;
    long long int low= 1, high = 1;
    long long int pow_num = 1;
    
    while( pow_num * pow_num < x ){
        pow_num *= 2;
        if(pow_num  * pow_num >= x){
    
            if(pow_num  * pow_num == x) return pow_num;
            high = pow_num;
            low = high/2;
            break;
    
        } 
    }
    while(low != high - 1){
        long long int mid = low + (high-low)/2;
        if( mid*mid == x) return mid;
        else if(mid * mid > x) high = mid;
        else low = mid;
    }
    return low;
}

int Solution::sqrt(int A) {
    return give_sqrt(A);
}

