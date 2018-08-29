int isValid(string &A) {
    
    stack<int> B;
    for(int i=0; i<A.length(); i++){
        
        if( A[i]=='('){
            B.push(A[i]);
        }
        else if( A[i]==')'){
            if( !B.empty() and ( B.top()=='(' ) ){
                B.pop();
            }
            else return 0;
        }
    }
    if( !B.empty() ) return 0;
    return 1;
}


bool shouldSwap(string &str, int start, int curr)
{
    for (int i = start; i < curr; i++) 
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void gen_permu(vector<string>&ret, int index, string &A){
    
    if(index == A.size()){
        string temp="(" + A + ")";
        if( isValid(temp) ) ret.push_back(temp);
        return;
    }
    
    for(int i=index; i<A.size(); i++){
        bool check = shouldSwap(A, index, i);
        if(check){
            swap(A[i], A[index]);
            gen_permu(ret, index+1, A);
            swap(A[i], A[index]);
        }
    }
}

vector<string> Solution::generateParenthesis(int A) {
    
    vector<string> ret;
    string arr="";
    for(int i=0; i<2*A; i++){
        if(i<A) arr+= "(";
        else arr+= ")";
    }
    string temp = arr.substr(1, arr.length()-2);
    gen_permu(ret, 0, temp);
    return ret;
}

