void count_path(vector<vector<int> > &A, int ind1, int ind2, int &ret){
    
    if( ind1==A.size()-1 && ind2==A[0].size()-1 ){
        ret++;
        return;
    }
    
    if( A[ind1][ind2] == 1) return;
    if( (ind2+1)<A[0].size() && A[ind1][ind2+1]!= 1 ) count_path(A, ind1, ind2+1, ret);
    if( (ind1+1)<A.size() && A[ind1+1][ind2]!= 1 ) count_path(A, ind1+1, ind2, ret);
    
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    if(A.size()==1 && A[0].size()==1 ) return 0;
    int ret = 0;
    count_path(A, 0, 0, ret);
    return ret;
}

