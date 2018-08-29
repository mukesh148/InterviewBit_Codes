int factorial(int x){
    if(x == 0 ) return 1;
    return x*(factorial(x-1) % 1000003);
}

int Solution::findRank(string A) {
    
    int str[58] = {0};
    
    for(int i=0; i<A.length(); i++){
        int x = A[i] - 'A';
        str[x]++;
    }
    // for(int i=0; i<58; i++){
    //     cout << str[i] << " " ;
    // }
    // cout << "\n";
    int count = 0;
    int n = A.length();
    for(int i=0; i<n-1; i++){
        long long int count_new = 0;
        long long int itr = 0;
        int x = A[i] - 'A';
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j]) itr++;
        }
        long long int temp = factorial(n - 1 - i)% 1000003; 
        for(int k=0; k<58; k++){
            if(str[k]>1){
                temp /= factorial(str[k]);
            }
        }
        
        count_new += itr * temp ;
        // cout << itr << " " << factorial(n - 1 - i) << " " << count_new << " previous \n";
        // for(int k=0; k<58; k++){
        //     if(str[k]>1){
        //         count_new /= factorial(str[k]);
        //     }
        // }
        // for(int i=0; i<26; i++){
        //     cout << str[i] << " " ;
        // }
        // cout << "\n";
        str[x]--;
        count += count_new;
        // cout << count_new << " " << count << " after \n";
    }
    return (count+1);
}

