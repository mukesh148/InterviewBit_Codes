// int search_left(const vector<int> &C, int x, int ind){
//     int low = 0;
//     int high = ind;
//     while( low <= high){
//         if( C[low] == C[high] ) return low;
//         int mid = low + ( high - low)/2;
//         if( x == C[mid] ) high = mid;
//         else low = mid + 1;
//     }
//     return low;
// }
// int search_right(const vector<int> &C, int x, int ind){
//     int low = ind;
//     int high = C.size()-1;
    
//     while( low <= high){
//         if( C[low] == C[high] ) return high;
//         int mid = low + ( high - low)/2;
//         if( x == C[mid] ) low = mid;
//         else high = mid - 1;
//     }
//     return high;
// }
// int search_(const vector<int> &C, int x, int ind, bool val){
//     int low, high;
//     if(val) low = 0, high = ind; 
//     else low = ind, high = C.size()-1;
    
//     while( low <= high){
//         if( C[low] == C[high] ){
//             if(val) return low;
//             else return high;
//         }
//         int mid = low + ( high - low)/2;
//         if( x == C[mid] ){
//             if(val) high = mid;
//             else low = mid;
//         }
//         else{
//             if(val) low = mid + 1;
//             else high = mid - 1;
//         }
//     }
//     if(val) return low;
//     return high;
// }

// vector<int> binary_search(const vector<int> &C, int x){
    
//     int low = 0;
//     int high = C.size()-1;
//     int first, second;
//     vector<int> ret(2);
//     while( low <= high){
//         int mid = low + ( high - low)/2;
//         if( x == C[mid] ) {
//             first = mid;
//             second = mid;
//             if(x == C[mid-1]) first = search_(C, x, mid, 1);
//             if(x == C[mid+1]) second = search_(C, x, mid, 0);
//             ret[0]=first;
//             ret[1]=second;
//             return ret;
//         } 
//         else if( C[mid] > x ) high = mid - 1;
//         else low = mid + 1;
//     }
//     ret[0]=-1;
//     ret[1]=-1;
//     return ret;
// }
vector<int> Solution::searchRange(const vector<int> &A, int target) {
    
    // vector<int> ans;
    // ans = binary_search(A, B);
    // return ans;
    int n = A.size();
        int i = 0, j = n - 1;
        vector<int> ret(2, -1);
        // Search for the left one
        while (i < j)
        {
            int mid = (i + j) /2;
            if (A[mid] < target) i = mid + 1;
            else j = mid;
        }
        if (A[i]!=target) return ret;
        else ret[0] = i;

        // Search for the right one
        j = n-1;  // We don't have to set i to 0 the second time.
        while (i < j)
        {
            int mid = (i + j) /2 + 1;   // Make mid biased to the right
            if (A[mid] > target) j = mid - 1;  
            else i = mid;               // So that this won't make the search range stuck.
        }
        ret[1] = j;
        return ret; 
    
}

/*
vector<int> binary_search(const vector<int> &C, int x){
    
    int low = 0;
    int high = C.size()-1;
    vector<int> ret(2);
    while( low <= high){
        
        int mid = low + ( high - low)/2;
        
        if( x == C[mid] ) {
            int i = mid;
            int j = mid;
            while( x == C[i-1]){
                if( i == 0) break;
                i-= 1;
            }
            while( x == C[j+1]){
                j+= 1;
                if( j == C.size()-1) break;
            }
            ret[0]=i;
            ret[1]=j;
            return ret;
        } 
        
        else if( C[mid] > x ) high = mid - 1;
        else low = mid + 1;
    }
    ret[0]=-1;
    ret[1]=-1;
    return ret;
}
*/


