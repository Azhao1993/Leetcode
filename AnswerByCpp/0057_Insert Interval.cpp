 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
57. 插入区间

给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:
输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:
输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(!intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int first = 0, last = 0, left = 0, right = intervals.size();
        // first代表新加入节点start 可能存在的位置，当在区间外时，属于它的下一个区间
        if(intervals[right-1].end < newInterval.start)first = right,right = 0;
        while(left<right){
            first = left + (right-left) / 2;
            if(intervals[first].start <= newInterval.start && intervals[first].end >= newInterval.start){
                break;
            }else if(first > 0 && intervals[first-1].end < newInterval.start && intervals[first].start > newInterval.start){
                break;
            }else if(first+1 < intervals.size()-1 && intervals[first].end < newInterval.start && intervals[first+1].start > newInterval.start){
                first++;
                break;
            }
            if(intervals[first].start > newInterval.start)right = first;
            else left = first+1;
        }
        left = first, right = intervals.size(), last = right-1;
        // last代表新加入节点的end 可能存在的位置，当在区间外时，属于它的上一个区间
        if(intervals[0].start > newInterval.end)last = -1,right = 0;
        while(left<right){
            last = left + (right-left) / 2;
            if(intervals[last].start <= newInterval.end && intervals[last].end >= newInterval.end){
                break;
            }else if(last > 0 && intervals[last-1].end < newInterval.end && intervals[last].start > newInterval.end){
                last--;
                break;
            }else if(last+1 < intervals.size()-1 && intervals[last].end < newInterval.end && intervals[last+1].start > newInterval.end){
                break;
            }
            if(intervals[last].start > newInterval.end)right = last;
            else left = last+1;
        }
        if(first > last){
            intervals.insert(intervals.begin()+first, newInterval);
        }else if(first == last){
            intervals[first].start = min(intervals[first].start, newInterval.start);
            intervals[first].end = max(intervals[first].end, newInterval.end);
        }else {
            left = min(intervals[first].start, newInterval.start);
            right = max(intervals[last].end, newInterval.end);
            intervals.erase(intervals.begin()+first,intervals.begin()+last+1);
            Interval tem(left,right);
            intervals.insert(intervals.begin()+first, tem);
        }
        return intervals;
    }
};

int main(){
    vector<Interval> arr({{1,3},{5,7}});
    Interval tem(3,5);
    
    Solution* so = new Solution();
    vector<Interval> res = so->insert(arr,tem);
    for(auto it:res)
        cout<<it.start<<' '<<it.end<<endl;

    return 0;
}