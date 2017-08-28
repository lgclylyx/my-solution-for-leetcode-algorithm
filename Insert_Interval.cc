/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
*/

/*
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int fpos = intervals.size(), epos = fpos-1;
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval.start <= intervals[i].end){
                fpos = i;
                break;
            }
        }
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval.end < intervals[i].start){
                epos = i-1;
                break;
            }
            if(newInterval.end <= intervals[i].end){
                epos = i;
                break;
            }
        }
        if(fpos == epos){
            for(int i = 0; i < intervals.size(); i++){
                if(fpos == i){
                    Interval temp;
                    temp.start = min(intervals[i].start,newInterval.start);
                    temp.end =  max(intervals[i].end,newInterval.end);
                    result.push_back(temp);
                    continue;
                }
                result.push_back(intervals[i]);
            }
        }else if(epos < fpos){ 
            for(int i = 0; i < intervals.size(); i++){
                if(fpos == i){
                    result.push_back(newInterval);
                }
                result.push_back(intervals[i]);
            }
            if(fpos == intervals.size())
                result.push_back(newInterval);
        }else{
            Interval temp;
            for(int i = 0; i < intervals.size();i++){
                if(i < fpos || i > epos){
                    result.push_back(intervals[i]);
                } 
                if( i == fpos){
                    temp.start = min(intervals[i].start,newInterval.start);
                }
                if(i == epos){
                    temp.end =  max(intervals[i].end,newInterval.end);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
*/