class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n),suf(n);

        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1]+arr[i],arr[i]);
        }

        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1]+arr[i],arr[i]);
        }

        int res=*max_element(begin(pre),end(pre));
        for(int i=1;i<n-1;i++){
            res=max(res,pre[i-1]+suf[i+1]);
        }
        return res;
    }
};