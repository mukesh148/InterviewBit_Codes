int Solution::anytwo(string A) {
    
    if(A.length()<=2) return 0;
    for(int i=0; i<A.length()-2; i++){
        char temp1, j=i+1;
        temp1 = A[i];
        // cout << " i - " << i << endl;
        while(j<A.length()-1 && A[j]!=temp1) j++;
        if(j == A.length()-1) continue;
        else{
            int k = i+1;
            unordered_map<char, int> hash;
            
            while( k<j && k<A.length()) {
                hash[A[k]] = 1;
                k++;
            }
            unordered_map<char, int> hash1;
            j++;
            while( j<A.length() ){
                if(A[j]==temp1) return 1;
                if(hash.find(A[j])!=hash.end()) return 1;
                if(hash1.find(A[j])==hash1.end()) hash1[A[j]]=1;
                else return 1;
                j++;
            }
        }
    }
    return 0;
}

