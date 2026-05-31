class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids),end(asteroids));

        long long cmass=mass;
        int n=asteroids.size(),i;
        for(i=0;i<n;i++){
            if(asteroids[i]<=cmass){
                cmass+=asteroids[i];
            }else{
                break;
            }
        }
        return (i==n);
    }
};