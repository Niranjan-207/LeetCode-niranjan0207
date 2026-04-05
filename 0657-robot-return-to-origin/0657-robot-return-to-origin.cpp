class Solution {
public:
    bool judgeCircle(string moves) {
        int u=0,l=0;
        for(char c:moves){
            if(c=='U')  u++;
            else if(c=='D') u--;
            else if(c=='L') l++;
            else    l--;
        }
        return (u==0 && l==0);
    }
};