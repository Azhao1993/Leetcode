#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
/*
1088. 易混淆数 II

本题我们会将数字旋转 180° 来生成一个新的数字。 比如 0、1、6、8、9 旋转 180° 以后，我们得到的新数字分别为 0、1、9、8、6。
2、3、4、5、7 旋转 180° 后，是 无法 得到任何数字的。易混淆数（Confusing Number）指的是一个数字在整体旋转 180° 以后，
能够得到一个和原来 不同 的数，且新数字的每一位都应该是有效的。（请注意，旋转后得到的新数字可能大于原数字）
给出正整数 N，请你返回 1 到 N 之间易混淆数字的数量。

示例 1：   输入：20   输出：6
解释： 易混淆数为 [6,9,10,16,18,19]。
6 转换为 9     9 转换为 6     10 转换为 01 也就是 1     16 转换为 91       18 转换为 81       19 转换为 61
示例 2：   输入：100  输出：19
解释： 易混淆数为 [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100]。

提示：  1 <= N <= 10^9
*/

class Solution {
private:
    /*
    // 判断单个数字是否为混淆数字
    bool confusingNumber(int N) {
        if(N == 0) return false;
        long tem = 0;
        int save = N;
        while(N){
            int cur = N%10;
            if(cur==2||cur==3||cur==4||cur==5||cur==7) return false;
            if(cur==6) tem = tem*10+9;
            else if(cur==9) tem = tem*10+6;
            else tem = tem*10 + cur;
            N /= 10;
        }
        return tem != save;
    }*/
    void dfs(int& res, long long base, long long cur, long long rev, int& N, vector<vector<int>>& trans){
        if(cur > N || base > 1e10 || rev > 1e10) return ;
        if(cur != rev) res++;
        for(int i=0; i<trans.size(); i++){
            // 防止无限循环递归
            if(cur == 0 && trans[i][0] == 0) continue ;
            dfs(res, base * 10, cur * 10 + trans[i][0], trans[i][1] * base + rev, N, trans);
        }
    }
public:
    int confusingNumberII(int N) {
        int res = 0;
        // 骚操作
        // if(N == 1e9) return 1950627;
        // for(int i = 6; i<=N; i++) if(confusingNumber(i)) res++;

        vector<vector<int>> trans{{0,0},{1,1},{6,9},{8,8},{9,6}};
        dfs(res, 1, 0, 0, N, trans);
        return res;
    }
};

int main(){
    int it = Solution().confusingNumberII(1e9);
    cout<<it<<endl;
    return 0;
}