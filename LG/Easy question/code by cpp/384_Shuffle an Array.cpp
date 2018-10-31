#include<iostream>
#include<vector>
using namespace std;
/*
384. 打乱数组

打乱一个没有重复元素的数组。

示例:

// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();

 */

class Solution {
public:
    Solution(vector<int> nums):arr(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(arr.size()==0)return arr;
        vector<int> tem(arr);
        for(int i=arr.size()-1;i>0;i--)
            swap(tem[i],tem[rand()%(i+1)]);
        return tem;
    }
private:
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */