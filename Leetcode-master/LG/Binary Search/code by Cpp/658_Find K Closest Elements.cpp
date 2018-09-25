#include<iostream>
#include<vector>
using namespace std;
/*
658. 找到 K 个最接近的元素

给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

示例 1:

输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]

示例 2:

输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
*/
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int low = 0,high = arr.size()-1,mid;
    vector<int> nums;
    while(low<=high){
        mid = low + (high-low)/2;
        if(arr[mid]>x)high = mid-1;
        else if(arr[mid]<x)low = mid+1;
        else {
            nums.push_back(arr[mid]);
            break;
             }
    }
    if(low>high)swap(low,high);
    else low = mid-1,high = mid+1;
    while(nums.size()<k){
        if(low<0)
            nums.push_back(arr[high++]);
        else if(high>arr.size()-1)
            nums.insert(nums.begin(),arr[low--]);
        else if( (x - arr[low]) <= (arr[high] - x))
            nums.insert(nums.begin(),arr[low--]);
        else nums.push_back(arr[high++]);
    }
    return nums;
}

int main(){
    int x[7] = {5,7,7,8,8,10,10};
    vector<int>nums(x,x+7);
    vector<int> n = findClosestElements(nums,4,7);
    for(int i =0; i<n.size();i++)
        cout<<n[i]<<' ';
    cout<<endl;
	return 0;
}
