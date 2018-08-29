int Solution::removeDuplicates(vector<int> &A) {
    
    int i=0;
    int j=0;
    int k=A.size()-1;
    while( j<A.size() && k>=0 && j<k) {
        
        while( (k-1)>=0 && A[k]==A[k-1]) k--;
        while( (j+1)<A.size() && A[j]==A[j+1]) j++;
        if(j>=k) break;
        if(i==j){
            i++;
            j++;
        }
        else{
            swap( A[i], A[k] );
            k--;
            i = i+1;
            j=i;
        }
    }
    int itr = i;
    sort(A.begin(), A.begin()+itr+1);
    
    for(int m=itr+1; m<A.size(); i++){
        A.pop_back();
    }
    
    int len = A.size();
    return len;
    
}

