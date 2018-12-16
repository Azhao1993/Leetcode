#include<iostream>
#include<vector>
using namespace std;
/*
59. 螺旋矩阵 II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > arr;
        if(!n)return arr;
        arr.resize(n);
        for(int i=0;i<n;i++)arr[i].resize(n);
        int i=0,j=0,left=-1,right=n-1,up=0,down=n-1;
        int val = 1;
        while(val<=n*n){
            // right
            j=++left;
            while(j<=right)arr[up][j++]=val++;
            if(val>n*n)return arr;
            // down
            i=++up;
            while(i<=down)arr[i++][right]=val++;
            if(val>n*n)return arr;
            // left
            j=--right;
            while(j>=left)arr[down][j--]=val++;
            if(val>n*n)return arr;
            // up
            i=--down;
            while(i>=up)arr[i--][left]=val++;
        }
        return arr;
    }
};

int main(){
    Solution* so = new Solution();
    int num = 4;
    vector<vector<int> > arr = so->generateMatrix(num);

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}