// long long int combination(int n, int k){
//     if( n <= k) return 1;
//     return ( n * combination(n-1, k) ) / (n-k) ;
// }

// int closest(int n){
//     long long int m = 0;
//     long long int s = 1;
//     while(n != 1){
//         n = n / 2;
//         m++;
//     }
//     return m;
// }

// int Solution::solve(int A) {
    
//     if( A<=1 ) return 1;
//     // int height = log(A) / log(2);
//     int height = closest(A);
//     int ideal_ele = pow(2, height);
//     int act_ele = A - (pow(2, height) - 1);
//     int L=0;
    
//     if( act_ele >= ideal_ele/2 ) L = pow(2, height) -1;
//     else L = pow(2, height) -1 - (ideal_ele/2 - act_ele); 
    
//     long long int x = combination(A-1, L);
//     long long int y = solve(L);
//     long long int z = solve(A-1-L);
//     return ( ( (x*y) % 1000000007) * z) % 1000000007;
// }
int closest(int n){
    long long int m = 0;
    long long int s = 1;
    while(n != 1){
        n = n / 2;
        m++;
    }
    return m;
}
long long int combination(int n,int r,int mod){
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[r];
}
int Solution::solve(int A) {
    if(A == 0){
        return 1;
    }
    else if(A == 1){
        return 1;
    }
    else{
        int k = closest(A);
        int M = 1 + A - pow(2,k);
        int p = pow(2,k-1);
        int l = p - 1 + min(p,M);
        int r = p - 1 + max(0,M-p);
        
        long long int x = combination(A-1,l,1000000007);
        cout << A << " " << l << " " << x<<endl;
        long long int y = solve(l);
        long long int z = solve(r);
        return (((x*y) % 1000000007)* z) % 1000000007;
    }
}



