#include<iostream>
#include<vector>
using namespace std;
/*
84. 柱状图中最大的矩形

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
示例:
输入: [2,1,5,6,2,3]   输出: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        /*
        int res = 0;
        for(int i=0;i<height.size();i++){
            // 遍历数组，左右拓展求每一个的最大面积，好理解，时间复杂度O(n*n)
            int l=i-1,r=i+1;
            while(l>=0 && height[l]>=height[i])l--;
            while(r<height.size() && height[r]>=height[i])r++;
            res = max(res,height[i]*(r-l-1));
        }
        return res;
        */

        // 单调数组，遇到高的进入数组，遇到低的计算可以达到的面积并弹出比它高的数据
        // 计算可以达到的面积时，右侧的下标为当前位置，左侧下标为前一个记录的位置
        int ret = 0;
        // 防止数据越界，方便计算面积
        height.push_back(0);
        vector<int> index;

        for(int i = 0; i < height.size(); i++){
            // 遇到比当前最高的柱子低或者相等的柱子，计算当前可以获得最大的面积
            while(index.size() > 0 && height[index.back()] >= height[i]){
                int h = height[index.back()];
                // 把当前较大的弹出，留下前面挡板的下标就行
                index.pop_back();
                // 计算左边挡板的位置
                int sidx = index.size() > 0 ? index.back() : -1;
                ret = max(h*(i-sidx-1),ret);
            }
            // index存的下标的柱高肯定是递增的
            index.push_back(i);
        }
        return ret;
    }
};

int main(){
    vector<int> a({2,1,5,6,2,3});

    Solution* so = new Solution();
    auto n = so->largestRectangleArea(a);
    cout<<n<<endl;
    return 0;
}
