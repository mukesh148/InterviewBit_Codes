vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    
    vector<int> ret;
    
    int i=0; 
    int j=0;
    while( i<A.size() and j<B.size() ){
        
        if( A[i] > B[j] ){
            j++;
        }
        else if( A[i] < B[j] ){
            i++;
        }
        else{
            ret.push_back(A[i]);
            i++;
            j++;
        }
        
    }
    return ret;
}

