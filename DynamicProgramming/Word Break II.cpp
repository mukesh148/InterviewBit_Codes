vector<string> breakWord(int index,string &A,unordered_map<string,int>&hash){
    
    vector<string> sentence;
    for(int i=index; i<A.length(); i++){
        
        string str = A.substr(index, i-index+1);
        if(hash.find(str)!=hash.end()){
            vector<string> vec = breakWord(i+1, A, hash);
            
            if(vec.size()==0) sentence.push_back(str);
            else {
                for(int j=0; j<vec.size(); j++){
                sentence.push_back(str + " " + vec[j]);
                }
            }
        }
    }
    return sentence;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {

    unordered_map<string, int> hash;
    for(int i=0; i<B.size(); i++){
        hash[B[i]] = 1;
    }
    vector<string> ret = breakWord(0, A, hash);
    for(int i=0; i<ret.size(); i++){
        int count =0;
        for(char x : ret[i]) if(x!=' ') count++;
        if(count!=A.length()) {
            ret.erase(ret.begin()+i);
            i--;
        }
    }
    return ret;
}

