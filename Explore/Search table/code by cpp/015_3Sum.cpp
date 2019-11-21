#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
15. 三数之和

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

vector<vector<int> > threeSum(vector<int>& nums) {
    // 用map来判断是否存在
    vector<vector<int> > arr;
    if(nums.size()<3)return arr;

    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++){
        if(nums[i]>0)break;
        if(i && nums[i] == nums[i-1])continue;// 去重

        int target = -nums[i];
        int left = i+1,right = nums.size()-1;

        while(left<right){
            if(nums[left]+nums[right] == target){
                arr.push_back({nums[i],nums[left],nums[right]});
                while((left+1)<right && nums[left]==nums[left+1])left++;// 去重
                while((right-1)>left && nums[right]==nums[right-1])right--;// 去重
                left++;
                right--;
            }else if(nums[left]+nums[right] > target)right--;
            else left++;
        }
    }
    return arr;

}


int main(){
    int x[6] = {-1, 0, 1, 2, -1, -4};
    vector<int>nums(x,x+6);
    vector<vector<int> > arr = threeSum(nums);
    for(int i = 0;i<arr.size();i++)
        cout<<arr[i][0]<<' '<<arr[i][1]<<' '<<arr[i][2]<<endl;
	return 0;
}
