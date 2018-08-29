void Solution::setZeroes(vector<vector<int> > &A) {
    
    vector<int> V1(A.size(),-1);
    vector<int> V2(A[0].size(),-1);
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            if(A[i][j]==0){
                V1[i]=i;
                V2[j]=j;
            }
        }
    }
    // for(int i=0; i<V1.size(); i++){
    //     cout<< V1[i] << " " ;
    // }
    // cout << " \n ";
    // for(int i=0; i<V2.size(); i++){
    //     cout<< V2[i] << " " ;
    // }
    
    for(int i=0; i<V1.size(); i++){
        if(V1[i]!=-1){
            for(int j=0; j<A[0].size(); j++){
                A[i][j]=0;
            }
        }
    }
    
    for(int i=0; i<V2.size(); i++){
        if(V2[i]!=-1){
            for(int j=0; j<A.size(); j++){
                A[j][i]=0;
            }
        }
    }
    
    // cout << "\n";
}

