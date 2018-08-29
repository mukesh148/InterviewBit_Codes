int factorial(int x){
    if(x == 0 ) return 1;
    return x*(factorial(x-1)% 1000003);
}

int Solution::findRank(string A) {
    
    long long int count = 0;
    
    int n = A.length();
    for(int i=0; i<n-1; i++){
        long long int itr=0;
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j]) itr++;
        }
        count +=  (itr * factorial(n - 1 - i));
    }
    return (count+1)%1000003;
}

