int stoi_mul(string &str){
    
    if(str.length()==1){
        return stoi(str);
    }
    int ret = 1;
    for(int i=0; i<str.length(); i++){
        ret*= (int)( str[i] - '0');
    }
    return ret;
}

int Solution::colorful(int num) {
    
    unordered_map<int, string> A;
    string num_str = to_string(num);
    
    for(int i=0; i<num_str.length(); i++){
        for(int j=i; j<num_str.length(); j++){
            
            string str = num_str.substr( i, j-i+1 );
            int val = stoi_mul(str);
            // cout << val << " " <<  str << " val \n";
            if ( A.find(val) == A.end() ) A.insert( make_pair(val, str) );
            else return 0;
        }
    }
    return 1;
}

