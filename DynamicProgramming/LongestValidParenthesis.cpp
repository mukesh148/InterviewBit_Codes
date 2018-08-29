int Solution::longestValidParentheses(string A) {
    
    int ret = 0;
    stack<int> stack;
    stack.push(-1);
    
    for(int i=0; i<A.size(); i++){
        
        if(A[i]=='('){
            stack.push(i);
        }
        else{
            stack.pop();
            if(!stack.empty()){
                ret = max(ret, i - stack.top());
            }
            else stack.push(i);
        }
        
    }
    return ret;
}

