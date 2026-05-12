class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> fre(10,0);
        for(char c:num){
            fre[c-'0']++;
        }

        string left="";
        for(int dig=9;dig>=0;dig--){
            int cnt=fre[dig]/2;
            if(dig==0 && left=="") continue;
            while(cnt--){
                left+=(dig+'0');
            }
        }

        string right=left;
        reverse(begin(right),end(right));

        string mid="";
        
        for(int dig=9;dig>=0;dig--){
            if(fre[dig]&1){  mid+=(dig+'0');break;}
        }
        
        string ans=left+mid+right;
        if(ans=="")  return "0";
        return ans;
    }
};