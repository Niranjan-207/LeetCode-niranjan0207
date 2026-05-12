class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        while(num>0){
            int dig=num%10;
            arr.push_back(dig);
            num/=10;
        }
        sort(begin(arr),end(arr));
        int num1=arr[0]*10 + arr[3];
        int num2=arr[1]*10 +arr[2];
        return num1+num2;
    }
};