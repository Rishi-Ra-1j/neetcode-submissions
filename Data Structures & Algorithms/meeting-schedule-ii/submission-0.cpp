/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>diff(1e6+1,0);
        for(auto &interval : intervals){
            diff[interval.start]++;
            diff[interval.end]--;
        }   
        int ans=0;
        for(int i=1;i<=1e6;i++){
            diff[i]+=diff[i-1];
            ans=max(ans,diff[i]);
        }
        return ans;
    }
};
