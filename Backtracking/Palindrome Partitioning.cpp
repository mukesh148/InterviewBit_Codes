bool ispalindrome(string &temp, int low, int high){
    
    if( temp.length()==0) return false;
    // int low = 0;
    // int high = temp.length()-1;
    while( low<high ){
        if(temp[low]==temp[high]){
            low++;
            high--;
        }
        else return false;
    }
    return true;
}

void create_palindrome( vector<vector<string> > &ret, int index, vector<string> &sec , string &A){
    
    // cout << temp << " " << ispalindrome(temp) << " palind \n";
    
    // else if( temp.length()!=0 ) return;
    
    if( index == A.length() ){
        ret.push_back(sec);
        return;
    }
    
    for(int i=index; i<A.length(); i++){
        
        if( ispalindrome(A, index, i) ){
            sec.push_back( A.substr(index, i-index+1) );
            create_palindrome(ret, i+1, sec, A);
            sec.pop_back();
                
        }
        // temp+= A[i];
        
        // if( temp.length()!=0 ) i+=A.length();
        
    }
    
}

vector<vector<string> > Solution::partition(string A) {
    
    vector<vector<string> > ret;
    // string temp = "";
    vector<string> sec;
    create_palindrome(ret, 0, sec, A);
    // cout << ret.size() << " len \n";
    // cout << ispalindrome(A) << " pa \n";
    
    return ret;
}

