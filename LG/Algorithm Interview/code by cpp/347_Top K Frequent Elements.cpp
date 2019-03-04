#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
347. 前K个高频元素

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:   输入: nums = [1,1,1,2,2,3], k = 2     输出: [1,2]
示例 2:   输入: nums = [1], k = 1               输出: [1]
说明： 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    /*
    vector<int> res;
    unordered_map<int,int> m;
    priority_queue<pair<int,int>> q;
    for(int n:nums) m[n]++;
    for(auto j:m)q.push({j.second,j.first});
    while(k)
    {
        res.push_back(q.top().second);
        q.pop();
        k--;
    }
    return res;
    */

    vector<int> arr;
    if(k == 0)return arr;

    // 定义map,并存入数据
    unordered_map<int,int>vec;
    for(int i = 0; i < nums.size(); ++i)vec[nums[i]]++;

    // 定义数组容器，并实现排序
    vector<pair<int,int>> vc;
    for(auto &it : vec)
        vc.push_back({it.first,it.second});
    sort(vc.begin(),vc.end(),[](pair<int,int> a, pair<int,int> b){return a.second>b.second;});

    // 根据排序输出
    for(auto &it : vc){
        arr.push_back(it.first);
        k--;
        if(!k)return arr;
    }
    return arr;
}


int main(){
    int x[6] = {1,1,1,2,2,3};
    vector<int>num(x,x+5);
    vector<int> nums = topKFrequent(num,2);

    for(int i = 0;i<nums.size();i++)
        cout<<nums[i]<<endl;
    return 0;
}
