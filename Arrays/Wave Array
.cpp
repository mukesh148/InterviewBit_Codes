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

vector<int> Solution::wave(vector<int> &A) {
    
    vector<int> ret;
    ret = MergeSort(A);
    
    for(int i=0; i<ret.size(); i+=2){
        
        if(ret.size()%2 != 0 and i == ret.size()-1){
            break;
        }
        
        int num = ret[i];
        ret[i] = ret[i+1];
        ret[i+1] = num;
    }
    
    return ret;
}

