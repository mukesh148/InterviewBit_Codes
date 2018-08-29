// void creatLPS(string &pat, vector<int> &lps){
//     lps[0] = 0;
//     int i =1, len = 0;
//     while (i < pat.length())
//     {
//         if (pat[i] == pat[len])
//         {
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else
//         {
//             if (len != 0) len = lps[len-1];
//             else
//             {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
// }

// int kmpSearch(string &A, string &B){
    
//     int a = A.length(), b = B.length();
//     if(b==0) return 0;
//     vector<int> lps(b);
//     creatLPS(B, lps);
    
//     // for(int k=0; k<lps.size(); k++){
//     //     cout << lps[k] << " ";
//     // }
//     cout << endl;
//     int i=0, j=0;
//     while(i < a){
//         if(A[i] == B[j]){
//             i++; 
//             j++;
//         }
//         if(j==b){
//             // cout << " got a match - " << i - j << endl;
//             j = lps[j-1];
//             return i - j;
//         }
//         else if( i<a && A[i]!=B[j] ){
//             if( j != 0 ) j = lps[j-1];
//             else i++;
//         }
//     }
    
//     return -1;
// }

int Solution::isMatch(const string A, const string B) {
    
    int m=B.length(), n=A.length();
    vector<vector<bool> > dp(n+1, vector<bool> (m+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=m; i++){
        if(B[i-1]=='*') dp[0][i] = dp[0][i-1];
    }
    
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=m; j++){
            
            if(B[j-1]=='*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else if(B[j-1]=='?' || B[j-1]==A[i-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

/*

    // string A1 = A.substr(0, A.length()-1);
    int i = 0, j = 0, lena = A1.length(), lenb = B.length();
    while( i < lena && j < lenb ){
        
        if(A1[i] == B[j]){
            i++;
            j++;
        }
        else if( B[j] == '*'){
            if( j == lenb-1) return 1;
            int k = j;
            while( k<lenb && (B[k]!='*' && B[k]!='?') ) k++;
            string strb = B.substr(j+1, k-j);
            string stra = A1.substr(i, lena-i);
            // cout << strb.length() << " some " << stra << " -str" << endl;
            // if(strb == 0)
            
            int ret = kmpSearch(stra, strb);
            // cout << ret << " ret \n";
            if( ret == -1 ) return 0;
            else{
                i = ret + strb.length();
                j += strb.length() + 1;
            }
        }
        else if( B[j] == '?'){
            i++;
            j++;
        }
        else return 0;
        
    }
    while(j < lenb){
        if(B[j]!='*') return 0;
    }
    while(i < lenb){
        if(B[j-1]!='*') return 0;
    }
    
    return 1;
*/

