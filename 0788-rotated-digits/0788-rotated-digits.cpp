class Solution {
public:
// set<char> se={'0','1','8','2','5','6','9'};

    int rotatedDigits(int n) {
        set<char> se={'3','4','7'};
        set<char> sr={'0','1','8'};
        int cnt=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            bool flag=true;
            bool can=false;
            for(char& c:s){
                if(sr.find(c)==sr.end())   can=true;
                if(se.find(c)!=se.end()){
                    flag=false;
                    break;
                }
            }
            
            if(flag && can){    cout<<i<<" ";cnt++;}
        }
        return cnt;
    }

};