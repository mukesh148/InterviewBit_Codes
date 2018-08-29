vector<int> Merge(vector<int> &L, vector<int> &R, vector<int> &D){
    int l = L.size();
    int r = R.size();
    int i=0, j=0, k=0;
    
    while(i<l and j<r){
        if(L[i]<=R[j]){
            D[k] = L[i];
            i++;
        }
        else{
            D[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<l){
        D[k] = L[i];
        i++; k++;
    }
    while(j<r){
        D[k] = R[j];
        j++; k++;
    }
    return D;
}

vector<int> MergeSort(vector<int> &F){
    
    int n = F.size();
    if(n<2){
        return F;
    }
    int mid = n/2;
    vector<int> left(mid);
    vector<int> right(n-mid);
    for(int i=0; i<mid; i++){
        left[i] = F[i];
    }
    for(int i=mid; i<n; i++){
        right[i-mid] = F[i];
    }
    MergeSort(left);
    MergeSort(right);
    Merge(left, right, F);
    
    return F;
}

int Solution::solve(vector<int> &A) {
    
    
    vector<int> check;
    // vector<int> c1(4);
    // vector<int> c2(4);
    // vector<int> c3(8);
    check = MergeSort(A);
    // c1[0]=1 ;c1[1]= 2;c1[2]= 4;c1[3]= 6;
    // c2[0]=3 ;c2[1]= 5;c2[2]= 7;c2[3]= 8;
    // check = Merge(c1,c2,c3);
    // for(int i=0; i<check.size(); i++){
    //     cout << check[i] << "\n";
    // }
    if(check[check.size()-1]==0) return 1;
    for(int i=0; i<check.size(); i++){
        if(A[i]!=A[i+1] and A[i]==check.size()-1-i) return 1;
    }
    return -1;
    
    // for(int i=0; i<c1.size(); i++){
    //     cout << c1[i] << "\n";
    // }
    // for(int i=0; i<A.size(); i++){
    //     int count=0;
    //     for(int j=0; j<A.size(); j++){
    //         if(A[i]<A[j]){
    //             count++;
    //         }
    //     }
    //     if(count==A[i]) return 1;
    // }
    // return -1;
    // return 0;
}

