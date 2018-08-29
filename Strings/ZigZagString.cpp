string Solution::convert(string A, int B) {
    
    if(B==1 or B==0) return A;
    // int skip_itr = (int) (2 * (B-2) + 1);
    // cout << skip_itr << "  skip \n";
    
    vector<int> skip_itr(B);
    skip_itr[0] = (int) (2 * (B-2) + 1);
    skip_itr[B-1] = (int) (2 * (B-2) + 1);
    for(int i=1; i<B-1; i++){
        skip_itr[i] = 2*(B-2-i)+1;
    }
    // for(int i=0; i<B; i++){
    //     cout << skip_itr[i] << " ";
    // }
    // cout <<  " \n";
    string ret="";
    // ret.push_back(A[0]);
    int count = 0;
    while(count < B){
        
        int count_check = 0;
        for(int i=0+count; i<A.length(); i++){
            
            ret+= A[i];
            
            if(count >= 1 and count <= B-2){
                
                if(count_check==0){
                    i+= skip_itr[count];    
                    count_check++;
                }
                else{
                    i+= skip_itr[0]-skip_itr[count]-1;
                    count_check = 0;
                }
            }
            else{
                i+= skip_itr[count];    
            }
        }
        count++;
    }
    return ret;
}

