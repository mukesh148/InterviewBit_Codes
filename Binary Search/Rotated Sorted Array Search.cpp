// int binary_search(const vector<int> &C, int x, int a, int b){
    
//     int low = a;
//     int high = b;
//     while( low <= high){
        
//         int mid = low + ( high - low)/2; 
//         if( x == C[mid] ) return mid; 
//         else if( C[mid] > x ) high = mid - 1;
//         else low = mid + 1;
//     }
//     return -1;
// }

// int pivot_search(const vector<int> &C){
    
//     int low = 0;
//     int n = C.size();
//     int high = n-1;
    
//     if(C[low] <= C[high]) return low;
    
//     while( low <= high){
        
//         int mid = low + ( high - low)/2;
//         int next = ( mid + 1 ) % n;
//         int prev = ( mid - 1 + n ) % n;
//         if( C[mid] < C[prev] && C[mid] < C[next]) return mid;
//         if( C[mid] >= C[high] ) low = mid + 1 ;
//         else high = mid - 1;
//     }
//     return low;
// }


int binary_search_modified(const vector<int> &C, int x){
    
    int low = 0, high = C.size()-1;
    int mid = low + ( high - low)/2;
    int n = C.size();
    
    cout << low << " " << high << " first \n";
    if(C[mid] > x){
        if(C[0] <= x){
            low = 0; 
            // high = mid - 1 ;
            high = mid;
        }   
        else {
            low = mid;
            // low = mid + 1;
            high = n - 1;
        }
    }
    else{
        if(C[n-1] >= x){
            low = mid; 
            high = n-1 ;
        }   
        else {
            low = 0;
            high = mid;
        }
        
    }
    cout << low << " " << high << " second \n";
    while( low <= high){
        
        mid = low + ( high - low)/2; 
        if( x == C[mid] ) return mid; 
        else if( C[mid] > x ) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    
    // int ans, n, low, high;
    // n = A.size();
    // ans = pivot_search(A);
    // if(A[n-1] < B){
    //     low = 0;
    //     high = ans - 1;
    // }
    // else {
    //     low = ans;
    //     high = n - 1;
    // }
    // int ret = binary_search(A, B, low, high);
    int ret; 
    ret = binary_search_modified(A, B);
    return ret;
}

