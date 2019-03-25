#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
45. 跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明: 假设你总是可以到达数组的最后一个位置。
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return 0;
        // 当前步数能到达的最远距离
        vector<int> steps;
        steps.push_back(nums[0]+1);
        for(int i=1;i<n;++i){
            if(steps.back() >= n)return steps.size();
            // 当前最远的距离
            int tem = nums[i]+i+1;
            if(tem > steps.back()){
                // 更新最远的值，或者多走一步
                if(steps.size()>=2 && i<steps[steps.size()-2])steps.back() = tem;
                else steps.push_back(tem);
            }
        }
        return steps.size();
    }
};

int main(){
    vector<int> a({1,3,3,1,1,3,1});

    Solution* so = new Solution();
    int num = so->jump(a);
    cout<<num<<endl;

    return 0;
}
