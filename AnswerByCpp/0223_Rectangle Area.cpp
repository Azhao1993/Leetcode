#include<bits\stdc++.h>
using namespace std;
/*
223. 矩形面积

在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
每个矩形由其左下顶点和右上顶点坐标表示，如图所示。 Rectangle Area

示例: 输入: -3, 0, 3, 4, 0, -1, 9, 2        输出: 45
说明: 假设矩形面积不会超出 int 的范围。
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long a = A, b = B, c = C, d = D, res = 0;
        res += (c - a) * (d - b);
        a = E, b = F, c = G, d = H;
        res += (c - a) * (d - b);
        a = max(A, E), b = max(B, F), c = min(C, G), d = min(D, H);
        if(c > a && d > b) res -= (c - a) * (d - b);
        return res;
    }
};

int main(){
    int res = Solution().computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    cout << res << endl;
    return 0;
}