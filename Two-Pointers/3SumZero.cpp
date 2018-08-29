vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    sort( A.begin(), A.end() );
    vector<vector<int> > ret;
    
    for(int i=0; i<A.size(); i++){
        
        if( (i-1)>=0 and A[i-1]==A[i]) {
            continue;
        } 
        int prev = i+1;
        int next = A.size()-1;
        while(prev<next){
            vector<int> temp;
            int check = A[i] + A[prev] + A[next];
            if(check == 0){
                temp.push_back(A[i]);
                temp.push_back(A[prev]);
                temp.push_back(A[next]);
                ret.push_back(temp);
                while( A[prev] == A[prev+1]) prev++;
                while( A[next] == A[next-1]) next--;
                prev++;
                next--;
            }
            else if( check > 0) next--;
            else prev++;
        }
    }
    return ret;
}

