vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    vector<vector<int> > ret;
    sort(A.begin(), A.end());
    
    // for(int i=0; i<A.size(); i++){
    //     cout << A[i] << " ";
    // }
    // cout << " \n";
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            // vector<int> temp;
            // temp.push_back(A[i]);
            // temp.push_back(A[j]);    
            int low = j+1;
            int high = A.size()-1;
            int low_ = -1;
            
            while( low < high ){
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[j]);
                if( A[i]+A[j]+A[low]+A[high] == B ){
                    if( low_==-1 || A[low_]!=A[low]) {
                        temp.push_back(A[low]);
                        temp.push_back(A[high]);
                        ret.push_back(temp);
                        low_ = low;
                    }
                    
                    low++;
                    high--;
                }
                else if(A[i]+A[j]+A[low]+A[high] < B){
                    low++;
                }
                else{
                    high--;
                }
            }
            while( (j+1)<A.size() && A[j]==A[j+1] ) j++;
        }
        
        while( (i+1)<A.size() && A[i]==A[i+1] ) i++;
        
    }
    
    return ret;
}

