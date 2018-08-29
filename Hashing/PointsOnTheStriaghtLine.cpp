int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    
    int ret = 0;
    int n = A.size();
    if(n<2) return n;
    for(int i=0; i<n ;i++){
        
        int a = A[i];
        int b = B[i];
        unordered_map<double, int> hash;
        for(int j=0; j<n; j++){
            
            if(i==j) continue;
            
            int c = A[j];
            int d = B[j];
            double slope = 0;
            
            if(c!=a) slope = (double)(d-b)/(c-a);
            else slope = INT_MAX;
            
            // cout << A[i] << " " << B[i] << " " << A[j] << " " << B[j] << " " << slope << " slope \n";
            
            if( hash.find(slope)==hash.end() ){
                hash[slope] = 2;
                if(hash[slope]>ret) ret = hash[slope];
            }
            else{
                hash[slope]++;
                if(hash[slope]>ret) ret = hash[slope];
            }
        }
        
    }
    return ret;
}

