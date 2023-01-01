
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int n=tokens.size();
        
        for (int i=0;i<n;i++){
            if (!(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" ||tokens[i]=="/")){
                st.push(stoi(tokens[i]));
            }
            else{
                if (tokens[i]=="+"){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    
                    st.push(op2+op1);
                    
                }
                else if (tokens[i]=="-"){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2-op1);
                }
                else if (tokens[i]=="*"){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2*op1);
                }
                else if (tokens[i]=="/"){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2/op1);
                    
                }
               
            }
            
        }
     
        
        return st.top();
    }
};
