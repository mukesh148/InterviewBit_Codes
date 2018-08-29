int Solution::minimumTotal(vector<vector<int> > &A) {
    
    vector<vector<int> > vec = A;
    int row = vec.size();
    for(int i=row-1; i>=0; i--){
        for(int j=0; j<vec[i].size(); j++){
            
            if(i==row-1) vec[i][j] = A[i][j];
            else{
                vec[i][j] = A[i][j]+ min(vec[i+1][j], vec[i+1][j+1]);
            }
        }
    }
    return vec[0][0];
}

