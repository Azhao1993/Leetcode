#include<iostream>
#include<vector>
using namespace std;
/*
189. 旋转阵列

给定一个数组，将数组中的元素向右移动  ķ 个位置，其中  ķ 是非负数。

示例1：

输入： [1,2,3,4,5,6,7]和k = 3
 输出： [5,6,7,1,2,3,4]
解释：
向右旋转1步：[7,1,2,3,4,5,6]
向右旋转2步：[6,7,1,2,3,4,5]
向右旋转3步：[5,6,7,1,2,3,4]
示例2：

输入： [-1,-100,3,99]和k = 2
 输出： [3,99，-1，-100]
 解释：
向右旋转1步：[99，-1，-100,3]
向右旋转2步：[3,99，-1，-100]
*/
void reverse(vector<int>& nums, int left, int right)
{
    while(left < right)swap(nums[left++],nums[right--]);
}

void rotate(vector<int>& nums, int k)
{
    if(nums.size() <= 0 ||  k < 0 )return;
    k = k%nums.size();  //防止溢出  [1,2] 3
    int left = 0;
    int right = nums.size()-1;
    int mid = right-k;
    reverse(nums, left, mid);
    reverse(nums, mid+1, right);
    reverse(nums, left, right);
}

int main(){
    int x[7] = {1,2,3,4,5,6,7};
    vector<int>nums(x,x+7);
    rotate(nums,3);
    for(int i = 0;i<nums.size();i++)
        cout<<nums[i]<<endl;
	return 0;
}
