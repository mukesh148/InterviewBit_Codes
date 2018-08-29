	string Solution::convertToTitle(int A) {
    
    string ret="";
    while(A>0){
        // cout << ch << "\n";
        char ch;
        if(A%26 == 0) {
            ch = 'Z';
            ret+= ch;
            A= A/26 - 1;
        }
        else{
            ch = char(A%26) + 'A' - 1 ;
            // cout << ch << " "<< A%26 << "\n";
            ret+= ch;
            A/=26;    
        }
        
        
    }
    reverse(ret.begin(), ret.end());
    return ret;
    
}

// string ans;
//     while (A) {
//         ans = char ((A - 1) % 26 + 'A') + ans;
//         // cout << ans << " \n";
//         A = (A - 1) / 26;
//     }
//     return ans;

