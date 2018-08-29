// int give_num(int x, int y){
    
//     int count = 0;
//     int check = (x | y) & (~x | ~y);
//     for(int i=31; i>=0; i--){
        
//         // bool b1 = ( (1<<i) & x );
//         // bool b2 = ( (1<<i) & y );
         
//         bool temp = check & (1<<i) ;
//         if(temp) count++;
//     }
//     return count;
// }

int Solution::cntBits(vector<int> &A) {
    
    long long int ret=0;
    vector<int> v_0(32,0);
    vector<int> v_1(32,0);
    for(int j=0; j<A.size(); j++){
        
        for(int i=31; i>=0; i--){
            bool temp = A[j] & (1<<i);
            if(temp) v_1[i] += 1;
            else v_0[i] += 1; 
        }
        
    }
    for(int i=0; i<32; i++){
        ret+= (long long )v_0[i] * (long long)v_1[i];
    }
    
    return (2 * ret) % 1000000007;
}

