int binary_search(vector<int> &C, int x){
    
    int low = 0;
    int high = C.size()-1;
    while( low <= high){
        
        int mid = low + ( high - low)/2; 
        if( x == C[mid] ) return 1; 
        else if( C[mid] > x ) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int row = A.size(), col=A[0].size();
    // if(row==0 or col==0) return 0;
    
    int ind_row = -1;
    for(int i=0; i<A.size(); i++){
        if( B >= A[i][0] and B <= A[i][col-1] ){
            ind_row = i;
            break;
        }
    }
    if( ind_row == -1) return 0;
    // cout << ind_row << " ind \n";
    // for(int i=0; i<A[ind_row].size(); i++){
    //     cout << A[ind_row][i] << " ";
    // }
    // cout << "\n";
    int ans = binary_search( A[ind_row], B );
    // cout << ans << " ans \n";
    
    return ans;
    
}

