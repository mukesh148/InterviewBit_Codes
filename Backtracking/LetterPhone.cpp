void gen_permu( vector<string> &ret, int index, string &A, vector<string> &arr, string &temp){
    
    if( temp.length()==A.length() ){
        ret.push_back(temp);
        return;
    }
    
    if( index==A.length() ) return;
    
    for(int i=index; i<A.length(); i++){
        
        int len = arr[(int)(A[i]-'0')].length();
        for(int j=0; j<len; j++){
            
            temp+= arr[(int)(A[i]-'0')][j];
            gen_permu(ret, i+1, A, arr, temp);
            temp.pop_back();
            
        }
    }
    
}

vector<string> Solution::letterCombinations(string A) {

    vector<string> arr = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    string temp="";
    gen_permu(ret, 0, A, arr, temp);
    // cout << temp << " arr \n";
    return ret;
    
}

