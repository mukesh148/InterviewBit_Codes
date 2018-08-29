void space( string &D, int F){
    for(int i=0; i<F; i++){
        D = "\t" + D;
    }
}

vector<string> Solution::prettyJSON(string A) {
    
    vector<string> ret;
    string temp= "";
    int count = 0;
    for(int i=0; i<A.length(); i++){
    
        if(A[i] == ' ') continue;
        
        if(A[i] == '{' or A[i] == '['){
            if(temp.length() != 0) {
                space( temp, count);    
                ret.push_back(temp);
            }
            temp = A[i];
            space( temp, count);
            ret.push_back(temp);
            count++;
            temp = "";
        }
        else if( (A[i] == '}' or A[i] == ']') and ( (i+1)<A.length() and A[i+1] == ',') ){
            if(temp.length() != 0) {
                space( temp, count);    
                ret.push_back(temp);
            }
            temp = A[i];
        }
        else if( (A[i] == '}' or A[i] == ']') ){
            if(temp.length() != 0) {
                space( temp, count);    
                ret.push_back(temp);
            }
            count--;
            temp = A[i];
            space( temp, count);
            ret.push_back(temp);
            
            temp = "";
        }
        else if( (i+1)<A.length() and (A[i] == ':') and (A[i+1] == '{' or A[i+1] == '[') ){
            temp+= A[i];
            space( temp, count);
            ret.push_back(temp);
            temp = "";
        }
        else if(A[i] == ','){
            temp+= A[i];
            if( A[i-1]=='}' or A[i-1]==']') count--;
            space( temp, count);
            ret.push_back(temp);
            temp = "";
        }
        else{
            temp+= A[i];
        }
        
    }
    
    return ret;
}

