#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
18. 四数之和

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
]
*/

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > arr;
    if(nums.size()<4)return arr;

    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-3;i++){
        if(i && nums[i] == nums[i-1])continue;// 去重
        for(int j=i+1;j<nums.size()-2;j++){
            if(j>i+1 && nums[j] == nums[j-1])continue;// 第二个数去重

            int new_target = target-nums[i]-nums[j];
            int left = j+1,right = nums.size()-1;

            while(left<right){
                if(nums[left]+nums[right] == new_target){
                    arr.push_back({nums[i],nums[j],nums[left],nums[right]});
                    while((left+1)<right && nums[left]==nums[left+1])left++;// 去重
                    while((right-1)>left && nums[right]==nums[right-1])right--;// 去重
                    left++;
                    right--;
                }else if(nums[left]+nums[right] > new_target)right--;
                else left++;
            }
        }
    }
    return arr;
}


int main(){
    int x[6] = {1, 0, -1, 0, -2, 2};
    vector<int>nums(x,x+6);
    vector<vector<int> > arr = fourSum(nums,0);
    for(int i = 0;i<arr.size();i++)
        cout<<arr[i][0]<<' '<<arr[i][1]<<' '<<arr[i][2]<<' '<<arr[i][3]<<endl;
	return 0;
}
