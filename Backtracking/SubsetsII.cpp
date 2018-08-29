void gencomb(vector<vector<int> >&ret, int index, vector<int>&ans, vector<int>&unique){
    
    if( index == unique.size() ){
        ret.push_back(ans);
        return;
    }
    ret.push_back(ans);
    for(int i=index; i<unique.size(); i++){
        ans.push_back(unique[i]);
        gencomb(ret, i+1, ans, unique);
        ans.pop_back();
        while((i+1)<unique.size() && unique[i]==unique[i+1]) i++;
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {

    sort(A.begin(), A.end());
    vector<vector<int> > ret;
    vector<int> ans;
    gencomb(ret, 0, ans, A);
    return ret;    
    
}

