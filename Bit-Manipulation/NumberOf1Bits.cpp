int Solution::numSetBits(unsigned int A) {
    
    int count = 0;
    for(int i=31; i>=0; i--){
        bool temp = A & (1 << i);
        cout << temp << " " << i << " \n";
        if(temp) count++;
    }
    return count;
}

