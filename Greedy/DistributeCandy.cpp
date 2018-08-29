int Solution::candy(vector<int> &ratings) {
    
    int candiesCnt = 0, curCandy, pos;
    vector<pair<int, int> > valueWithPos; 
    for (int i = 0; i < ratings.size(); i++) {
        valueWithPos.push_back(make_pair(ratings[i], i));
    }
    sort(valueWithPos.begin(), valueWithPos.end());
    vector<int> candies (ratings.size(), 0);
    for (int i = 0; i < valueWithPos.size(); i++) {
        pos = valueWithPos[i].second;
        curCandy = 0;
        if (pos > 0 && ratings[pos - 1] < ratings[pos]) {
            curCandy = candies[pos - 1];
        } 
        if (pos < ratings.size() - 1 && ratings[pos + 1] < ratings[pos]) {
            curCandy = max(curCandy, candies[pos + 1]);
        }
        candies[pos] = curCandy + 1;
        candiesCnt += candies[pos];
    }
    return candiesCnt;
}

