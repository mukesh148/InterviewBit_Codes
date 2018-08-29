int give_bin_count(int x){
    if(x==0) return 1;
    int count = 0;
    while(x>0){
        count+=1;
        x/=2;
    }
    return count;
}
string give_bin(int x, int y){
    // if(x==0) return to_string(0);
    string ret;
    while(x>0){
        ret+= to_string(x%2);
        x/=2;
    }
    while(ret.length() != y){
        ret+= to_string(0);
    }
    // reverse(ret.begin(), ret.end());
    return ret;
}

int Solution::hammingDistance(const vector<int> &A) {
    
    int max_ele = *max_element(A.begin(), A.end());
    int max_ele_count = give_bin_count(max_ele);
    // vector<string> temp(A.size());
    // for(int i=0; i<A.size(); i++){
    //     temp[i] = give_bin(A[i], max_ele_count);
    // }
    // int count = 0;
    // for(int i=0; i<A.size(); i++){
    //     for(int j=i; j<A.size(); j++){
    //         for(int k=0; k<max_ele_count; k++){
    //             if( temp[i][k]!=temp[j][k] ) count++;
    //         }
    //     }
    // }
    
    // for(int i=0; i<A.size(); i++){
    //     temp[i] = give_bin(A[i], max_ele_count);
    // }
    int count = 0;
    
    for(int k=0; k<max_ele_count; k++){
        int x=0, y=0;
        for(int i=0; i<A.size(); i++){
            string a = give_bin(A[i], max_ele_count);    
            if(a[k]=='0') x++;
            if(a[k]=='1') y++;
        }
        count+= 2*x*y;
    }
    return count;
}

// int Solution::hammingDistance(const vector<int> &A) {
// long long sum = 0;
//     for(int i=0; i<=31; i++){
//         int x=0, y=0;
//         int t = 1<<i;
//         for(int j=0; j<A.size(); j++){
//             if(A[j]&t){
//                 x++;
//             }else{
//                 y++;
//             }
//         }
        
//         sum += (long long)2*(long long)x*(long long)y;
//         sum %= 1000000007;
//     }
//     return (int)sum;
// }
