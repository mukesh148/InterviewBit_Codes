vector<int> Solution::findSubstring(string A, const vector<string> &B) {

    vector<int> ret;
    map<string, int> hash;
    for(int i=0; i<B.size(); i++){
        if( hash.find(B[i])==hash.end() ){
            hash[B[i]]=1;
        }
        else hash[B[i]]++;
    }
    
    int len = B[0].size();
    for(int i=0; i<A.size(); i++){
        
        map<string, int> hash_copy = hash;
        string temp = A.substr(i, len);
        if( hash_copy.find(temp)==hash_copy.end() ) continue;
        
        int j = i;
        int total = 0;
        while( total!= B.size() ){
            if( hash_copy[A.substr(i, len)]<=0 || hash_copy.find(A.substr(i, len))==hash_copy.end() ) break;
            else{
                hash_copy[A.substr(i, len)]--;
                total++;
                i+= len;
            }
        }
        if(total == B.size() ){
            ret.push_back(j);
        }
        i = j;
    }
    return ret;
}

