class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time=0;
        for(int i=0; i<timeSeries.size(); i++){
            if(i<timeSeries.size()-1&&timeSeries[i]+duration>timeSeries[i+1]) time += timeSeries[i+1] - timeSeries[i];
            else time += duration;
        }
        return time;
    }
};