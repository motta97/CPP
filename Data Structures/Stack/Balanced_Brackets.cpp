string isBalanced(string s) {
stack<char> stck;
    stack<char> helper_stack;
    char x;
    char y;
    for(int i =0;i<s.length();i++){
        stck.push(s[i]);
    }
    while(!stck.empty()){
        x=stck.top();
        stck.pop();
        if(x=='}'||x==')'||x==']'){
            helper_stack.push(x);
        }
        else if(x=='{'||x=='('||x=='['){
            if(!helper_stack.empty()){
                y = helper_stack.top();
                helper_stack.pop();
                if(x=='('){
                    if(y!=')')return "NO";
                }
                else if(x=='{'){
                    if(y!='}')return "NO";
                }
                else{
                    if(y!=']')return "NO";
                }
            }
            else return "NO";
        }
          
        
        
        
    }
    
    if(helper_stack.empty()) return "YES";
    return "NO";

}