string Solution::fractionToDecimal(int numerator, int denominator) {
    
    long long int A = numerator, B = denominator;
    
    if(A==0) return "0";
    int sign = (A<0 && B<0)||(A>0 && B>0) ? 1 :-1;
    if( abs(B)==1 ){
        string ret = to_string(A);
        if(ret[0]=='-') ret = ret.substr(1, ret.length()-1);
        if(sign==-1) return "-" + ret;  
        else return ret;
    }
    A = abs(A);
    B = abs(B);
    int floor_val = floor(A/B);
    string ret="";
    
    long long int remain = A % B;
    unordered_map<int, int> hash;
    int check = false;
    int i = 0;
    while( remain != 0){
        if(hash.find(remain)==hash.end()){
            hash.insert( make_pair(remain, i) ); 
        }
        else{
            check = true;
            ret = ret.substr(0, hash[remain]) + "(" + ret.substr(hash[remain], ret.length()-hash[remain]) + ")"; 
            // ret = "(" + ret + ")";
            break;
        }
        remain *= 10;
        ret+= to_string( remain/B );
        remain = remain % B;
        i++;
    }
    
    if(ret.length()!=0) ret = to_string(floor_val) + "." + ret;
    else ret = to_string(floor_val);
    
    if(ret[0]=='-') ret = ret.substr(1, ret.length()-1);
    if(sign == -1) return "-" + ret;
    return ret;
}

