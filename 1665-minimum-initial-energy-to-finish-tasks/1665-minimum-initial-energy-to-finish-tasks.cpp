class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return (b[1]-b[0])<(a[1]-a[0]);
    }

    bool pos(int energy,vector<vector<int>>& tasks){
        for(vector<int>& task:tasks){
            if(energy<task[1])  return false;
            energy-=task[0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks),end(tasks),cmp);
        int lo=0;
        int hi=0;
        for(vector<int> task:tasks){
            lo=min(lo,task[1]);
            hi+=task[1];
        }
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(pos(mid,tasks)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};