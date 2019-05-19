#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
137. 只出现一次的数字 II

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
说明： 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:   输入: [2,2,3,2]   输出: 3
示例 2:   输入: [0,1,0,1,0,1,99]    输出: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three;
        for(int it : nums){
            // two 的相应的位等于 1 时，代表出现 2 次
            two |= (one & it);
            // one 相应的位等于 1 时，代表出现 1 次
            one ^= it;
            // three 相应的位等于 1 时，表示出现 3 次
            three = (one & two);
            // 清除出现 3 次的数
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

int main(){
    vector<int> arr({2,2,3,2});
    Solution* so = new Solution();
    int n = so->singleNumber(arr);
    cout<<n<<endl;
    return 0;
}