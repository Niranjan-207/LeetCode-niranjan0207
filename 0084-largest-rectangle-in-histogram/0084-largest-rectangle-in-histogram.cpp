class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> ns(n),ps(n);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty())  ns[i]=n;
            else    ns[i]=st.top();
            st.push(i);
        }

        st = stack<int>();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty())  ps[i]=-1;
            else    ps[i]=st.top();
            st.push(i);
        }

        int maans=INT_MIN;
        for(int i=0;i<n;i++){
            maans=max(maans,(ns[i]-ps[i]-1)*heights[i]);
        }
        return maans;
    }
};