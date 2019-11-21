#include<iostream>
#include<vector>
using namespace std;
/*
54. 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

vector<int> spiralOrder(vector<vector<int> > & matrix) {
    vector<int> arr;
    if(!matrix.size() || !matrix[0].size())return arr;
    int rowLength = matrix.size(),colLength = matrix[0].size();
    int up = 0,down = rowLength-1,left = 0,right = colLength-1;
    while(true){
        for(int j = left;j<=right;j++)arr.push_back(matrix[up][j]);
        if(++up>down)break;
        for(int i = up;i<=down;i++)arr.push_back(matrix[i][right]);
        if(--right<left)break;
        for(int j = right;j>=left;j--)arr.push_back(matrix[down][j]);
        if(--down<up)break;
        for(int i = down;i>=up;i--)arr.push_back(matrix[i][left]);
        if(++left>right)break;
    }
    return arr;
}


int main(){
    vector<vector<int> > v;
    for(int i=0;i<3;++i){
        vector<int> tmp;
        v.push_back(tmp);
        for(int j=0;j<4;++j)
            v[i].push_back(i*4+j+1);
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    vector<int> nums = spiralOrder(v);
    for(int i=0;i<nums.size();++i){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
	return 0;
}
