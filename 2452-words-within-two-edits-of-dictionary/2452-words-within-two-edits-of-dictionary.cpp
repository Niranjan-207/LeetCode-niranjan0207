class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int len=queries[0].length();
        for(int i=0;i<queries.size();i++){
            bool found=false;
            for(int j=0;j<dictionary.size();j++){
                int cnt=0;
                
                for(int k=0;k<len;k++){
                    if(queries[i][k]!=dictionary[j][k]) cnt++;
                    if(cnt>3)   break;
                }
                if(cnt<3){
                    found=true;
                    break;
                }   
            }
            if(found)   ans.push_back(queries[i]);
        }
        return ans;
    }
};