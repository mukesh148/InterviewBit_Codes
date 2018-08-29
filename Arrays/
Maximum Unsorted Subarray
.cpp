int give_min(vector<int> &A, int x, int y){
    int count=A[x], ind=x;
    for(int i=x; i<y+1; i++){
        if(A[i]<count) {
            count = A[i];
            ind = i;
        }
    }
    return ind;
}
int give_max(vector<int> &A, int x, int y){
    int count=A[x], ind=x;
    for(int i=x; i<y+1; i++){
        if(A[i]>count) {
            count = A[i];
            ind = i;
        }
    }
    return ind;
}

vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> ret;
    for(int i=0; i<A.size()-1; i++){
        
        // if(A[i]==A[i+1] and ret.size()>0){
        //     ret.push_back(i);
        //     cout << i << " first \n";
        //     if(ret.size()>=3) {
        //         ret[1] = ret[2];
        //         ret.pop_back();
        //     }
        // }
        
        if(A[i]>A[i+1]){
            ret.push_back(i);
            // cout << i << " second \n";
            if(ret.size()>=3) {
                ret[1] = ret[2];
                ret.pop_back();
            }
        }
    }
    if(ret.size()>0){
        int count = ret[ret.size() - 1];
        for(int i=count+1; i<A.size()-1; i++){
            if(A[i]==A[i+1]) {
            ret.push_back(i);
            if(ret.size()>=3) {
                ret[1] = ret[2];
                ret.pop_back();
                }
            }
            else{
                break;
            }
        }
    }
    
    
    // cout << ret[0] << "\n";
    if(ret.size()==1) ret.push_back( ret[0]+1 );
    else if(ret.size()==2) ret[1]+=1;
    
    if(ret.size()==2){
        int ind = give_min(A, ret[0], ret[1]);
        // cout << A[ind] << " put \n";
        // cout << ret[0] << " " << ret[1] << "  \n";
        int count = ret[0];
        for(int i=0; i<count; i++){
            if(A[i] > A[ind]){
                ret[0] = i;
                break;
            }
        }
        int count1 = ret[1];
        int ind1 = give_max(A, ret[0], ret[1]);
        for(int i=count1; i<A.size(); i++){
            if(A[i] < A[ind1]){
                ret[1] = i;
                
            }
        }
    }
    
    if(ret.size()>1) return ret;
    else {
        ret.push_back(-1);
        return ret;
    }
    
}

// vector<int> B = A;
//     sort(B.begin(), B.end());
//     vector<int> ret;
    
//     for(int i=0; i<A.size(); i++){
//         if(A[i]!=B[i]) {
//             ret.push_back(i);
//             if(ret.size()>=3) {
//                 ret[1] = ret[2];
//                 ret.pop_back();
//             }
//         }
//     }
//     B.clear();
//     B = vector<int>();
    // if(ret.size()>1) return ret;
    // else {
    //     ret.push_back(-1);
    //     return ret;
    // }
