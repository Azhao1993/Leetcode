#include<iostream>
#include<vector>
using namespace std;
/*
118. 杨辉三角

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:     输入: 5    输出:[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        if(numRows < 1) return arr;
        helper(arr, numRows);
        /*
        arr.resize(numRows);
        for(int i=0;i<numRows;i++)
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)arr[i].push_back(1);
                else arr[i].push_back(arr[i-1][j-1]+arr[i-1][j]);
            }
        */
        return arr;
    }
    void helper(vector<vector<int>>& res, int numRows){
        if(numRows == 1){
            res.push_back(vector<int>{1});
            return ;
        }
        helper(res, numRows-1);
        vector<int> pre = res.back();
        vector<int> tem;
        for(int i = 0; i <= pre.size(); i++){
            if(i == 0 || i == pre.size()) tem.push_back(1);
            else tem.push_back(pre[i-1] + pre[i]);
        }
        res.push_back(tem);
    }
};

int main(){
    vector<vector<int>> arr = Solution().generate(5);
    for(auto num:arr){
        for(auto it:num)
            cout<<it<<' ';
        cout<<endl;
    }
	return 0;
}
