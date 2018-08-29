int Solution::isPalindrome(string A) {
    
    int low = 0;
    int high = A.length()-1;
    while(low < high){
        int chec1=0, chec2=0;
        if( A[low] >= 'a' and A[low] <= 'z' ) chec1 = A[low] - 'a';
        else if( A[low] >= 'A' and A[low] <= 'Z' ) chec1 = A[low] - 'A';
        else if( A[low] >= '0' and A[low] <= '9' ) chec1 = A[low] - '0';
        else {
            low++; 
            continue;
        }
        if(low == high) return 1;
        
        if( A[high] >= 'a' and A[high] <= 'z' ) chec2 = A[high] - 'a';
        else if( A[high] >= 'A' and A[high] <= 'Z' ) chec2 = A[high] - 'A';
        else if( A[high] >= '0' and A[high] <= '9' ) chec2 = A[high] - '0';
        else {
            high--;
            continue;   
        }
        if(low == high) return 1;
        
        if( chec1 == chec2 ) {
            low++;
            high--;
        }
        else return 0;
    }
    return 1;
}


/*
int Solution::isPalindrome(string A) {
    
    int low = 0;
    int high = A.length()-1;
    while(low < high){
        int chec1=0, chec2=0;
        if( A[low] >= 'a' and A[low] <= 'z' ) chec1 = A[low] - 'a';
        else if( A[low] >= 'A' and A[low] <= 'Z' ) chec1 = A[low] - 'A';
        else if( A[low] >= '0' and A[low] <= '9' ) chec1 = A[low] - '0';
        else {
            low++; 
            continue;
        }
        if(low == high) return 1;
        
        if( A[high] >= 'a' and A[high] <= 'z' ) chec2 = A[high] - 'a';
        else if( A[high] >= 'A' and A[high] <= 'Z' ) chec2 = A[high] - 'A';
        else if( A[high] >= '0' and A[high] <= '9' ) chec2 = A[high] - '0';
        else {
            high--;
            continue;   
        }
        if(low == high) return 1;
        
        if( chec1 == chec2 ) {
            low++;
            high--;
        }
        else return 0;
    }
    return 1;
}

*/
