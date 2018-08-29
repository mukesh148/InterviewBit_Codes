int Solution::numTrees(int A) {
    
    vector<int> vec(A+1,0);
    vec[1] = 1;
    vec[0] = 1;
    
    for(int i=2; i<=A; i++){
        for(int j=1; j<=i; j++){
            int left = j-1;
            int right = i-j;
            vec[i] += vec[left] * vec[right];
        }
    }
    return vec[A];
}

