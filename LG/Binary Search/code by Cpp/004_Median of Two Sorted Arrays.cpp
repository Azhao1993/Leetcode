#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
4. 两个排序数组的中位数


给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
*/
double findKth(vector<int>& nums1,vector<int>& nums2,int st1,int st2,int end1,int end2,int k){
    // 在两个有序数组中寻找第K个数
    // 保证nums1数组比较少
    if(end1>end2)return findKth(nums2,nums1,st2,st1,end2,end1,k);
    if(end1==0)return nums2[st2+k-1];
    if(k==1)return min(nums1[st1],nums2[st2]);
    int x = min(k/2,end1),y=k-x;
    if(nums1[st1+x-1]<nums2[st2+y-1])return findKth(nums1,nums2,st1+x,st2,end1-x,end2,k-x);
    else if(nums1[st1+x-1]>nums2[st2+y-1])return findKth(nums1,nums2,st1,st2+y,end1,end2-y,k-y);
        else return nums1[st1+x-1];

}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int a = nums1.size(),b = nums2.size();
    int sum = a + b;
    if(sum%2)return findKth(nums1,nums2,0,0,a,b,sum/2+1);
    else {
        double ak = findKth(nums1,nums2,0,0,a,b,sum/2);
        double bk = findKth(nums1,nums2,0,0,a,b,sum/2+1);
        return (ak+bk)/2.0;
    }
}

int main(){
    int x[7] = {5,7,7,8,8,10,10};
    vector<int>nums1(x,x+7);
    int y[7] = {7,8,8,10,10,10,11};
    vector<int>nums2(y,y+7);
    double n = findMedianSortedArrays(nums1,nums2);
    cout<<n<<endl;
	return 0;
}
