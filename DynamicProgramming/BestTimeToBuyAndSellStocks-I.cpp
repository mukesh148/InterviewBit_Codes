int Solution::maxProfit(const vector<int> &prices) {

    if (prices.size() <= 1) return 0;
    int K = 1;
    int maxProf = 0;
    vector<vector<int> > f(K+1, vector<int>(prices.size(), 0));
    
    for (int kk = 1; kk <= K; kk++) {
        int tmpMax = f[kk-1][0] - prices[0];
        for (int ii = 1; ii < prices.size(); ii++) {
            f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
            tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
            maxProf = max(f[kk][ii], maxProf);
        }
    }
     
    return maxProf;
}

