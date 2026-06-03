class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landCompletion=INT_MAX,waterCompletion=INT_MAX;
        int n=landDuration.size();
        int m=waterDuration.size();
        
        for(int i=0;i<n;i++){
            landCompletion=min(landCompletion,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            waterCompletion=min(waterCompletion,max(landCompletion,waterStartTime[i])+waterDuration[i]);
        }
        int lfws=waterCompletion;


        landCompletion=INT_MAX;waterCompletion=INT_MAX;
        for(int i=0;i<m;i++){
            waterCompletion=min(waterCompletion,waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0;i<n;i++){
            landCompletion=min(landCompletion,max(waterCompletion,landStartTime[i])+landDuration[i]);
        }
        return min(lfws,landCompletion);
    }
};