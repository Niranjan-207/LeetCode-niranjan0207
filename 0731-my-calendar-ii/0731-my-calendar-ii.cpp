class MyCalendarTwo {
public:
    map<int,int> mp;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        int room=0;
        int overLap=0;
        for(auto& [ro,del]:mp){
            overLap+=del;
            room=max(room,overLap);
        }
        if(room>2){
            mp[startTime]-=1;
            mp[endTime]+=1;
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */