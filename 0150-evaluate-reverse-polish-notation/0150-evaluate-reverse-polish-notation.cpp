class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c:tokens){
            if(c=="+"){
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num1+num2);
            }else if(c=="-"){
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num2-num1);
            }else if(c=="*"){
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num1*num2);
            }else if(c=="/"){
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num2/num1);
            }else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};