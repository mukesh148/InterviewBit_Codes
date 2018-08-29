int Solution::repeatedNumber(const vector<int> &A) {
        
    int arraySize = A.size();
    if (arraySize <= 1) {
        return -1;
    }
    int slow = A[0];
    int fast = A[A[0]];
    
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    fast = 0;
    while (fast != slow) {
        slow = A[slow];
        fast = A[fast];
    }
    
    return fast;
    
}


//   vector<int> B = A;
//     sort(B.begin(), B.end());
//     for(int i=B.size()-1; i>0; i--){
//         if(B[i]==B[i-1]) return B[i];
//         else B.pop_back();
//     }
//     return -1;
