bool shouldSwap(vector<int> str, int start, int curr)
{
    for (int i = start; i < curr; i++) 
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void gen_permu(vector<vector<int> >&ret, int index, vector<int> &A){
    
    
    if(index == A.size()-1 ){
        ret.push_back(A);
        return;
    }
    
    for(int i=index; i<A.size(); i++){
        bool check = shouldSwap(A, index, i);
        if(check){
            swap(A[i], A[index]);
            gen_permu(ret, index+1, A);
            swap(A[i], A[index]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {

    vector<vector<int> >ret;
    gen_permu(ret, 0, A);
    cout << ret.size() << " size \n";
    return ret;
}

