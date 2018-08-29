// int editDist(string &A, int ind1, string &B, int ind2){
//     if(ind1>=A.length() && ind2<B.length()) return (B.length()-ind2);
//     else if(ind1<A.length() && ind2>=B.length()) return (A.length()-ind1);
//     else if(ind1>=A.length() && ind2>=B.length()) return 0;
    
//     if( A[ind1]==B[ind2] ) return 1+editDist(A, ind1+1, B, ind2+1);
//     else return min( min( 1+editDist(A, ind1+1, B, ind2), 1+editDist(A, ind1, B, ind2+1) ), 1+editDist(A, ind1+1, B, ind2+1) );
// }

int Solution::minDistance(string A, string B) {
    
    vector<vector<int>> dist(A.length()+1, vector<int>(B.length()+1, 0));
    for(int i=0; i<dist.size(); i++){
        for(int j=0; j<dist[0].size(); j++){
            if(i==0) dist[i][j] = j;
            if(j==0) dist[i][j] = i;
        }
    }
    
    for(int i=1; i<dist.size(); i++){
        for(int j=1; j<dist[0].size(); j++){
            
            if(A[i-1]==B[j-1]){
                dist[i][j] = dist[i-1][j-1];
            }
            else{
                dist[i][j] = 1 + min( dist[i-1][j], min( dist[i][j-1], dist[i-1][j-1] ) ); 
            }
            
        }
    }
    return dist[A.length()][B.length()];
}

