class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            char& c=s[i];
            if(c=='(')  st.push(i);
            else if(c==')'){
                if(st.empty())  st.push(i);
                else{
                    char& to=s[st.top()];
                    if(c==')' && to=='(')   st.pop();
                    else    st.push(i);
                }
            }
        }
        if(st.empty())  return s;
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(!st.empty() && i==st.top()){
                st.pop();
            }else{
                ans+=s[i];
            }
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};