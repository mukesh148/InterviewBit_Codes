void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size()-1;
    int count=0;
    while(count != A.size()-1){
        for(int i=0; i<(n-2*count); i++){
            int temp1 = A[n-i-count][count];
            int temp2 = A[count][count+i];
            int temp3 = A[count+i][n-count];
            int temp4 = A[n-count][n-i-count];
            A[count][count+i] = temp1;
            A[count+i][n-count] = temp2;
            A[n-count][n-i-count] = temp3;
            A[n-i-count][count] = temp4;
        }
        count+=1;
    }
}

