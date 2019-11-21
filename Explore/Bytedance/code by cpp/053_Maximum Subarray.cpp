#include<iostream>
#include<vector>
using namespace std;
/*
53. 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
int maxSubArray(vector<int>& nums) {
    if(!nums.size()) return 0;
    int maxValue = nums[0],temp = 0;
    for(int i = 0; i<nums.size(); i++){
        // 当前temp若小于0，重新相加
        if(temp>0)
            temp+=nums[i];
        else temp = nums[i];
        maxValue = max(maxValue,temp);
    }
    return maxValue;
}

int main(){
    int x[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int>nums(x,x+9);
    int n = maxSubArray(nums);
    cout<<n<<endl;
	return 0;
}
