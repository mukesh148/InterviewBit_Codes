bool isPossible(vector<int> &C, long long int page, long long int D){
    
    long long int curr_page = 0;
    int curr_stu = 1;
    for(int i=0; i<C.size(); i++){
        
        if( curr_page + C[i] > page){
            curr_stu++;
            if(curr_stu > D) return 0;    
            curr_page = 0;
            i--;
        }
        else {
            curr_page+= C[i];
        }
    }
    return 1;
}

int Solution::books(vector<int> &A, int B) {
    
    long long int low = 0;
    long long int high = 0;
    long long int ans = 0;
    
    if(A.size() < B or A.size() == 0) return -1;
    
    for(int i=0; i<A.size(); i++) { high+= (long long)A[i]; }
    while(low<=high){
        long long int mid = (low + high) /2;
        if( isPossible(A, mid, B) ){
            high = mid - 1;
            ans = mid;
        }
        else {
            low = mid + 1 ;
        }
    }
    return ans; 
}


// int mod = 10000003;
// int check(long long int A,long long int B, vector<int> &C,long long int Time) {
//     long long int curTime = 0;
//     int curPainter = 1;
//     for(int i=0;i<C.size();i++) {
//         if(curTime + C[i]*B > Time) {
//             curPainter++;
//             if(curPainter > A) {
//                 return 0;
//             }
//             curTime = 0;
//             i--;
//         } else {
//             curTime += C[i]*B;
//         }
//     }
//     return 1;
// }
// int Solution::paint(int A, int B, vector<int> &C) {
//     long long int low = 0;
//     long long int high = 0;
//     for(int i=0; i<C.size(); i++) high += ((long long)B)*C[i];
//     int ans;
//     while(low<=high) {
//         long long int mid = (low+high)/2;
//         if(check(A,B,C,mid)) {
//             high = mid-1;
//             ans = mid%mod;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }
