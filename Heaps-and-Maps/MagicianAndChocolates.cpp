int Solution::nchoc(int A, vector<int> &B) {
    
    priority_queue<int> hash;
    for(int i=0; i<B.size(); i++){
        hash.push(B[i]);
    }
    
    int ret=0;
    while(A>0){
        
        ret = (ret + hash.top() % 1000000007) % 1000000007;
        int temp = hash.top();
        hash.pop();
        hash.push(floor(temp/2));
        A--;
    }
    return ret;
}

