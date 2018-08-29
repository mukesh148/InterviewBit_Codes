int Solution::removeDuplicates(vector<int> &A) {
    
    if(A.size()==0 or A.size()==1 or A.size()==2) return A.size();
    int count = 0;
    for(int i=0; i<A.size(); i++){
        if((i+1)<A.size() && A[i]!=A[i+1]){
            A[count] = A[i];
            count++;
            continue;
        }
        
        if( i==A.size()-1 ){
            if(A[i]!=A[i-1]){
                A[count] = A[i];
                count++;
            }
        }
        
        int temp=0;
        while( (i+1)<A.size() && A[i]==A[i+1] ){
            if(temp<1){
                A[count] = A[i];
                count++;
                temp++;
                i++;
                A[count] = A[i];
                count++;
            }
            else i++;
        }
        
    }
    A.erase(A.begin()+count, A.end());
    return count;
    
}

