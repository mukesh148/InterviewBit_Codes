vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ret; 
    map<int, int> hash;
    
    int n = A.size();
    int high = n-1;
    
    for(int i=n-1; i>=0; i--){
        int sum_ = B[i] + A[high];
        if(hash.find(sum_)!=hash.end()){
            hash[sum_]++;
        }
        else hash[sum_] = 1;
    }
    
    int check = false;
    for(int i=n-2; i>=0; i--){
        
        for(int j=n-1; j>=0; j--){
            
            int sum_ = B[j] + A[i];
            // cout << sum_ << " sum_ again \n";    
            if( (hash.begin())->first >= sum_ ){
                check = true;
                break;
            }
            else{
                int temp = (hash.begin())->first;
                cout << temp << " erase \n";
                if( hash[temp] > 1 ) {
                    hash[temp]--;
                    if( hash.find(sum_)!= hash.end() ) hash[sum_]++;
                    else hash[sum_] = 1;
                }
                else {
                    hash.erase(temp);
                    hash[sum_] = j;
                }
            }
        }
        if(check) break;
    }
    
    for (map<int,int>::iterator it = hash.begin(); it != hash.end(); ++it) {
        int temp = it->first;
        while( hash[temp]!=0 ){
            cout << temp << " show \n";
            hash[temp]--;
            ret.push_back(temp);
            // if(ret.size()==n){
            //     sort(ret.begin(), ret.end());
            //     reverse(ret.begin(), ret.end());                
            //     return ret;
            // }
        }
         
    }
    sort(ret.begin(), ret.end());
    reverse(ret.begin(), ret.end());
    return ret;
}

