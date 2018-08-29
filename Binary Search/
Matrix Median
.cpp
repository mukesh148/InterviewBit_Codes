// int Solution::findMedian(vector<vector<int> > &A) {
    
//     int row = A.size(), col = A[0].size();
//     vector<int> vec;
//     int temp=A[0][0], count = 0, ind_temp = 0;
//     int num = (row*col)/2;
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             if( vec.size() != num+1){
//                 if(A[i][j] > temp) {
//                     temp = A[i][j];
//                     ind_temp = count;
//                 }
//                 vec.push_back(A[i][j]);
//                 count++;
//             }
//             else if(A[i][j] < temp){
//                     // vec.erase(remove(vec.begin(), vec.end(), temp), vec.end());
//                     vec[ind_temp] = A[i][j];
                    
//                     auto temp_ind = max_element(vec.begin(), vec.end());
//                     temp = *temp_ind;
//                     ind_temp = distance( begin(vec), temp_ind);
                    
//                     // vec.push_back(A[i][j]);
//             }
//             else break;
//         }
//     }
//     temp = *max_element(vec.begin(), vec.end());
//     return temp;
// }



int Solution::findMedian(vector<vector<int> > &A) {
    int l = 0, r = INT_MAX;
    int mid, req = (int)A.size() * (int)A[0].size();
    assert(req % 2);
    while(r - l > 1){
        mid = l + (r - l) / 2;
        int cnt = 0;
        for(auto &i: A){ 
            //using upper bound in a sorted array to count number of elements smaller than mid
            int p = upper_bound(i.begin(), i.end(), mid) - i.begin();
            cnt += p;
        }
        if(cnt >= (req/2 +1)) r = mid;
        else l = mid;
    }   
    return r;
}



