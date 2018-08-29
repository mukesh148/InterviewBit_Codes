vector<string> Solution::fizzBuzz(int A) {
    
    vector<string> ret;
    string a = "Fizz";
    string b = "Buzz";
    string ab = "FizzBuzz";
    for(int i=1; i<A+1; i++){
        if( i%3==0 and i%5==0){
            ret.push_back(ab);
        }
        else if( i%3==0 ){
            ret.push_back(a);
        }
        else if( i%5==0 ){
            ret.push_back(b);
        }
        else{
            ret.push_back(to_string(i));
        }
    }
    return ret;
}

