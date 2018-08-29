string new_func(int num, int num_zero, string D){
    
    string temp="";
    int count = 0;
    int n = D.length();
    for(int i=n-1; i>=0; i--){
        
        int var = D[i] - '0';
        int mul = num * var;
        temp = to_string( (mul+count) % 10) + temp;
        count = (mul+count)/10;
    }
    if(count != 0) {
        temp = to_string( count ) + temp;
    }
    for(int i=0; i<num_zero; i++){
        temp+= "0";
    }
    return temp;
}

string merge_str(string A, string B){
    
    string ret="";
    int count = 0;
    int len_a = A.length()-1;
    int len_b = B.length()-1;
    while( len_a >= 0 and len_b >= 0 ){
        
        int val1 = (int)(A[len_a] - '0');
        int val2 = (int)(B[len_b] - '0');
        ret =  to_string( (val1 + val2 + count)%10 )  + ret ;
        count = (val1 + val2 + count)/10;
        len_a--;
        len_b--;
    }
    if( len_a==-1 && len_b==-1 ) {
        if( count != 0) {
            ret = to_string( count ) + ret;
            return ret;
        }
        return ret;
    }
    // while( len_a >= 0){
    //     int val = (int) (A[len_a] - '0');  
    //     ret = to_string( (val+count)%10 ) + ret;
    //     count = (val+count) / 10;
        
    //     len_a--;
    // }
    while( len_b >= 0){
        int val = (int) (B[len_b] - '0');
        ret = to_string( (val+count)%10 ) + ret;
        count = (val+count) / 10;
        
        len_b--;
    }
    if(count != 0) ret = to_string( count ) + ret;
    
    return ret;
}

// string Solution::multiply(string A, string B) {
    
//     int len_a = A.length();
//     int len_b = B.length();
//     string ret="";
    
//     for(int i=len_a-1; i>=0; i--){
        
//         int var1 = (int)(A[i]-'0');
//         int num = var1;
//         int num_zero = len_a-1-i;
//         string new_temp = new_func(num, num_zero, B);
//         ret = merge_str(ret, new_temp);
//     }
//     int itr = ret.length()-1;
//     for(int i=0; i<ret.length(); i++){
//         if(ret[i] != '0'){
//             itr = i;
//             break;
//         } 
//     }
//     string ret_new = ret.substr(itr, ret.length()-itr);
//     return ret_new;
// }




string Solution::multiply(string num1, string num2){
    int n1 = num1.size();
            int n2 = num2.size();
            if (n1 == 0 || n2 == 0)     return "0";

            // will keep the result number in vector in reverse order
            std::vector<int> result(n1 + n2, 0);

            int i_n1 = 0; // index by num1
            int i_n2 = 0; // index by num2

            // go from right to left by num1
            for (int i = n1 - 1; i >= 0; i--){
                int carrier = 0;
                int n1 = num1[i] - '0';
                i_n2 = 0;

                // go from right to left by num2
                for (int j = n2 - 1; j >= 0; j--){
                    int n2 = num2[j] - '0';     

                    int sum = n1 * n2 + result[i_n1 + i_n2] + carrier;
                    carrier = sum / 10;
                    result[i_n1 + i_n2] = sum % 10;

                    i_n2++;
                }

                // store carrier in next cell
                if (carrier > 0)
                    result[i_n1 + i_n2] += carrier;

                i_n1++;
            }

            // ignore '0's from the right
            int i = result.size() - 1;
            while (i>=0 && result[i] == 0) i--;

            // if all were '0's - means either both or one of num1 or num2 were '0'
            if(i == -1) return "0";

            // generate the result string
            std::string s = "";
            while (i >= 0) s += std::to_string(result[i--]);

            return s;
}
