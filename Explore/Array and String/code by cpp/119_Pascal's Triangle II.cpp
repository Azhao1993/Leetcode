#include<iostream>
#include<vector>
using namespace std;
/*
119. 杨辉三角 II

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
*/
vector<int> getRow(int rowIndex) {
    // 为了减少空间复杂度，采用两个数组来回替换
    vector<int> arr(rowIndex+1,1);
    vector<int> temp(rowIndex+1,1);
    if(rowIndex < 2)return arr;
    for(int i = 2;i<=rowIndex;i++){
        temp.resize(i+1,1);
        for(int j = 1;j<i;j++)
            temp[j] = arr[j-1] + arr[j];
        i++;
        if(i>rowIndex)return temp;
        arr.resize(i+1,1);
        for(int j = 1;j<i;j++)
            arr[j] = temp[j-1] + temp[j];
    }
    // for (int i=0; i<=rowIndex; i++) {
    //     arr.push_back(1);
    //     for (int j=arr.size()-2; j>0;j--) {
    //         arr[j] = arr[j] + arr[j-1];
    //     }
    // }
    return arr;
}
int main(){
    vector<int>nums = getRow(5);
    for(int i = 0;i<nums.size();i++)cout<<nums[i]<<' ';
    cout<<endl;
	return 0;
}
