#include<iostream>
#include<vector>
using namespace std;
/*
268. 缺失数字

给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?。
*/
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); ++i)
        result = result ^ nums[i] ^ i;
    return result;

    // unsigned long long sum = (nums.size()+1)*nums.size()/2;
    // for(auto num:nums)sum-=num;
    // return sum;
}

int main(){
    int x[7] = {0,3,6,5,1,4,2};
    vector<int>nums(x,x+7);
    int num = missingNumber(nums);
    cout<<num<<endl;
	return 0;
}
