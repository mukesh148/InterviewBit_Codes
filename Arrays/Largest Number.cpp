vector<int> give_num(int x){
    vector<int> ret; 
    if(x==0) {
        ret.push_back(0);
        return ret;
    }
    
    while(x!=0){
        ret.push_back(x%10);
        x/=10;
    }
    return ret;
}

void sort_row(vector<int> &B, int y, int counte){
    
    if(counte==B.size()-1) return;
    
    vector<int> fin_ele = give_num(B[B.size()-(y-1)-counte]);
    vector<int> prev_ele = give_num(B[B.size()-y-counte]);
    bool bul = (fin_ele.size() - y == -1 and prev_ele[prev_ele.size() - y] == 0);
    bool bul1 = (fin_ele.size() - y == -1 and prev_ele[prev_ele.size() - y] > fin_ele[fin_ele.size() - y +1]);
    
    bool bul2 = (fin_ele[fin_ele.size() - y] == 0 and prev_ele.size() - y == -1);
    bool bul3 = (fin_ele[fin_ele.size() - y] > prev_ele[prev_ele.size() - y +1] and prev_ele.size() - y == -1);

    bool check;
    if( prev_ele.size() - y != -1 ){
        check = fin_ele[fin_ele.size()-y] > prev_ele[prev_ele.size()-y];
    }
    else {
        check = true and bul3;
    }
    
    if( (check or bul or bul3 ) and (!bul1 or !bul2)){  
        int any_v = B[B.size()-1-counte];
        B[B.size()-1-counte] = B[B.size()-2-counte];
        B[B.size()-2-counte] = any_v;
        // fin_ele.clear();
        // prev_ele.clear();
        // fin_ele = vector<int>();
        // prev_ele = vector<int>();
    }
    else if(fin_ele[fin_ele.size()-y] == prev_ele[prev_ele.size()-y]){
        sort_row(B, y+1, counte);
    }
    sort_row(B, y, counte+1);
    fin_ele = vector<int> ();
    prev_ele = vector<int> ();
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector<vector<int> > V(10, vector<int> ());
    
    for(int i=0; i<A.size(); i++){
        vector<int> count= give_num(A[i]);
        // if()
        V[count[count.size()-1]].push_back(A[i]);
        if(V[count[count.size()-1]].size()>1 and count[count.size()-1] != 0){
            //count =2 in func
            sort_row(V[count[count.size()-1]], 2, 0);
        }
        // count.clear();
        // vector<int>().swap(count);
        // count.clear();
        // count.shrink_to_fit();
    }
    // count = vector<int> ();
    string muku;
    // vector<int> temp;
    if(V[0].size()==A.size()) { muku.append(to_string(0)); return muku; }
    for(int i=9; i>=0; i--){
        // cout << V[i].size() << " \n";
        if(V[i].size()>0){
            for(int j=0; j<V[i].size(); j++){
                // temp.push_back(V[i][j]);
                muku.append( to_string(V[i][j]) );
            }
        }
    }
    for(int i=0; i<V[9].size(); i++){
        cout << V[9][i] << "\n";
    }
    // cout << V[3][i] << " \n";
    V = vector<vector<int> > ();
    // temp = vector<int > ();
    return muku;
}

