#include<iostream>
#include<limits.h>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<random>
#include<ctime>
using namespace std;
/*
1060. 有序数组中的缺失元素

给出一个有序数组 A，数组中的每个数字都是 独一无二的，找出从数组最左边开始的第 K 个缺失数字。

示例 1：   输入：A = [4,7,9,10], K = 1    输出：5
解释： 第一个缺失数字为 5 。
示例 2：   输入：A = [4,7,9,10], K = 3    输出：8
解释： 缺失数字有 [5,6,8,...]，因此第三个缺失数字为 8 。
示例 3：   输入：A = [1,2,4], K = 3       输出：6
解释： 缺失数字有 [3,5,6,7,...]，因此第三个缺失数字为 6 。

提示：
1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8
*/

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // 应该是好用的，没有办法检测
        // 二分法  边界为 [left, right)  左闭右开
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + ((right-left) >> 1);
            // 从左端到中间缺失的数字个数
            int miss = nums[mid] - nums[left] + left - mid;
            if(miss > k)
                right = mid;
            else if(miss < k)
                // 正常的二分法应该为 mid + 1  所以会陷入死循环
                left = mid, k -= miss;
            else {
                // k == miss   中间到左端最后一个缺失的数字
                while(mid-1 >= left && nums[mid-1] + 1 == nums[mid]) mid--;
                return nums[mid] - 1;
            }
            // 防止死循环
            if(left + 1 == right) break;
        }
        // 左右下标相差为 1
        int miss = nums[right] - nums[left] - 1;
        return miss > k ? nums[left] + k : nums[right] + k - miss;

        // 可能的结果
        int res = nums[0] + k;
        for(int i=1; i<nums.size(); ++i){
            if(res < nums[i]) return res;
            else res++;
        }
        return res;
    }
};

int main(){
    vector<int> arr({4,8,9,10});
    Solution* so = new Solution();
    int num = so->missingElement(arr, 3);
    cout<<num<<endl;

    return 0;
}