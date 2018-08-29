int Solution::titleToNumber(string A) {
    
    // for(int i=0; i<A.length(); i++){
    //     char ch;
    //     ch = A[i];
    //     cout << int(ch) << "\n";
    // }
    
    int count = 0;
    for(int i=0; i<A.length()-1; i++){
        count += pow(26, i+1);
    }
    for(int i=0; i<A.length()-1; i++){
        
        char ch;
        int itr;
        ch = A[i];
        itr = int(ch) - 64 ;
        count += (itr-1)*pow(26, A.length()-1-i);
        
    }    
    char ch;
    ch = A[ A.length()-1 ];
    int itr = int(ch) - 64;
    count+= itr;
    return count;
}

