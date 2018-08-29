int give_max(vector<int> &B, int x, int y){
    int count = x;
    for(int i=x+1; i<y+1; i++){
        if( B[i]<B[count] and B[i]>=B[x-1] ) count = i;
    }
    return count; 
}

void Solution::nextPermutation(vector<int> &A) {
    
    if(A.size()==1 or A.size()==0) return;
    int count=0, i=0, ind, just_max_num;
    for(i=A.size()-1; i>0; i--){
        if(A[i]>A[i-1]){
            count +=1;
            break;
        }
    }
    
    // cout << i << " i \n";
    
    if(count == 0){
        sort(A.begin(), A.end());
        return;
    }
    just_max_num = give_max(A, i, A.size()-1);
    // cout << just_max_num << " num \n";
    swap(A[i-1], A[just_max_num]);
    sort(A.begin()+i, A.end());
}

