int Solution::solve(int A) {
    
    // vector<int> W(A+1, -1);
    // vector<int> Y(A+1, -1);
    long long int temp1 = 24;
    long long int temp2 = 12;
    long long int temp = 0;
    // W[1] = 24;
    // Y[1] = 12;
    for(int i=2; i<=A; i++){
        // long long int temp1 = 10*Y[i-1] + 11*W[i-1];
        // long long int temp2 = 7*Y[i-1] + 5*W[i-1];
        // temp1 %= 1000000007;
        // temp2 %= 1000000007;
        // W[i] = temp1;
        // Y[i] = temp2;
        temp = temp1;
        temp1 = ( 10 * temp2 + 11 * temp1 ) % 1000000007;
        temp2 = ( 7 * temp2 + 5 * temp ) % 1000000007;
    }
    // long long int ret = (temp1 + temp2) % 1000000007;
    return (temp1 + temp2) % 1000000007;
}

