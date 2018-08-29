int fact(int x, int y, int z){
    if(x==0 or x==y) return 1;
    return ( x * fact(x-1, y, z-1) ) / z;
}
int Solution::uniquePaths(int A, int B) {
    
    int count = A+B-2;
    int max_num = max(A, B);
    int min_num = min(A,B);
    long long int ans = fact(count, max_num-1, min_num-1);
    return ans;
}

