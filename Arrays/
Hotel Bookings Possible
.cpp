// template <typename T>
// vector<size_t> sort_indexes(const vector<T> &v) {

//   // initialize original index locations
//   vector<size_t> idx(v.size());
//   iota(idx.begin(), idx.end(), 0);

//   // sort indexes based on comparing values in v
//   sort(idx.begin(), idx.end(),
//       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

//   return idx;
// }

// int give_count(vector<int> &A, vector<int> &B, vector<int> &C){
    
//     int count=1; //i needed
//     int x=0;
//     for(int i=1; i<A.size(); i++){
//         // if(B[i-1]<=A[i] and A[i]!=A[i-1]) {
//         //     // cout << " nooo \n ";
//         //     count+=0;
//         // }
//         // else if(A[i]>=C[x] and A[i]!=B[i]){
//         //     // cout << " came \n ";
//         //     x+=1;
//         //     count+=0;
//         // }
//         // else {
//         //     // cout << " inc \n ";
//         //     count+=1;
//         // }
        
//         if(A[i] >= B[i-1]){
//             // count+=0;
//             cout << count << " " << C[x] << " " << i << " " ;
//             cout << "case 1 \n";
//             if(B[i-1]==C[x]){
//                 x+=1;
//                 cout << count << " " << C[x] << " " << i << " " ;
//                 cout << "case 2 \n";
//             }
//         }
//         else{
//             if(A[i] >= C[x]) {
//                 x+=1;
//                 // count+=0;
//                 cout << count << " " << C[x] << " " << i << " " ;
//                 cout << "case 3 \n";
//             }
//             else{
//                 count+=1;
//                 cout << count << " " << C[x] << " " << i << " " ;
//                 cout << "case 4 \n";
                
//             }
//         }
        
        
//     }
//     return count;
// }

// bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
//     vector<int> A;
//     vector<int> B;
//     vector<int> C;
//     // int c_count = 0;
//     for (auto i: sort_indexes(arrive)) {
//         A.push_back(arrive[i]);
//         B.push_back(depart[i]);
//     }
//     for (auto i: sort_indexes(depart)) {
//         C.push_back(depart[i]);
//     }
    
//     // for(int i=0; i<A.size(); i++){
//     //     cout << A[i] << " " ;
//     // }
//     // cout << "\n";
//     // for(int i=0; i<B.size(); i++){
//     //     cout << B[i] << " " ;
//     // }
//     // cout << "\n";
//     // for(int i=0; i<C.size(); i++){
//     //     cout << C[i] << " " ;
//     // }
//     // cout << "\n";
//     int count=1; //i needed
//     int x=0;
//     for(int i=1; i<A.size(); i++){
//         count+=1;
        
//         if(A[i] >= B[i-1]){
//             count-=1;
//         }
//         else{
//             if(A[i] >= C[x] and A[i]!=B[i]) {
//                 x+=1;
//                 count-=1;
//             }
//         }
//         if(B[i]==C[x]){
//             x+=1;
//         }
//         // cout << "("<< i << ","<< count << ") ";
//         if(count>K) return false;
//     }
//     // cout << "\n";
//     // for(int i=0; i<A.size(); i++){
//     //     cout << A[i] << " " ;
//     // }
//     // cout << "\n";
//     // for(int i=0; i<B.size(); i++){
//     //     cout << B[i] << " " ;
//     // }
//     // cout << "\n";
//     // for(int i=0; i<C.size(); i++){
//     //     cout << C[i] << " " ;
//     // }
//     // cout << "\n";
//     // cout << count << "\n";
//     // cout << c_count << "\n";
//     return true;
// }

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K){
    
    if(K == 0)
        return false;

    int N = arrive.size();
        
    vector<pair<int, int> > vec;
    for(int i = 0; i < N; i++) {
        vec.push_back(make_pair(arrive[i], 1));
        vec.push_back(make_pair(depart[i], 0));
    }
    
    for (int i=0; i<vec.size(); i++)
    {
        cout << vec[i].first << " "
             << vec[i].second << endl;
    }
    
    sort(vec.begin(), vec.end());
    
    cout<< "\n" << vec.size() << "anything \n";
    for (int i=0; i<vec.size(); i++)
    {
        cout << vec[i].first << " "
             << vec[i].second << endl;
    }
    
    int curActive = 0;
    int maxAns = 0;
    for (int i = 0; i < vec.size(); i++) {
       if (vec[i].second == 1) { // arrival
           curActive++;
           maxAns = max(maxAns, curActive);
        } else {
            curActive--;
        }
    }
    if (K >= maxAns) return true;
    return false;
        
}


