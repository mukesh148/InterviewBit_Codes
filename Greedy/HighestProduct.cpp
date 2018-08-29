int Solution::maxp3(vector<int> &A) {
    
    if( A.size() < 3 ) return -1;
    
    int a=INT_MIN, b=INT_MIN, c=INT_MIN, d=INT_MIN, e=INT_MIN;    
    
    for(int i=0; i<A.size(); i++){
        
        bool check = (A[i]<0) ? false : true;
        if( check ){
            
            int min_ = min( a, min( b,c ) );
            if( min_ == a && A[i] > a ) a = A[i];
            else if( min_ == b && A[i] > b ) b = A[i];
            else if( min_ == c && A[i] > c ) c = A[i];
            
        }
        else{
            
            int min_ = min( d,e );
            if( min_ == d && abs(A[i]) > d ) d = abs(A[i]);
            else if( min_ == e && abs(A[i]) > e ) e = abs(A[i]);
            
        }
        
    }
    if( a==INT_MIN && b==INT_MIN && c==INT_MIN ){
        sort(A.begin(), A.end());
        return A[A.size()-1]*A[A.size()-2]*A[A.size()-3];
    }
    
    if( d!=INT_MIN && e!=INT_MIN ){
        return max( max( a, max( b, c) )*d*e, a*b*c)  ;
    }
    else{
        if( a==INT_MIN || b==INT_MIN || c==INT_MIN ) return a * b * max(d, e) * (-1);
        return a * b * c;
    }
}

