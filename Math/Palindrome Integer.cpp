int Solution::isPalindrome(int A) {
    
    int new_int=0;
    int temp = A;
    int count = 0;
    while(temp>0){
        count+=1;
        temp/=10;
    }
    // cout << count << " count \n";
    temp = A;
    while(temp>0 and count>0){
        // cout << (temp%10) << " " << count << " p \n";
        new_int += (temp%10) * pow(10, count-1);
        // cout << (temp%10) << " " << count << " " << pow(10, count-1) << " p \n";
        temp/=10;
        count--;
    }
    // cout << new_int << " \n";
    if(new_int == A) return 1;
    return 0;
    
    // return new_int;
}

