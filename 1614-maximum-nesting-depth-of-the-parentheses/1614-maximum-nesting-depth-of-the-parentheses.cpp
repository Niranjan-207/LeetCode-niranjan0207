class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int len=0;
        for(char c:s){
            if(c=='(')  st.push(c);
            else if(c==')'){
                int clen=st.size();
                len=max(len,clen);
                st.pop();
            }
        }
        return len;
    }
};