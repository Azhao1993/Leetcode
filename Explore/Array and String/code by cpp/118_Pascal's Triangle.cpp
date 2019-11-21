#include<iostream>
#include<vector>
using namespace std;
/*
118. 杨辉三角

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    if(numRows == 0)return res;
    res.push_back(vector<int>(1,1));
    for(int i = 1 ; i<numRows; i++){
        vector<int> row;
        row.push_back(1);
        for(int j=0;j<i-1;j++){
            row.push_back(res[i-1][j]+res[i-1][j+1]);
        }
        row.push_back(1);
        res.push_back(row);
    }
    return res;
    // vector<vector<int> > arr;
    // arr.resize(numRows);
    // for(int i=0;i<numRows;i++)
    //     for(int j=0;j<=i;j++){
    //         if(j==0 || j==i)arr[i].push_back(1);
    //         else arr[i].push_back(arr[i-1][j-1]+arr[i-1][j]);
    //     }
    // return arr;
}

int main(){
    vector<vector<int> >nums = generate(5);
    for(int i = 0;i<nums.size();i++){
        for(int j = 0;j<nums[i].size();j++)
            cout<<nums[i][j]<<' ';
        cout<<endl;
    }
	return 0;
}
