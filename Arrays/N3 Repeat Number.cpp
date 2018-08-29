int Solution::repeatedNumber(const vector<int> &A) {
    if (A.size() == 0) return 0;
    vector<int> add_ele(2);
    vector<int> add_count(2,0);
    add_ele[0] = A[0];
    add_count[0] = 1;
    add_count[1] = -1;
    int n = A.size();
    for(int i=1; i<n; i++){
        if(A[i]==add_ele[0]){
            add_count[0]+=1;
        }
        else if(add_count[1]!=-1) {
            if(A[i]==add_ele[1]) add_count[1]++;
            else{
                add_count[1]--;
                add_count[0]--;
            }
        }
        else{
            add_ele[1] = A[i];
            add_count[1] = 1;
        }
        
        if(add_count[1]==0) add_count[1] = -1;
        if(add_count[0]==0){
            if(add_count[1]!=-1){
                add_ele[0] = add_ele[1];
                add_count[0] = add_count[1];
                add_count[1] = -1;
            }
            else if(i < A.size()-1){
                add_ele[0] = A[i+1];
                add_count[0] = 1;
                i++;
            }
        }
        cout << i << " ";
    }
    cout << add_ele[0] << " " << add_ele[1] << " \n" ;
    add_count[0] = 0, add_count[1] = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == add_ele[0]) add_count[0]++;
        if (A[i] == add_ele[1]) add_count[1]++;
    }
    if (add_count[0] > (double)A.size()/3.0) return add_ele[0];
    else if (add_count[1] > (double)A.size()/3.0) return add_ele[1];
    else return -1;
    
    // return -1;
}



