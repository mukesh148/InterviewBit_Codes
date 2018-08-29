int Solution::removeElement(vector<int> &A, int B) {
    
    // int low=0;
    // int high=0;
    // while( high < A.size() && low < A.size() ){
        
    //     while( high < A.size() and A[high] == B) high++;
    //     if(high >= A.size()) break;
    //     if(A[low] != B){
    //         low++;
    //         high++;
    //     }
    //     else{
    //         swap(A[low], A[high]);
    //         low++;
    //         high++;
    //     }
    // }
    // return low;
    int count = 0;
    for(int i=0; i<A.size(); i++){
        
        if(A[i]!=B){
            A[count]= A[i];
            count++;
        }
        else{
            continue;
        }
    }
    
    return count;
}
