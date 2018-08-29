/*
int myXOR(int x, int y)
{
    int res = 0; // Initialize result
     
    // Assuming 32-bit Integer 
    for (int i = 31; i >= 0; i--)                     
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
        
        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);          
 
        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
*/

int myXOR(int x, int y)
{
   return (x | y) & (~x | ~y);
}

int Solution::findMinXor(vector<int> &A) {
    
    if(A.size()==0) return -1;
    if(A.size()==1) return A[0];
    sort( A.begin(), A.end() );
    
    int ret = INT_MAX;
    for(int i=0; i<A.size()-1; i++){
    
        if( myXOR(A[i], A[i+1]) < ret ) ret = myXOR(A[i], A[i+1]);

    }
    return ret;
}

