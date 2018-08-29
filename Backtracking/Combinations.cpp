void gencomb(vector<vector<int> >&ret, int index, vector<int>&ans, int B, int sum, vector<int>&unique){
    
    if(sum>B) return;
    if(sum==B){
        ret.push_back(ans);
    }
    
    for(int i=index; i<unique.size(); i++){
        ans.push_back(unique[i]);
        sum+= unique[i];
        gencomb(ret, i, ans, B, sum, unique);
        ans.pop_back();
        sum-= unique[i];
    }
    
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    sort(A.begin(), A.end());
    vector<vector<int> > ret;
    vector<int> ans;
    vector<int> unique;
    unique.push_back(A[0]);
    for(int i=1; i<A.size(); i++){
        if( (i-1)>=0 && A[i]!=A[i-1] ){
            unique.push_back(A[i]);
        }
    }
    gencomb(ret, 0, ans, B, 0, unique);
    sort(ret.begin(), ret.end());
    return ret;
}

