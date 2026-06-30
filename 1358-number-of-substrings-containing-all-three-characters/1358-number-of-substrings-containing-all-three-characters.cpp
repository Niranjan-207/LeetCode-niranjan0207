class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,n=s.length();
        int a=0,b=0,c=0;
        int cnt=0;

        for(int r=0;r<n;r++){
            if(s[r]=='a')   a++;
            else if(s[r]=='b')   b++;
            else c++;
            while(a>=1 && b>=1 && c>=1){
                //cnt++;
                cnt+=(n-r);

                if(s[l]=='a')   a--;
                else if(s[l]=='b')   b--;
                else c--;
                l++;
            }
        }
        return cnt;
    }
};