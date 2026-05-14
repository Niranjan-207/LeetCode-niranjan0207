class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> fre(n+1,0);
        for(vector<int>& booking:bookings){
            fre[booking[0]-1]+=booking[2];
                fre[booking[1]]-=booking[2];
        }
        for(int i=1;i<=n;i++){
            fre[i]+=fre[i-1];
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=fre[i];
        }
        
        return ans;
    }
};