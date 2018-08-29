vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // long long nom_diff=0, sq_diff=0, nom_sum, sum_n=0, sum_n2=0, doub_num, mis_num, n;
    // long long arr_nom_sum=0, arr_sq_sum=0;
    long long nom_diff=0, sq_diff=0, nom_sum;
    int doub_num, mis_num;
    for(int i=0; i<A.size(); i++){
        // arr_nom_sum+= A[i];
        // arr_sq_sum+= pow(A[i],2);
        // sum_n+= i+1;
        // sum_n2+= pow(i+1,2);
        nom_diff+= A[i] - (i+1);
        sq_diff+= ((long long)A[i] * (long long)A[i]) - ((long long)(i+1) * (long long)(i+1));
    }
    // n = A.size();
    // sum_n = (n*(n+1))/2;
    // sum_n2 = (n*(n+1)*(2*n+1))/6;
    // nom_diff = arr_nom_sum - sum_n;
    // sq_diff = arr_sq_sum - sum_n2;
    nom_sum = (sq_diff / nom_diff);
    doub_num = (nom_diff+nom_sum)/2;
    mis_num = nom_sum - doub_num;
    
    vector<int> B;
    B.push_back(doub_num);
    B.push_back(mis_num);
    return B;
}

