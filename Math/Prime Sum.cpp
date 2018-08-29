// int is_prime(int x){
//     int count = int(sqrt(x));
//     for(int i=2; i<=count; i++){
//         if(i<x and x%i==0) return 0;
//     }
//     return 1;
// }

vector<int> Solution::primesum(int A) {
    
    vector<int> ret;
    // vector<int> temp;
    // for(int i=2; i<A; i++){
    //     int count = is_prime(i);
    //     if(count==1) temp.push_back(i);
    // }
    
    
    vector<int> ans;
    vector<bool> arr(A+1, true);
    arr[0] = false;
    arr[1] = false;
    // cout << "\n";
    for (int i = 2; i*i <= A; i++) {
        if (arr[i]){
            for(int j = 2; i*j <= A; j++) arr[i*j] = false;
        }
    }
    for(int i=0; i<arr.size(); i++){
        if(arr[i]){
            ans.push_back(i);
        }
    }
    // cout << "\n";
    int j= ans.size()-1;
    for(int i=0; i<ans.size(); i++){
        if( (ans[i] + ans[j]) > A){
            j--;
            i--;
        }
        else if((ans[i] + ans[j]) < A){
            continue;
        }
        else{
            ret.push_back(ans[i]);
            ret.push_back(ans[j]);
            return ret;
        }
    }
    // return ans;
}

