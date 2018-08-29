int Solution::trailingZeroes(int A) {
    
    int count5 = 0;
    int itr = 1;
    while( pow(5, itr) <= A ){
        int temp = pow(5, itr);
        count5+= A/temp;
        itr++;
    }
    return count5;;
}

