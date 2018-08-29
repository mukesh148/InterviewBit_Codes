void gencomb(vector<vector<int> >&ret, int index, vector<int>&ans, int B, int sum, vector<int>&unique){
    
    if(sum>B) return;
    if(sum==B){
        ret.push_back(ans);
        return;
    }
    for(int i=index; i<unique.size(); i++){
        ans.push_back(unique[i]);
        sum+= unique[i];
        gencomb(ret, i+1, ans, B, sum, unique);
        ans.pop_back();
        sum-= unique[i];
        while((i+1)<unique.size() && unique[i]==unique[i+1]) i++;
        
    }
    
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    
    sort(A.begin(), A.end());
    vector<vector<int> > ret;
    vector<int> ans;
    gencomb(ret, 0, ans, B, 0, A);
    // sort(ret.begin(), ret.end());
    return ret;
    
}

