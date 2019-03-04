#include<iostream>
#include<vector>
using namespace std;
/*
378. 有序矩阵中第K小的元素

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。
示例:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
返回 13。
说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
*/

class Solution {
public:
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0],high = matrix[n-1][n-1];
        while(low<high){
            int mid = low + (high-low)/2;
            int pos = 0;
            // upper_bound为二分法查找，在每一行找大于mid的数目
            // 当所有的mid的数目等于k时，则为high
            for(int i=0;i<n;i++)
                pos += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(pos<k) low = mid+1;
            else high = mid;
        }
        return high;
        /*
        if(matrix.size() < 1)
            return 0;
        // 先存进数组中，进行sort后查找
        vector<int> vec;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                vec.push_back(matrix[i][j]);
        sort(vec.begin(), vec.end());
        if(k == 0)
            return vec[k];
        return vec[k-1];
        */
    }
};

int main(){
    vector<int> a({1,5,9});
    vector<int> b({10,11,13});
    vector<int> c({12,13,15});
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    int n = so->kthSmallest(grid,8);
    cout<<n<<endl;
    return 0;
}
