int Solution::gcd(int A, int B) {
    
    if(A==0 or B==0){
        if(A==0) return B;
        if(B==0) return A;
    }
    int min_val = min(A, B);
    vector<int> temp;
    int count = 0;
    for(int i=1; i<= sqrt(min_val); i++){
        if(min_val%i == 0){
            temp.push_back(i);
        }
        if(i == sqrt(min_val)) count--;
    }
    count += temp.size()-1;
    for(int i=count; i>=0; i--){
        temp.push_back( min_val/temp[i] );
    }
    for(int i= temp.size()-1; i>=0; i--){
        if( max(A, B)%temp[i]==0 ) return temp[i];
    }
    
    return 0;
}

