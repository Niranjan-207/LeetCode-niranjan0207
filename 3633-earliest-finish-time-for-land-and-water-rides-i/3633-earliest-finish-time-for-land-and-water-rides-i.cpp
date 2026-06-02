class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        int n=landStartTime.size();
        int m=waterDuration.size();

        for(int i=0;i<n;i++){
           int landFin=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                int waterFin=max(landFin,waterStartTime[j])+waterDuration[j];
                ans=min(ans,waterFin);
            }
        }

         for(int i=0;i<m;i++){
            int waterFin=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                int landFin=max(waterFin,landStartTime[j])+landDuration[j];
               ans=min(ans,landFin);
            }
        }
        return ans;

    }
};