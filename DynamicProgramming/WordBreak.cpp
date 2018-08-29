// bool breakWord(int index, string &A, unordered_map<string, int> &hash, string &s){
    
//     bool result = false;
//     if( s==A ) return true;
//     for(int i=index; i<A.length(); i++){
//         string str = A.substr(index, i-index+1);
//         // s += A.substr(index, i-index+1);
//         if(hash.find(str)!=hash.end()){
//             s += str;
//             result |= breakWord(i+1, A, hash, s);
            
//         }
//     }
//     return result;
// }

// bool Break(string str, unordered_map<string, int> &hash)
// {
//     int size = str.size();
//     if (size == 0)  return true;
//     for (int i=1; i<=size; i++)
//     {
//         if (hash.find( str.substr(0, i) )!=hash.end() &&
//             Break( str.substr(i, size-i), hash ))
//             return true;
//     }
//     return false;
// }

// bool breakWord( string &s, unordered_map<string, int> &hash){
    
//     int size = s.length();
//     if(size == 0) return false;
    
//     vector<bool> dp(size, 0);
//     for(int i=0; i<size; i++){
        
//         if( dp[i]==0 && hash.find(s.substr(0, i+1))!=hash.end() ) dp[i] = 1;
        
//         if(dp[i] && i==size-1) return 1;
//         if(dp[i]){
            
//             for(int j=i+1; j<size; j++){
                
//                 if(dp[j]==0 && hash.find(s.substr(i+1, j-i))!=hash.end() ) dp[j]=1;
                
//                 if(dp[j] && j==size-1) return 1;
                
//             }
            
//         }
        
//     }
//     return 0;
// }

bool breakWord( string &s, unordered_map<string, int> &hash){
    
    int size = s.length();
    if(size == 0) return false;
    
    vector<bool> dp(size, 0);
    vector<int> index;
    index.push_back(-1);
    
    for(int i=0; i<size; i++){
        
        int msize = index.size();
        int flag = 0;
        for(int j=msize-1; j>=0; j--){
            
            
            string str = s.substr( index[j]+1, j - index[j] );
            if( hash.find(str)!= hash.end() ){
                flag = 1;
                break;
            }
            
        }
        if(flag==1){
            dp[i] = 1;
            index.push_back(i);
        }
        
    }
    return dp[size-1];
}

int Solution::wordBreak(string A, vector<string> &B) {
    
    // A = A.substr(0, A.length()-1);
    unordered_map<string, int> hash;
    for(int i=0; i<B.size(); i++){
        hash[B[i]] = 1;
    }
    // string s = "";
    return breakWord(A, hash);
}

