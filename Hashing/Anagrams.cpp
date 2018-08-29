// bool isSame(string &A, string &B){
    
//     if(A.length()!= B.length()) return false;
//     map<char, int> hash;
//     for(int i=0; i<A.length(); i++){
//         if(hash.find(A[i])==hash.end()){
//             hash.insert( make_pair(A[i], i) );
//         }
//     }
//     for(int i=0; i<B.length(); i++){
//         if(hash.find(B[i])==hash.end()){
//             return false;
//         }
//     }
//     return true;
// }

void sort_str(string &A){
    
    int chararr[26] = {0};
    for(int i=0; i<A.length(); i++){
        chararr[A[i]-'a']++;
    }
    string temp="";
    for(int i=0; i<26; i++){
        for(int j=0; j<chararr[i]; j++) temp+= char('a'+i);
    }
    A = temp;
    return;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    vector<vector<int> > ret;
    
    unordered_map<string, int> hash;
    int count = 0;
    for(int i=0; i<A.size(); i++){
        
        string temp = A[i];
        sort_str(temp);
        
        if( hash.find(temp)== hash.end() ){
            hash.insert(make_pair(temp, count));    
            vector<int> arr;
            arr.push_back(i+1);
            ret.push_back(arr);
            count++;
        }
        else{
            int var = hash[temp];
            ret[var].push_back(i+1);
        }
    }
    
    return ret;
}

