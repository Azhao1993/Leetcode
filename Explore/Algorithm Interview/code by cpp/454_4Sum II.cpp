#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
454. 四数相加 II

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
例如: 输入: A = [ 1, 2] B = [-2,-1] C = [-1, 2] D = [ 0, 2]
输出: 2
解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/


int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int time = 0;
    unordered_map<int,int>m1,m2;
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.size();j++){
            // AB和CD两两之和出现次数
            m1[A[i]+B[j]]++;
            m2[C[i]+D[j]]++;
        }
    for(auto a:m1)time += a.second * m2[-a.first];
    return time;
}

int main(){
    int x[2] = {1, 2};
    vector<int> a(x,x+2);
    int y[2] = {-2,-1};
    vector<int> b(y,y+2);
    int z[2] = {-1, 2};
    vector<int> c(z,z+2);
    int zz[2] = {0, 2};
    vector<int> d(zz,zz+2);
    int num = fourSumCount(a,b,c,d);
    cout<<num<<endl;
	return 0;
}
