vector<int> Solution::equal(vector<int> &A) {
    
    unordered_map<int, string> hash;
    vector<int> ret;
    if(A.size()<4) return ret;
    int sum = 0;
    int low = INT_MAX;
    int high = INT_MAX;
    int low_ = INT_MAX;
    int high_ = INT_MAX;
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            
            if(hash.find(A[i]+A[j]) == hash.end()){
                string temp="";
                temp+= to_string(i);
                temp+= to_string(j);
                hash.insert( make_pair(A[i]+A[j], temp ) );
            }
            else{
                string temp = hash[A[i]+A[j]];
                int a = (int) (temp[0] - '0');
                int b = (int) (temp[1] - '0');
                if( (a!=i && a!=j && b!=i && b!=j) && (a<low || b<high) ) {
                    low = a; 
                    high = b;
                    low_ = i; 
                    high_ = j;
                }
                sum = A[i]+A[j];
            }
        }
    }
    ret.push_back(low);
    ret.push_back(high);
    ret.push_back(low_);
    ret.push_back(high_);
    return ret;
}

