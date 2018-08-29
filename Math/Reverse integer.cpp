int Solution::reverse(int A) {
    
    if(A>=pow(2, 31) or A<=(-pow(2, 31))) return 0;
    
    long long int new_int=0;
    int temp = abs(A);
    // cout << temp << " abs \n";
    int count = 0;
    while(temp>0){
        count+=1;
        temp/=10;
    }
    
    temp = abs(A);
    // cout << temp << " " << count << " abs \n";
    while(temp>0 and count>0){
        new_int += (temp%10) * pow(10, count-1);
        // cout << temp%10 << " " << pow(10, count-1) << " power \n"; 
        temp/=10;
        count--;
    }
    // cout << new_int << " \n";
    
    if(new_int>=pow(2, 31) or new_int<=(-pow(2, 31))) return 0;
    
    if(A==abs(A)) return new_int;
    new_int = (-1) * new_int;
    return new_int;
}

