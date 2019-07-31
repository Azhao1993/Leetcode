#include <bits\stdc++.h>
using namespace std;
/*
581. 最短无序连续子数组

给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
你找到的子数组应是最短的，请输出它的长度。

示例 1:   输入: [2, 6, 4, 8, 10, 9, 15]         输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

说明 :  输入的数组长度范围在 [1, 10,000]。   输入的数组可能包含重复元素 ，所以升序的意思是<=。
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) { 
        // iMax 为当前遍历结果中的最大值， iMin 为当前遍历结果中的最小值， end = -1 初始有序时仍能返回正解
        int len = nums.size(), iMax = nums[0], iMin = nums[len-1], st = 0, end = -1;
        for(int i=1; i<len; i++){
            // 当前结果最大值大于当前值，说明当前元素应该在前面
            if(iMax > nums[i]) end = i;
            else iMax = nums[i];
            if(iMin < nums[len-i-1]) st = len-i-1;
            else iMin = nums[len-i-1];
        }
        return end-st+1;
        /*
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int left = 0, right = nums.size()-1;
        while(left < right && nums[left] == sorted[left]) left++;
        if(left == right) return 0;
        while(right > left && nums[right] == sorted[right]) right--;
        return right-left+1;
        */
    }
};

int main(){
    vector<int> arr{2, 6, 4, 8, 10, 9, 15};
    int res = Solution().findUnsortedSubarray(arr);
    cout<<res<<endl;
    return 0;
}
