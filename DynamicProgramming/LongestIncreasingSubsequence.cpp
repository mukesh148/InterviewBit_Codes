int Solution::lis(const vector<int> &A) {
    
    vector<pair<int, int> > vec(A.size());
    vec[A.size()-1] = make_pair(1, A[A.size()-1]);
    for(int i=A.size()-2; i>=0; i--){
        
        sort(vec.begin() + i + 1, vec.end());
        reverse(vec.begin() + i + 1, vec.end());
        
        for(int j=i+1; j<A.size(); j++){
            
            if( A[i] < vec[j].second){
                vec[i].first = vec[j].first + 1;
                break;
            }
            else {
                vec[i].first = 1;
            }
        }
        vec[i].second = A[i];
    }
    sort(vec.begin(), vec.end());
    return vec[A.size()-1].first;
}

