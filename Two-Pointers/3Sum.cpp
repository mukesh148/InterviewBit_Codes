// int binary_search( vector<int> &C, int x){
//     long long int start = 0;
//     long long int end = C.size()-1;
    
//     while(start<=end){
//         long long int mid = start + ( end - start )/2;
//         if( C[mid] == x ) return mid;
//         else if( C[mid] > x) end = mid - 1;
//         else start = mid + 1;
//     }
//     return end;
// }

// int Solution::threeSumClosest(vector<int> &A, int B) {
    
//     sort(A.begin(), A.end());
    
//     // long long int ans = INT_MAX;
//     long long int j = binary_search( A, B);
//     long long int i=0, k=A.size()-1;
//     long long int ans = A[0]+A[1]+A[2];
//     // cout << i << " " << j << " " << k << " \n";
//     while( i<j && k>j ){
        
//         long long int temp = A[i] + A[j] + A[k];
        
//         long long int check1 = abs((long long)ans - (long long)B);
//         long long int check2 = abs((long long)temp - (long long)B);
//         // cout << check2 << " " << check1 << " check \n";
        
//         if( check2 < check1 ) ans = temp;
//         // cout << temp << " " << ans << " check \n";
//         if( temp == B ) return temp;
//         else if( temp < B) i++;
//         else k--;
//     }
    
//     if(i==j){
//         i += 1;
//         while( i<k ){
//             long long int temp = A[i] + A[j] + A[k];
//             long long int check1 = abs((long long)ans - (long long)B);
//             long long int check2 = abs((long long)temp - (long long)B);
//             if( check2 < check1 ) ans = temp;
//             if( temp == B ) return temp;
//             else if( temp < B) i++;
//             else k--;
//         }
//     }
//     else if(k==j){
//         k -= 1;
//         while( i<k ){
//             long long int temp = A[i] + A[j] + A[k];
//             long long int check1 = abs((long long)ans - (long long)B);
//             long long int check2 = abs((long long)temp - (long long)B);
//             // cout << check2 << " " << check1 << " check \n";
//             if( check2 < check1 ) ans = temp;
//             // cout << temp << " " << ans << " check \n";
//             if( temp == B ) return temp;
//             else if( temp < B) i++;
//             else k--;
//         }
//     }
//     return ans;
// }


/*
    int ans = INT_MAX;
    int i=0, j=1, k=2;
    ans = A[0] + A[1] + A[2];
    
    for(int i=3; i<A.size(); i++){
        
        if(ans == B) return ans;
        
        int temp = ans + A[i] - A[i-3];
        cout << temp << " temp " << ans << " ans \n";
        int check1 = abs( ans - B );
        int check2 = abs( temp - B );
        
        if( check2 < check1 ) ans = temp;
        
    }
    return ans;
*/

int Solution::threeSumClosest(vector<int> &num, int target){
    sort(num.begin(), num.end());
            int bestSum = 1000000000, sum = 0;
            // Fix the smallest number in the three integers
            for (int i = 0; i < num.size() - 2; i++) {
                // Now num[i] is the smallest number in the three integers in the solution
                int ptr1 = i + 1, ptr2 = num.size() - 1;
                while (ptr1 < ptr2) {
                    sum = num[i] + num[ptr1] + num[ptr2];
                    if (abs(target - sum) < abs(target - bestSum)) {
                        bestSum = sum;
                    }
                    if (sum > target) {
                        ptr2--;
                    } else {
                        ptr1++;
                    }
                }
            }
            return bestSum;
}

