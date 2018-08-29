int just_ret(const vector<string> &A, int ind1, int ind2){
    
    map<char, int> hash;
    for(int i=ind1; i<3+ind1; i++){
        for(int j=ind2; j<3+ind2; j++){
            if(A[i][j]=='.') continue;
            if( hash.find(A[i][j]) == hash.end() ){
                hash.insert( make_pair( A[i][j], i ) );
            }
            else return 0;
        }
    }
    return 1;
}

int Solution::isValidSudoku(const vector<string> &A) {
    
    // for(int i=0; i<9; i++){
    //     cout << A[i] << " \n";
    // }
    for(int i=0; i<9; i++){
        map<char, int> hash;
        for(int j=0; j<9; j++){
            if(A[i][j]=='.') continue;
            if( hash.find(A[i][j]) == hash.end() ){
                hash.insert( make_pair( A[i][j], i ) );
            }
            else {
                
                // cout << i << " " << j << " " << A[i][j] <<  " 1st";
                return 0;
            }
        }
    }
    for(int i=0; i<9; i++){
        map<char, int> hash;
        for(int j=0; j<9; j++){
            if(A[j][i]=='.') continue;
            if( hash.find(A[j][i]) == hash.end() ){
                hash.insert( make_pair( A[j][i], j ) );
            }
            else {
                // cout << " 2nd";
                return 0;
            }
        }
    }
    
    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            
            int temp = just_ret(A, i, j);
            // cout << i << " " << j << " " << temp << " tmep \n";
            if(temp==0) {
                // cout << " 3rd";
                return 0;
            }
        }
    }
    return 1;
}

