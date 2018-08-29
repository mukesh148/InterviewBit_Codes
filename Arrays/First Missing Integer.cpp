// int give_max(vector<int> B){
//     int count_max = 1;
//     for(int i=0; i<B.size(); i++){
//         if(B[i]>count_max) count_max= B[i];
//     }
//     return count_max;
// }

// void do_zero(vector<int> &B, int x){
//     if(B[x]<0 or B[x]-1==x or x<0) return;
    
//     int temp=B[B[x]-1];
//     B[B[x]-1] = B[x];
//     B[x] = 0;
//     do_zero(B, temp);
    
// }

int Solution::firstMissingPositive(vector<int> &A) {
    
    
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
    
    
    // int count=1;
    // count = give_max(A);
    // vector<int> temp(count+2,-1);
    
    // do_zero(A, 0);
    // for(int i=0; i<A.size(); i++){
    //     cout << A[i] << " ";
    // }
    // cout << "\n";
    
    // // do_zero(A, 2);
    // // do_zero(A, 4);
    // for(int i=0; i<A.size(); i++){
    //     int j=i;
    //     do_zero(A, j);
    // }
    // for(int i=0; i<A.size(); i++){
    //     cout << A[i] << " ";
    // }
    // cout << "\n";
}


// int count=0, sum=0;
//     int ret=0;
//     for(int i=0; i<A.size(); i++){
//         if(A[i]<=0){
//             count+=1;
//             A[i]=0;
//         }
//         sum+= A[i];
//     }
//     // int count_max;
//     // count_max = give_max(A);
//     // cout<< count_max << " max \n";
//     // cout<< A.size() << " max \n";
//     // int new_int = A.size()-count_max;
//     // cout << new_int << " priunt \n";
//     // for(int i=count_max-(count-1); i>abs(new_int); i--){
//     //     ret+= i;
//     // }
//     for(int i=0; i<(A.size()-(count-1)); i++){
//         ret+= i+1;
//     }
//     // cout<< ret << " ret \n";
//     // cout<< sum << " sum \n";
//     ret = ret - sum;
    
//     return ret;
