#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
350. 两个数组的交集 II

给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // 给定两个数组，写一个方法来计算它们的交集。
    map<int,int> cnt;
    vector<int> inter;
    for(int i=0;i<nums1.size();i++)cnt[nums1[i]]++;
    for(int i=0;i<nums2.size();i++)
        if(cnt.find(nums2[i])!=cnt.end())
            if(cnt[nums2[i]]-- > 0)inter.push_back(nums2[i]);
    return inter;
}

int main(){
    int x[4] = {1,2,2,1};
    vector<int>nums1(x,x+4);
    int y[4] = {3,2,2,4};
    vector<int>nums2(y,y+4);
    vector<int> n = intersect(nums1,nums2);
    for(int i =0; i<n.size();i++)
        cout<<n[i]<<' ';
    cout<<endl;
	return 0;
}
