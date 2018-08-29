// void repeat_(vector<int> &B, int x, int y){
//     if(B[x] == y) {
//         // B[x] =  
//         return;
//     }
//     repeat_(B, B[x], y);
    
//     // int temp = B[x];
//     B[x] = B[B[x]];
// }

void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0; i<A.size(); i++){
        A[i] += (A[A[i]]%n ) * n;
        // A[i] /= n;
    }
    for(int i=0; i<A.size(); i++){
        // A[i] += (A[A[i]]%n ) * n;
        A[i] /= n;
    }
}

