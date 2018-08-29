vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> ret(B,0);
    vector<int> temp;
    // fist number must be small
    if( A[0]=='I' ){
        ret[0] = 1;
        for(int i=2; i<=B; i++){
            temp.push_back(i);
        }
    }
    //// fist number must be bigger
    else{
        ret[0] = B;
        for(int i=1; i<=B-1; i++){
            temp.push_back(i);
        }
    }
    if(B==0 or B==1){
        return ret;
    }
    int count1=0, count2=0;
    for(int i=B-2; i>=0; i--){
        if(A[i]=='I'){
            // ret[i+1] = *max_element(temp.begin(), temp.end());
            ret[i+1] = temp[i+count2];
            // temp.erase(remove(temp.begin(), temp.end(), ret[i+1]), temp.end());
            count1+=1;
        }
        if(A[i]=='D'){
            // ret[i+1] = *min_element(temp.begin(), temp.end());
            ret[i+1] = temp[(B-2)-i-count1];
            // temp.erase(remove(temp.begin(), temp.end(), ret[i+1]), temp.end());
            count2+=1;
        }
    }
    return ret;
}

