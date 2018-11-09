#include<iostream>
#include<vector>
using namespace std;
/*
498. 对角线遍历

给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

说明:

给定矩阵中的元素总数不会超过 100000 。
*/

vector<int> findDiagonalOrder(vector<vector<int> > & matrix) {
    vector<int> arr;
    if(!matrix.size())return arr;
    int arrLength = matrix.size()*matrix[0].size();
    int row = 0,column = 0;
    for(int i = 0; i < arrLength; i++){
        arr.push_back(matrix[row][column]);
        if((row + column) % 2 ){
            // 左下
            if(row == matrix.size()-1)// 右
                column++;
            else if(column == 0)// 下
                row++;
            else row++,column--;// 左下
        }else{
            // 右上
            if(column == matrix[0].size()-1)// 下
                row++;
            else if(row == 0)// 右
                column++;
            else row--,column++;// 右上
        }
    }
    return arr;
}


int main(){
    vector<vector<int> > v;
    for(int i=0;i<3;++i){  
        vector<int> tmp;
        v.push_back(tmp);
        for(int j=0;j<3;++j)
            v[i].push_back(i*3+j+1); 
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    vector<int> nums = findDiagonalOrder(v);
    for(int i=0;i<nums.size();++i){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
	return 0;
}
