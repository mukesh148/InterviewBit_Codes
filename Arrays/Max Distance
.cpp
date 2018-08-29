int Solution::maximumGap(const vector<int> &A) {
    
    if(A.size()==0) return -1;
    if(A.size()==1) return 0;
    
    int N = A.size();
    
    vector<pair<int, int> > vec;
    for(int i = 0; i < N; i++) {
        vec.push_back(make_pair(A[i], i));
    }
    sort(vec.begin(), vec.end());
    
    int l = vec.size();
    int ind_max = vec[l-1].second;
    int max_ = 0;
    
    for(int i=l-2; i>=0; i--){
        max_ = max(max_, ind_max - vec[i].second);
        ind_max = max(ind_max, vec[i].second);
    }
    
    
    // cout<< "\n" << vec.size() << "anything \n";
    // for (int i=0; i<vec.size(); i++)
    // {
    //     cout << vec[i].first << " "
    //          << vec[i].second << endl;
    // }
    // cout << vec.size() << " \n";
    
    // vector<int> temp;
    // for(int i=0; i<vec.size(); i++){
    //     temp.push_back(vec[vec.size() - 1 -i].second);
    // }
    
    // int max_=0;
    // // cout << "\n" << temp.size() << " size \n";
    // for(int i=temp.size(); i>0; i--){
    //     int count = ( temp.size()-1 ) - temp[i-1];
    //     // cout << count << "  value \n";
    //     if( max_ < count ) max_ = count;
    //     temp.pop_back();
    // }
    return max_;
}

