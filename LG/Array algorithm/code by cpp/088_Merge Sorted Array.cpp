#include<iostream>
#include<vector>
using namespace std;
/*
88. 合并两个有序数组

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int pos = m+n-1;
    while (m > 0 && n > 0) {
        if (nums1[m - 1] > nums2[n - 1]) 
            nums1[pos--] = nums1[--m];
        else
            nums1[pos--] = nums2[--n];
    }
    // 后面的已经排好
    //while(m > 0)
        //nums1[pos--] = nums1[--m];
    while(n > 0)
        nums1[pos--] = nums2[--n];
}


int main(){
    int x[6] = {1,2,3,0,0,0};
    vector<int>nums1(x,x+6);

    int y[3] = {4,5,6};
    vector<int>nums2(y,y+3);
    merge(nums1,3,nums2,3);

    for(int i = 0;i<nums1.size();i++)
        cout<<nums1[i]<<endl;
    return 0;
}
