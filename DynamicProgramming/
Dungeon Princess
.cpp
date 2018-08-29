int Solution::calculateMinimumHP(vector<vector<int> > &A) {

    int row = A.size(), col = A[0].size();
    vector<vector<int>> vec( row+1, vector<int>(col+1, 0) );
    
    
    for(int i=row-1; i>=0; i--){
        for(int j=col-1; j>=0; j--){
            
            if(i==row-1 || j==col-1){
                vec[i][j] = min( min(0, A[i][j]+vec[i+1][j]), min(0, A[i][j]+vec[i][j+1]) );
            }
            else{
                vec[i][j] = max( min(0, A[i][j]+vec[i+1][j]), min(0, A[i][j]+vec[i][j+1]) );
            }
            
        }
    }    
    
    // for(int i=0; i<=row; i++){
    //     for(int j=0; j<=col; j++){
    //         cout << vec[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
    
    return abs(vec[0][0])+1;
}

/*
int row = A.size(), col = A[0].size();
    int check1 = INT_MAX, check2 = INT_MAX;
    vector<vector<int> vec(row+1, vector<pair<int, int>>(col+1, make_pair(0,INT_MIN)));
    
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
           
           if( A[i-1][j-1] + vec[i-1][j].first > vec[i][j-1].second ){
               vec[i][j].first = A[i-1][j-1] + vec[i-1][j].first;
               if( vec[i][j].first < INT_MAX ) check1 = vec[i][j].first;
               vec[i][j].second = check1;
           }
           else if( A[i-1][j-1] + vec[i][j-1].first > vec[i-1][j].second ){
               vec[i][j].first = A[i-1][j-1] + vec[i][j-1].first;
               if( vec[i][j].first < INT_MAX ) check2 = vec[i][j].first;
               vec[i][j].second = check2;
           }
           else{
               int temp = (vec[i-1][j].second > vec[i][j-1].second) ? 1 : 0 ;
               if(temp){
                    vec[i][j].first = A[i-1][j-1] + vec[i-1][j].first;
                    vec[i][j].second = vec[i-1][j].second;
               }
               else{
                    vec[i][j].first = A[i-1][j-1] + vec[i][j-1].first;
                    vec[i][j].second = vec[i][j-1].second;
               }
           }
            
        }
    }
*/
