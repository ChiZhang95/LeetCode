class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int h=0;
        sort(citations.begin(),citations.end());
        for(int i=0; i<citations.size(); i++){
            if(i == 0 && citations[i] >= citations.size()-i){ h = citations.size()-i;}
            if(citations.size()-i-1 >= citations[i] && citations.size()-i-1 <= citations[i+1]){
                h = citations.size()-i-1;
            }
        }
        return h;
    }
};