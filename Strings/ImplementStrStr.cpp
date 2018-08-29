void computeLPSArray(const string pat, vector<int> &lps)
{
    int len = 0;
 
    lps[0] = 0;
    int M = pat.length();
    int i = 1;
    
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) len = lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const string pat, const string txt)
{
    int N = txt.length();
    int M = pat.length();
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    
    vector<int> lps(pat.length());
    computeLPSArray( pat, lps );
    
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {   
            return i-j;
            j = lps[j-1];
        }
 
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0) j = lps[j-1];
            else i = i+1;
        }
    }
    return -1;
}
 



int Solution::strStr(const string A, const string B) {
    
    if(A.length() == 0 or B.length() == 0 or A.length()<B.length()) return -1;
    
    int ret = 0;
    ret = KMPSearch(B, A);
    return ret;
}

/*
int Solution::strStr(const string A, const string B) {
    
    if(A.length() == 0 or B.length() == 0 or A.length()<B.length()) return -1;
    for(int i=0; i<A.length(); i++){
        int count = 0;
        int k = i;
        for(int j=0; j<B.length(); j++){
            
            if(A[k+j] == B[j]) {
                count++;
                // k++;
            }
            
        }
        if(count== B.length()) return i;
    }
    return -1;
}
*/

