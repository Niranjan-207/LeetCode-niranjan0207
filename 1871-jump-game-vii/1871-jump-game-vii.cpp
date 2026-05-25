class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        queue<int> q;
        q.push(0);
        s[0]='1';
        int far=0;
        while(!q.empty()){
            
                int cur=q.front();
                if(cur==n-1)    return true;
                q.pop();

                int l=max(cur+minJump,far+1);
                //int l=cur+minJump;
                int r=min(cur+maxJump,n-1);
                for(int j=l;j<=r;j++){
                    if(s[j]=='1')   continue;
                    q.push(j);
                    s[j]='1';
                }
                far=max(far,r);
            
        }
        return false;
    }
};