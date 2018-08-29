void space( string &D, int F){
    for(int i=0; i<F; i++){
        D+= " ";
    }
}

string add_spaces(vector<string> &A, int B, int ind1, int ind2, vector<int> temp){
    
    string ret="";
    ret+= A[ind1];
    int count = B;
    
    if(ind2 == A.size()-1){
        for(int i=ind1+1; i<ind2+1; i++){
            ret+= " ";
            ret+= A[i];
        }
        if(ret.length() < B) space(ret, B-ret.length());
    }
    else{
        for(int i=ind1; i<ind2+1; i++){
            count-= temp[i];
        }
        int c1 = 0, c2 = 0;
        if( (ind2-ind1) == 1 or (ind2-ind1) == 0 ) {
            c1 = count;
        }
        else if(count%(ind2-ind1)==0){
            c1 = count / (ind2-ind1);
            c2 = count / (ind2-ind1);
        }
        else{
            c1 = count / (ind2-ind1) + 1;
            c2 = count / (ind2-ind1);
        }
        int mod_cal = 0;
        if((ind2-ind1) != 0){
            mod_cal = count % (ind2-ind1);    
        }
        
        space(ret, c1);
        mod_cal--;
        for(int i=ind1+1; i<ind2+1; i++){
            ret+= A[i];
            if( i < ind2 ){ 
                if(mod_cal>0) space(ret, c1), mod_cal--;
                else space(ret, c2);
            }
        }
    }
    return ret;
}


vector<string> Solution::fullJustify(vector<string> &A, int B) {
    
    vector<string> ret;
    vector<int> temp(A.size());
    for(int i=0; i<A.size(); i++){
        temp[i] = A[i].length();
    }
    for(int i=0; i<A.size(); i++){
        int var1 = 0;
        int count = 0;        
        var1+= temp[i];
        int j = i;
        count++;
        if(var1 > B) {
            vector<string> ret;
            return ret;
        }
        while( (j+1)<A.size() and (var1+temp[j+1]+count) <= B ){
            
            var1+= temp[j+1];
            j++;
            count++;
            
        }ret.push_back( add_spaces(A, B, i, j, temp) );
        i = j;
        
    }
    return ret;
}

