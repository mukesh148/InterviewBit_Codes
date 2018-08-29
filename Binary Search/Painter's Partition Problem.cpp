// int Solution::paint(int A, int B, vector<int> &C) {
    
//     int n = C.size();
//     int temp_ = *max_element( C.begin(), C.end() );
//     if(A >= n) return ( B * temp_ )  % 10000003 ;
    
//     int j=0;
//     vector<int> temp;
//     int i;
//     for(i=0; i<n; i++){
//         if(temp.size() == A) break;
//         // temp[j] = C[i];
//         temp.push_back(C[i]);
//         int sz = temp.size();
//         int temp_max = *max_element( temp.begin(), temp.begin() + sz -1 );
        
//         while((temp[sz-1]+C[i+1])<=temp_max){
//             // cout <
//             temp[sz-1]+= C[i+1];
//             i++;
//         }
//     }
//     for(int j=0; j<A; j++){
//         cout << temp[j] << " ";
//     }
//     cout << "\n";
//     for(i=i; i<n; i++){
//         // int ver = *min_element( temp.begin(), temp.end() );
//         auto temp_ind = min_element(temp.begin(), temp.end());
//         int val = *temp_ind;
//         int ind_temp = distance( begin(temp), temp_ind);
//         temp[ind_temp]+= C[i];
//     }
//     for(int j=0; j<A; j++){
//         cout << temp[j] << " ";
//     }
//     cout << "\n";
//     long long int ret = *max_element( temp.begin(), temp.end() );
//     return ( B * ret ) % 10000003 ;
// }

// bool isPossible(int x, int z, int y, vector<int> &D){
    
//     vector<int> temp(x);
//     int j=0;
//     for(int i=0; i<D.size(); i++){
        
//         while(temp[j]*z <= y){
//             temp[j]+= D[i];
//             i++;
//             if(i == D.size()) break;
//         }
//         i--;
//         j++;
//         if(j > x and i < D.size()-1) return false;
//     }
//     return true;
// }

// int Solution::paint(int A, int B, vector<int> &C){
    
//     long long int min_ = 0, max_ = INT_MAX;
//     long long int mid;
//     int ans;
//     while(min_<=max_){
//         mid = (min_+max_)/2;
//         if(isPossible( A, B, mid, C )) {
//             max_ = mid - 1;      
//             ans = mid % 10000003;
//         }
//         else {
//             min_ = mid + 1;
//         }
//     }
    
//     return ans*B;
    
// }

int mod = 10000003;
int check(long long int A,long long int B, vector<int> &C,long long int Time) {
    long long int curTime = 0;
    int curPainter = 1;
    for(int i=0;i<C.size();i++) {
        if(curTime + C[i]*B > Time) {
            curPainter++;
            if(curPainter > A) {
                return 0;
            }
            curTime = 0;
            i--;
        } else {
            curTime += C[i]*B;
        }
    }
    return 1;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int low = 0;
    long long int high = 0;
    for(int i=0; i<C.size(); i++) high += ((long long)B)*C[i];
    int ans;
    while(low<=high) {
        long long int mid = (low+high)/2;
        if(check(A,B,C,mid)) {
            high = mid-1;
            ans = mid%mod;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


