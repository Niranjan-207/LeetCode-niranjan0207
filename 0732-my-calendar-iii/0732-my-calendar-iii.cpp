class MyCalendarThree {
public:
map<int,int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;

        int k=0;
        int overLap=0;
        for(auto& [day,delta]:mp){
            overLap+=delta;
            k=max(k,overLap);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */