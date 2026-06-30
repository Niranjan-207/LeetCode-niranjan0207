class Solution {
public:
    bool can(vector<int>& piles,int h,int mid){
        int k=0;
        for(int num:piles){
            k+=(num/mid);
            if((num%mid)!=0)    k++;
        }
        return k<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,hi=*max_element(begin(piles),end(piles));

        while(l<hi){
            int mid=l+(hi-l)/2;
            if(can(piles,h,mid)){
                hi=mid;
            }else{
                l=mid+1;
            }
        }
        return l;


    }
};