#include<iostream>
#include<vector>
using namespace std;
/*
703. 数据流中的第K大元素

设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
说明: 
你可以假设 nums 的长度≥ k-1 且k ≥ 1。
 */

class KthLargest {
private:
    int kth;
    priority_queue<int,vector<int>,great<int> > que;
public:
    KthLargest(int k, vector<int> nums) {
        kth = k;
        for(auto i:nums){
            que.push(i);
            if(que.size()>k)que.pop();
        }
    }
    
    int add(int val) {
        que.push(val);
        if(que.size()>kth)que.pop();
        return que.top();
    }
    /*
private:
    vector<int> arr;
    int Kth;
public:
    KthLargest(int k, vector<int> nums) {
        // 降序排列
        sort(nums.rbegin(), nums.rend());
        arr = nums;
        Kth = k;
        // 防止nums个数过少
        if(arr.size()>k)arr.resize(k);
    }
    
    int add(int val) {
        // 防止arr为空
        if(!arr.size()) arr.push_back(val);
        else if(arr[0]<val)arr.insert(arr.begin(),val);
        else if(arr.back()>val)arr.push_back(val);
        else{
            for(vector<int>::iterator it = arr.begin();it!=arr.end();it++)
                if(*it >= val && it+1 != arr.end() && *(it+1)<val ){
                    arr.insert(it+1,val);
                    break;
                }
            }
        if(arr.size()>Kth)arr.resize(Kth);
        return arr.back();
    }
    */
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
