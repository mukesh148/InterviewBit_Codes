int binary_deci(vector<int> &A){
    
    int ret=0;
    for(int i=0; i<32; i++){
        
        ret+= A[i] * pow(2, 31-i);
        
    }
    return ret;
}

int Solution::singleNumber(const vector<int> &A) {

    // vector<int> B_0(32, 0);
    vector<int> B_1(32, 0);
    vector<int> B(32, 0);
    for(int i=0; i<A.size(); i++){
        
        for(int j=31; j>=0; j--){
            
            bool b = A[i] & ( 1 << j );
            if(b){
                B_1[31-j]+=1;
            }
        }
        
    }
    
    // for(int i=0; i<B_1.size(); i++){
    //     cout << B_1[i] << " ";
    // }
    // cout << "\n";
    for(int i=0; i<32; i++){
        
        if( B_1[i]%3 == 1 ){
            B[i]=1;
        }
        
    }
    // for(int i=0; i<32; i++){
    //     cout << B[i] << " ";
    // }
    // cout << "\n";
    // cout <<  << " num \n";
    
    return binary_deci(B);
    
}

