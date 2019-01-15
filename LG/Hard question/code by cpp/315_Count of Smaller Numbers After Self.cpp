#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
315. 计算右侧小于当前元素的个数

给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:
输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
 */

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> arr;
        if(!nums.size()) return arr;
        // 通过在排序好的数组进行查找，降低运算复杂度
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());

        int left,right;
        for(int i=0;i<nums.size();i++){
            left = 0, right = sorted.size()-1;
            // 2分法，进行查找
            while(left<=right){
                int mid = left + (right-left)/2;
                if(nums[i] > sorted[mid])left = mid+1;
                else right = mid-1;
            }
            arr.push_back(left);
            sorted.erase(sorted.begin()+left);
        }
        return arr;
    }
};

int main(){
    vector<int> a({5,2,6,1,42,543,5,3425,324,5,234,5,3425,342,1235,26,3,5,1,5});
    Solution* so = new Solution();
    vector<int> arr = so->countSmaller(a);
    for(auto n:arr)    
        cout<<n<<' ';
    return 0;
}
