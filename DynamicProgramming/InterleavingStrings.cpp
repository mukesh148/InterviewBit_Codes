int Solution::isInterleave(string A, string B, string C) {
    
    int lena = A.length(), lenb = B.length(), lenc = C.length();
    if(lena + lenb != lenc ) return 0;
    
    int i=0, j=0, k=0;
    while( i<lena && j<lenb ){
        
        if( A[i]==C[k] && B[j]==C[k]){
            if(A[i+1] == C[k+1]) i++;
            else if(B[j+1] == C[k+1]) j++;
            else i++;
        }
        else if(A[i]==C[k]) i++;
        else if(B[j]==C[k]) j++;
        else return 0;
        k++;
    }
    
    while(i < lena ){
        if(A[i++]!=C[k++]) return 0;
    }
    while(j < lenb ){
        if(B[j++]!=C[k++]) return 0;
    }
    return 1;
}

