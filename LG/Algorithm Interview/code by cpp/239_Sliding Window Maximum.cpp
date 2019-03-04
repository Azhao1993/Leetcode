#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
239. 滑动窗口最大值

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。
返回滑动窗口最大值。
示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
注意：
你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。
进阶：
你能在线性时间复杂度内解决此题吗？
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 双端队列实现
        vector<int> arr;
        if(k>nums.size() || !nums.size())return arr;
        deque<int> que;
        for(int i=0;i<nums.size();i++){
            // 若当前最大值不在范围内弹出
            if(!que.empty() && que.front()==i-k)que.pop_front();
            // 若当前插入的值比之前的大，弹出之前的值，只保留最大值
            while(!que.empty() && nums[que.back()] < nums[i])que.pop_back();
            que.push_back(i);
            if(i>=k-1)arr.push_back(nums[que.front()]);
        }
        return arr;
        /*
        // 优先队列实现
        vector<int> arr;
        if(k>nums.size() || !nums.size())return arr;
        priority_queue<pair<int,int> > que;
        for(int i=0;i<k-1;i++)que.push({nums[i],i});
        for(int i=k-1;i<nums.size();i++){
            que.push({nums[i],i});
            // 若最大值不在范围内弹出
            while(que.top().second < i-k+1)que.pop();
            arr.push_back(que.top().first);
        }
        return arr;
        */
    }
};

int main(){
    int cha[8]={8,3,-1,-3,5,3,6,7};
    vector<int> a(cha,cha+8);

    Solution* so = new Solution();
    vector<int> arr = so->maxSlidingWindow(a,3);
    for(auto n:arr)
        cout<<n<<' ';
    return 0;
}
