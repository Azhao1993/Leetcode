#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
42. 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
 */

class Solution {
public:
    int trap(vector<int>& height) {
        // 空间复杂度为O(n),时间复杂度为O(n),代码清晰明确
        int n = height.size();
        if(n<3)return 0;
        // left为当前节点左边最长的柱高
        // right为当前节点右边最长的柱高
        vector<int> left(n,0), right(n,0);
        for(int i=1;i<n-1;i++)
            left[i] = max(left[i-1],height[i-1]);
        for(int i=n-2;i>0;i--)
            right[i] = max(right[i+1],height[i+1]);
        int res = 0;
        for(int i=1;i<n-1;i++)
            res += max(0, min(left[i],right[i]) - height[i]);
        return res;
        // 两端进行搜索，只查找一遍，更快,空间复杂度为O(1),时间复杂度为O(1)
        int n = height.size();
        if(n<3)return 0;
        int left = 0, right = n-1;
        int leftmax = height[0],rightmax = height[n-1];
        int res = 0;
        while(left<right){
            if(leftmax<rightmax){
                left++;
                res += max(0, min(leftmax,rightmax)-height[left]);
                leftmax = max(leftmax,height[left]);
            }else{
                right--;
                res += max(0, min(leftmax,rightmax)-height[right]);
                rightmax = max(rightmax,height[right]);
            }
        }
        return res;
    }
};

int main(){
    int cha[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> a(cha,cha+12);

    Solution* so = new Solution();
    int n = so->trap(a);
    cout<<n<<endl;
    return 0;
}
