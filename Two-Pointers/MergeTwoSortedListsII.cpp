void Solution::merge(vector<int> &A, vector<int> &B) {
    
    vector<int> ret;
    
    int i=0;
    int j=0;
    while( i<A.size() and j<B.size() ){
        if(A[i] < B[j]) {
            ret.push_back(A[i]);
            i++;
        }
        else {
            ret.push_back(B[j]);
            j++;
        }
        
    }
    while( i< A.size()){
        ret.push_back(A[i]);
        i++;
    }
    while( j< B.size()){
        ret.push_back(B[j]);
        j++;
    }
    A = ret;
}

