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
            // else{
            //     B_0[31-j]+=1;
                
            // }
        }
        
    }
    
    // for(int i=0; i<B_0.size(); i++){
    //     cout << B_0[i] << " ";
    // }
    // cout << "\n";
    // for(int i=0; i<B_1.size(); i++){
    //     cout << B_1[i] << " ";
    // }
    // cout << "\n";
    for(int i=0; i<32; i++){
        
        if( B_1[i]%2 != 0 ){
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


/*
    // if(A.size()==1)
    vector<int> B = A;
    sort(B.begin(), B.end());
    for(int i=0; i<B.size(); i++){
        
        if(i==0){
            if(B[i]!=B[i+1]) return B[i];
        }
        else if(i==B.size()-1){
            if(B[i]!=B[i-1]) return B[i];
        }
        
        if( (i-1)>=0 and (i+1)<B.size() and B[i]!=B[i-1] and B[i]!=B[i+1] ){
            return B[i];
        }
    }
    return 0;
*/
