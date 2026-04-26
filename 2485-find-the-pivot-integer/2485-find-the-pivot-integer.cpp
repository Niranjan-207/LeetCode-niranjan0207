class Solution {
public:
    int pivotInteger(int n) {
        int tot=(n*(n+1))/2;
        int cur=0;
        for(int i=1;i<=n;i++){
            cur+=i;
            int ri=tot-cur+i;
            if(cur==ri) return i;
        }
        return -1;
    }
};